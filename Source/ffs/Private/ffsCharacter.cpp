#include "ffsCharacter.h"
#include "EngineUtils.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GSCAbilitySystemComponent.h"
#include "Abilities/Attributes/GSCAttributeSet.h"
#include "NavigationSystem.h"
#include "NavigationSystem/Public/NavigationSystem.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "ffsCharacterMovementComponent.h"
#include "Animations/GSCNativeAnimInstanceInterface.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "ffsAnimInstance.h"
#include "ffsWeapon.h"

AffsCharacter::AffsCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UffsCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetCapsuleComponent());
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;

	Mesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh3P"));
	Mesh3P->SetOwnerNoSee(true);
	Mesh3P->SetupAttachment(GetCapsuleComponent());
	Mesh3P->bCastDynamicShadow = true;
	Mesh3P->CastShadow = true;

	DeathCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("DeathCamera"));
	DeathCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	DeathCamera->SetRelativeLocation(FVector(0.f, 0.f, 100.f));	 // Position the camera above the character
	DeathCamera->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f)); // Rotate the camera to look down
	DeathCamera->SetActive(false);								 // Disable the camera by default

	// Initialize the respawn time and default spawn point
	RespawnTime = 3.f;
	DefaultSpawnPoint = FVector(0.f, 0.f, 0.f);
	SpawnPointSearchRadius = 1000.f;

	RecoilAnimation = CreateDefaultSubobject<URecoilAnimationComponent>(TEXT("RecoilAnimComp"));
	AnimMasterComponent = CreateDefaultSubobject<UAGRAnimMasterComponent>(TEXT("AGRAnimMaster"));

	WeaponManager = CreateDefaultSubobject<UffsWeaponManager>(TEXT("WeaponManager"));
	WeaponManager->SetIsReplicated(true);
}

#pragma region Initialization

void AffsCharacter::BeginPlay()
{
	Super::BeginPlay();

	UAbilitySystemComponent *ASC = Cast<UAbilitySystemComponent>(AbilitySystemComponent);

	if (Mesh1P)
	{
		if (IGSCNativeAnimInstanceInterface *AnimInstanceInterface = Cast<IGSCNativeAnimInstanceInterface>(Mesh1P->GetAnimInstance()))
		{
			if (ASC)
			{
				AnimInstanceInterface->InitializeWithAbilitySystem(ASC);
			}
		}
	}

	if (Mesh3P)
	{
		if (IGSCNativeAnimInstanceInterface *AnimInstanceInterface = Cast<IGSCNativeAnimInstanceInterface>(Mesh3P->GetAnimInstance()))
		{
			if (ASC)
			{
				AnimInstanceInterface->InitializeWithAbilitySystem(ASC);
			}
		}
	}

	if (IsLocallyControlled())
	{
		FOnTimelineEvent Event;
		Event.BindDynamic(this, &AffsCharacter::PlayCameraShake);
		RecoilAnimation->AddEvent(0.02f, Event);

		// TODO: User configurable FOV
		UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->SetFOV(90.f);
	}

	if (ASC)
	{
		HealthChangedDelegateHandle = ASC->GetGameplayAttributeValueChangeDelegate(UGSCAttributeSet::GetHealthAttribute()).AddUObject(this, &AffsCharacter::OnHealthChanged);
	}
}

void AffsCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UAbilitySystemComponent *ASC = Cast<UAbilitySystemComponent>(AbilitySystemComponent);

	if (ASC)
	{
		ASC->GetGameplayAttributeValueChangeDelegate(UGSCAttributeSet::GetHealthAttribute()).Remove(HealthChangedDelegateHandle);
	}
}

#pragma endregion Initialization

#pragma region State

void AffsCharacter::OnHealthChanged(const FOnAttributeChangeData &Data)
{
	float NewHealthValue = Data.NewValue;

	if (NewHealthValue <= 0.f)
	{
		Die();
	}
}

void AffsCharacter::Die()
{
	APlayerController *PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		PC->DisableInput(PC);
	}

	Ragdoll();
	SwitchToDeathCamera();
	GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &AffsCharacter::Respawn, RespawnTime, false);
}

void AffsCharacter::Respawn()
{
	// Find a suitable spawn point
	FVector SpawnPoint = DefaultSpawnPoint;
	for (TActorIterator<AffsCharacter> It(GetWorld()); It; ++It)
	{
		if (*It != this)
		{
			UNavigationSystemV1 *NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
			if (NavSystem)
			{
				FNavLocation RandomReachablePoint;
				if (NavSystem->GetRandomReachablePointInRadius(It->GetActorLocation(), SpawnPointSearchRadius, RandomReachablePoint))
				{
					SpawnPoint = RandomReachablePoint.Location;
				}
			}
			break;
		}
	}

	// Move the character to the spawn point
	if (HasAuthority())
	{
		SetActorLocation(SpawnPoint);
	}

	// Enable player controls
	APlayerController *PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		PC->EnableInput(PC);
	}

	ResetMesh3P();
	ResetAttributes();

	SwitchToFirstPersonCamera();
}

void AffsCharacter::ResetAttributes()
{
	// Get the attribute set and set health to GetMaxHealth
	UAbilitySystemComponent *ASC = Cast<UAbilitySystemComponent>(AbilitySystemComponent);

	if (ASC)
	{
		ASC->SetNumericAttributeBase(UGSCAttributeSet::GetHealthAttribute(), ASC->GetNumericAttributeBase(UGSCAttributeSet::GetMaxHealthAttribute()));
	}
}

void AffsCharacter::SwitchToDeathCamera()
{
	APlayerController *PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		PC->SetViewTargetWithBlend(this, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
		DeathCamera->SetActive(true);
		FirstPersonCameraComponent->SetActive(false);
		Mesh3P->SetOwnerNoSee(false);
		Mesh1P->SetVisibility(false);
		WeaponManager->CurrentWeapon->GunMesh->SetVisibility(false);
	}
}

void AffsCharacter::SwitchToFirstPersonCamera()
{
	APlayerController *PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		PC->SetViewTargetWithBlend(this, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
		FirstPersonCameraComponent->SetActive(true);
		DeathCamera->SetActive(false);
		Mesh3P->SetOwnerNoSee(true);
		Mesh1P->SetVisibility(true);

		WeaponManager->CurrentWeapon->GunMesh->SetVisibility(true);
	}
}

void AffsCharacter::Ragdoll()
{
	if (HasAuthority())
	{
		Multicast_Ragdoll();
	}
	else
	{
		Server_Ragdoll();
	}
}

void AffsCharacter::Server_Ragdoll_Implementation()
{
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	Multicast_Ragdoll();
}

void AffsCharacter::Multicast_Ragdoll_Implementation()
{
	if (Mesh3P)
	{
		Mesh3P->SetCollisionProfileName(TEXT("Ragdoll"));

		if (Mesh3P->GetPhysicsAsset())
		{
			Mesh3P->SetAllBodiesSimulatePhysics(true);
		}
	}

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
}

void AffsCharacter::ResetMesh3P()
{
    if (HasAuthority())
    {
        Multicast_ResetMesh3P();
    }
    else
    {
        Server_ResetMesh3P();
    }
}

void AffsCharacter::Server_ResetMesh3P_Implementation()
{
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	Multicast_ResetMesh3P();
}

void AffsCharacter::Multicast_ResetMesh3P_Implementation()
{
	if (Mesh3P)
	{
		Mesh3P->SetCollisionProfileName(TEXT("NoCollision"));
		Mesh3P->SetAllBodiesSimulatePhysics(false);
		Mesh3P->SetAllBodiesPhysicsBlendWeight(0.0f);
		Mesh3P->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		Mesh3P->SetRelativeLocation(FVector(0.f, 0.f, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
		Mesh3P->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	}

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
}

#pragma endregion State

#pragma region Weapons

FHitResult AffsCharacter::FireWeapon(bool InitialShot, bool Debug)
{
	FHitResult FireLineTraceResult = WeaponManager->FireLineTrace(InitialShot, Debug);

	PlayFireAnimation();
	PlayWeaponFireFX(WeaponManager->CurrentWeapon->MuzzleFlashFX, FName("Muzzle"));
	PlayWeaponFireFX(WeaponManager->CurrentWeapon->CaseEjectFX, FName("ShellEject"));

	return FireLineTraceResult;
}

void AffsCharacter::PlayCameraShake()
{
	if (IsLocallyControlled() && WeaponManager->CurrentWeapon && WeaponManager->CurrentWeapon->CameraRecoilShake)
	{
		UGameplayStatics::GetPlayerCameraManager(this, 0)
			->StartCameraShake(WeaponManager->CurrentWeapon->CameraRecoilShake);
	}
}

void AffsCharacter::PlayFireAnimation()
{
	RecoilAnimation->Play();
	WeaponManager->PlayFireAnimation(false);

	if (HasAuthority())
	{
		Server_PlayFireAnimation();
	}
}

void AffsCharacter::Server_PlayFireAnimation_Implementation()
{
	Multicast_PlayFireAnimation();
}

void AffsCharacter::Multicast_PlayFireAnimation_Implementation()
{
	WeaponManager->PlayFireAnimation(true);
}

void AffsCharacter::PlayWeaponFireFX(UNiagaraSystem *FX, FName SocketName)
{
	WeaponManager->PlayWeaponFireFX(FX, SocketName, false);

	if (HasAuthority())
	{
		Server_PlayWeaponFireFX(FX, SocketName);
	}
}

void AffsCharacter::Server_PlayWeaponFireFX_Implementation(UNiagaraSystem *FX, FName SocketName)
{
	Multicast_PlayWeaponFireFX(FX, SocketName);
}

void AffsCharacter::Multicast_PlayWeaponFireFX_Implementation(UNiagaraSystem *FX, FName SocketName)
{
	if (IsLocallyControlled())
	{
		return;
	}

	WeaponManager->PlayWeaponFireFX(FX, SocketName, true);
}

#pragma endregion Weapons

#pragma region Equipping

void AffsCharacter::EquipWeapon()
{
	WeaponManager->EquipWeapon(Mesh1P, Mesh3P);

	if (IsLocallyControlled() || HasAuthority())
	{
		OnWeaponEquipped(
			WeaponManager->CurrentWeapon->RecoilAnimData,
			WeaponManager->CurrentWeapon->FireRate,
			WeaponManager->CurrentWeapon->Burst);
		// TODO: Set burst and firemode
	}
}

void AffsCharacter::ChangeWeapon()
{
	if (!WeaponManager->CurrentWeapon)
	{
		return;
	}

	const int LastIndex = WeaponManager->CurrentGunIndex;
	int NewIndex = WeaponManager->CurrentGunIndex + 1;

	if (NewIndex > WeaponManager->InitializedWeapons.Num() - 1)
	{
		NewIndex = 0;
	}

	if (!WeaponManager->InitializedWeapons[NewIndex])
	{
		NewIndex = LastIndex;
		return;
	}

	WeaponManager->CurrentGunIndex = NewIndex;
	UnequipWeapon();
}

void AffsCharacter::UnequipWeapon()
{
	if (WeaponManager->UnequipMontage)
	{
		UAnimInstance *AnimInstance1P = Mesh1P->GetAnimInstance();
		AnimInstance1P->Montage_Play(WeaponManager->UnequipMontage, 1.0f);
	}

	OnWeaponUnequipped();

	if (IsLocallyControlled() && !HasAuthority())
	{
		Server_UnequipWeapon(WeaponManager->CurrentGunIndex);
	}
	else if (HasAuthority())
	{
		Multicast_UnequipWeapon();
	}
}

void AffsCharacter::Server_UnequipWeapon_Implementation(int WeaponIndex)
{
	if (HasAuthority())
	{
		WeaponManager->CurrentGunIndex = WeaponIndex;
		const auto Gun = WeaponManager->InitializedWeapons[WeaponIndex];
		OnWeaponEquipped(Gun->RecoilAnimData, Gun->FireRate, Gun->Burst);

		Multicast_UnequipWeapon();
	}
}

void AffsCharacter::Multicast_UnequipWeapon_Implementation()
{
	if (WeaponManager->UnequipMontage && !IsLocallyControlled())
	{
		// This is causing me to have to add another event in my third person anim blueprint to replicate the
		// unequip animation. The reason for this is because the unequip animation montage fires a notify
		// to call the equip weapon function. If I set this to the first person mesh it works fine but I think
		// because I am calling another montage before this its causing issues. If we call it on the third person
		// mesh it works fine but we have to add another event in the anim blueprint to replicate the unequip animation.
		UAnimInstance *AnimInstance3P = Mesh3P->GetAnimInstance();
		AnimInstance3P->Montage_Play(WeaponManager->UnequipMontage, 1.0f);
	}
}

#pragma endregion Equipping

#pragma region Helper Functions
// Helper to create a collision query params object that ignores the character and all its children
FCollisionQueryParams AffsCharacter::GetIgnoreCharacterParams() const
{
	FCollisionQueryParams Params;

	TArray<AActor *> CharacterChildren;
	GetAllChildActors(CharacterChildren);
	Params.AddIgnoredActors(CharacterChildren);
	Params.AddIgnoredActor(this);

	return Params;
}
#pragma endregion Helper Functions