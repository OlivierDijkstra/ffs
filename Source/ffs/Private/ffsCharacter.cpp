#include "ffsCharacter.h"
#include "EngineUtils.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GSCAbilitySystemComponent.h"
#include "Abilities/Attributes/GSCAttributeSet.h"
#include "NavigationSystem.h"
#include "NavigationSystem/Public/NavigationSystem.h"
#include "Math/UnrealMathUtility.h"
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
	
	DeathCameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("DeathCameraBoom"));
	DeathCameraBoom->SetupAttachment(GetCapsuleComponent());
	DeathCameraBoom->TargetArmLength = 300.0f; // Set the distance of the death camera
	DeathCameraBoom->bUsePawnControlRotation = false; // Do not rotate the arm based on controller
	DeathCameraBoom->SetActive(false); // Disable the boom by default
	DeathCameraBoom->SetRelativeRotation(FRotator(-70.f, 0.f, 0.f));
	
	DeathCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("DeathCamera"));
	DeathCamera->SetupAttachment(DeathCameraBoom);
	DeathCamera->SetRelativeLocation(FVector(0.f, 0.f, 0.f)); // Position the camera at the end of the boom
	DeathCamera->SetRelativeRotation(FRotator(0.f, 0.f, 0.f)); // Rotate the camera to look down
	DeathCamera->SetActive(false); // Disable the camera by default

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

void AffsCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsDead)
    {
        // Get the location of the Mesh3P
        FVector MeshLocation = Mesh3P->GetComponentLocation();

        // Calculate the direction from the DeathCamera to the Mesh3P
        FVector Direction = MeshLocation - DeathCamera->GetComponentLocation();

        // Calculate the target rotation that looks at the Mesh3P
        FRotator TargetRotation = FRotationMatrix::MakeFromX(Direction).Rotator();

        // Get the current rotation of the DeathCamera
        FRotator CurrentRotation = DeathCamera->GetComponentRotation();

        // Interpolate the rotation from the current to the target
        FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, 2.0f);

        // Set the rotation of the DeathCamera
        DeathCamera->SetWorldRotation(NewRotation);
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
	bIsDead = true;

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
	if (HasAuthority())
	{
		Multicast_FixPlayer();
	}
	else
	{
		Server_TeleportPlayer();	
	}
}

void AffsCharacter::Server_TeleportPlayer_Implementation()
{
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);

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

	SetActorLocation(SpawnPoint);
	Multicast_FixPlayer();
}

void AffsCharacter::Multicast_FixPlayer_Implementation()
{
	// Enable player controls
	APlayerController *PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		PC->EnableInput(PC);
	}

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);

	if (Mesh3P)
	{
		Mesh3P->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Mesh3P->SetCollisionObjectType(ECC_WorldStatic);
		Mesh3P->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
		Mesh3P->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Block);
		
		Mesh3P->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Block);

		Mesh3P->SetAllBodiesSimulatePhysics(false);
		Mesh3P->SetAllBodiesPhysicsBlendWeight(0.0f);

		Mesh3P->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		Mesh3P->SetRelativeLocation(FVector(0.f, 0.f, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
		Mesh3P->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	}

	ResetAttributes();
	SwitchToFirstPersonCamera();

	bIsDead = false;
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
    if (PC && WeaponManager)
    {
        PC->SetViewTargetWithBlend(this, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
        FirstPersonCameraComponent->SetActive(false);
		DeathCameraBoom->SetActive(true);
        DeathCamera->SetActive(true);
        Mesh3P->SetOwnerNoSee(false);
        Mesh1P->SetVisibility(false);

        WeaponManager->CurrentWeapon->GunMesh->SetVisibility(false);

		FRotator DeathCameraRotation = DeathCamera->GetComponentRotation();
		DeathCameraRotation.Roll = FMath::RandRange(0.f, 360.f);
		DeathCamera->SetWorldRotation(DeathCameraRotation);
    }
}

void AffsCharacter::SwitchToFirstPersonCamera()
{
	APlayerController *PC = Cast<APlayerController>(GetController());
	if (PC && WeaponManager)
	{
		PC->SetViewTargetWithBlend(this, 0.f, EViewTargetBlendFunction::VTBlend_Cubic); // Set blend time to 0
		FirstPersonCameraComponent->SetActive(true);
		DeathCameraBoom->SetActive(false);
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
		Mesh3P->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		Mesh3P->SetCollisionObjectType(ECC_PhysicsBody);
		Mesh3P->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
		Mesh3P->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Ignore);

		Mesh3P->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Ignore);

		if (Mesh3P->GetPhysicsAsset())
		{
			Mesh3P->SetAllBodiesSimulatePhysics(true);
		}
	}

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
}

#pragma endregion State

#pragma region Weapons

FHitResult AffsCharacter::FireWeapon(bool InitialShot, bool Debug)
{
	if (!WeaponManager->CurrentWeapon)
	{
		return FHitResult();
	}

	FHitResult FireLineTraceResult = WeaponManager->FireLineTrace(InitialShot, Debug);

	PlayFireAnimation();
	PlayWeaponFireFX(WeaponManager->CurrentWeapon->MuzzleFlashFX, FName("Muzzle"));
	PlayWeaponFireFX(WeaponManager->CurrentWeapon->CaseEjectFX, FName("ShellEject"));

	return FireLineTraceResult;
}

void AffsCharacter::PlayCameraShake()
{
	if (IsLocallyControlled() && WeaponManager && WeaponManager->CurrentWeapon && WeaponManager->CurrentWeapon->CameraRecoilShake)
	{
		UGameplayStatics::GetPlayerCameraManager(this, 0)
			->StartCameraShake(WeaponManager->CurrentWeapon->CameraRecoilShake);
	}
}

void AffsCharacter::PlayFireAnimation()
{
	RecoilAnimation->Play();

	if (WeaponManager) {
		WeaponManager->PlayFireAnimation(false);
	}

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
	if (!WeaponManager) return;
		
	WeaponManager->PlayFireAnimation(true);
}

void AffsCharacter::PlayWeaponFireFX(UNiagaraSystem *FX, FName SocketName)
{
	if (WeaponManager) {
		WeaponManager->PlayWeaponFireFX(FX, SocketName, false);
	}

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

	if (WeaponManager) {
		WeaponManager->PlayWeaponFireFX(FX, SocketName, true);
	}
}

#pragma endregion Weapons

#pragma region Equipping

void AffsCharacter::EquipWeapon()
{
	if (IsLocallyControlled() && !HasAuthority() && WeaponManager)
	{
		WeaponManager->IncrementCurrentWeaponIndex();
		WeaponManager->EquipWeaponOnPlayer(this, WeaponManager->Weapons[WeaponManager->CurrentWeaponIndex]);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("LOCAL CLIENT: Weapon Index: %d, Current Weapon: %s"), WeaponManager->CurrentWeaponIndex, *WeaponManager->CurrentWeapon->GetName()));
		Server_EquipWeapon(WeaponManager->CurrentWeaponIndex);
	}
}

void AffsCharacter::Server_EquipWeapon_Implementation(int32 WeaponIndex)
{
	if (HasAuthority() && WeaponManager)
	{
		WeaponManager->CurrentWeaponIndex = WeaponIndex;
		WeaponManager->EquipWeaponOnPlayer(this, WeaponManager->Weapons[WeaponManager->CurrentWeaponIndex]);
		// Print the weapon index and the current weapon name, SERVER: prefix
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("SERVER: Weapon Index: %d, Current Weapon: %s"), WeaponManager->CurrentWeaponIndex, *WeaponManager->CurrentWeapon->GetName()));

		Multicast_EquipWeapon(WeaponManager->CurrentWeapon);
	}
}

// Update the weapon for the other players, DO NOT do anything montage related
void AffsCharacter::Multicast_EquipWeapon_Implementation(AffsWeapon *Weapon)
{
    if (WeaponManager && Weapon)
    {
		// Print the weapon param
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("MULTICAST: Weapon: %s"), *Weapon->GetName()));
		WeaponManager->EquipWeaponOnPlayer(this, Weapon);
	}
}
// @
void AffsCharacter::UnequipWeapon()
{
	OnWeaponUnequipped();

	if (IsLocallyControlled() && !HasAuthority() && WeaponManager)
	{
		Server_UnequipWeapon();
	}
	else if (HasAuthority())
	{
		Multicast_UnequipWeapon();
	}
}
// @
void AffsCharacter::Server_UnequipWeapon_Implementation()
{
	if (HasAuthority() && WeaponManager)
	{
		Multicast_UnequipWeapon();
	}
}
// @
void AffsCharacter::Multicast_UnequipWeapon_Implementation()
{
	if (WeaponManager && WeaponManager->UnequipMontage && !IsLocallyControlled())
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

void AffsCharacter::PlayThirdPersonUnequipMontage()
{
	if (HasAuthority() && WeaponManager && WeaponManager->UnequipMontage)
	{
		UAnimInstance *AnimInstance3P = Mesh3P->GetAnimInstance();
		AnimInstance3P->Montage_Play(WeaponManager->UnequipMontage, 1.0f);
	}

	if (HasAuthority())
	{
		Server_PlayThirdPersonUnequipMontage();
	}
}

void AffsCharacter::Server_PlayThirdPersonUnequipMontage_Implementation()
{
	Multicast_PlayThirdPersonUnequipMontage();
}

void AffsCharacter::Multicast_PlayThirdPersonUnequipMontage_Implementation()
{
	if (WeaponManager && WeaponManager->UnequipMontage && !IsLocallyControlled())
	{
		UAnimInstance *AnimInstance3P = Mesh3P->GetAnimInstance();
		AnimInstance3P->Montage_Play(WeaponManager->UnequipMontage, 1.0f);
	}
}

void AffsCharacter::ReverseThirdPersonUnequipMontage()
{
	// Play a reversed version of the unequip montage from the position of the currently playing montage
	if (HasAuthority() && WeaponManager && WeaponManager->UnequipMontage)
	{
		UAnimInstance *AnimInstance3P = Mesh3P->GetAnimInstance();
		AnimInstance3P->Montage_Play(WeaponManager->UnequipMontage, -1.0f, EMontagePlayReturnType::MontageLength, 0.0f, true);
	}

	if (HasAuthority())
	{
		Server_ReverseThirdPersonUnequipMontage();
	}
}

void AffsCharacter::Server_ReverseThirdPersonUnequipMontage_Implementation()
{
	Multicast_ReverseThirdPersonUnequipMontage();
}

void AffsCharacter::Multicast_ReverseThirdPersonUnequipMontage_Implementation()
{
	if (WeaponManager && WeaponManager->UnequipMontage && !IsLocallyControlled())
	{
		UAnimInstance *AnimInstance3P = Mesh3P->GetAnimInstance();
		AnimInstance3P->Montage_Play(WeaponManager->UnequipMontage, -1.0f, EMontagePlayReturnType::MontageLength, 0.0f, true);
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