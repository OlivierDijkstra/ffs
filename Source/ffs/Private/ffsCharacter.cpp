#include "ffsCharacter.h"
#include "ffsAnimInstance.h"
#include "AbilitySystemComponent.h"
#include "Abilities/GSCAbilitySystemComponent.h"
#include "Abilities/Attributes/GSCAttributeSet.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "ffsCharacterMovementComponent.h"
#include "Animations/GSCNativeAnimInstanceInterface.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
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

void AffsCharacter::OnHealthChanged(const FOnAttributeChangeData& Data)
{
    float NewHealthValue = Data.NewValue;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health changed to %f"), NewHealthValue));

    if (NewHealthValue <= 0.f)
    {
        Die();
    }
}

void AffsCharacter::Die()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You died!"));
}

void AffsCharacter::Ragdoll()
{
    if (HasAuthority())
    {
        MulticastRagdoll();
    }
    else
    {
        ServerRagdoll();
    }
}

void AffsCharacter::ServerRagdoll_Implementation()
{
    MulticastRagdoll();
}

void AffsCharacter::MulticastRagdoll_Implementation()
{
    if(Mesh3P)
    {
        Mesh3P->SetCollisionProfileName(TEXT("Ragdoll"));

        if(Mesh3P->GetPhysicsAsset())
        {
            Mesh3P->SetAllBodiesSimulatePhysics(true);
        }
    }
}

#pragma endregion State

#pragma region Weapons

void AffsCharacter::PlayCameraShake()
{
	if (IsLocallyControlled() && WeaponManager->CurrentWeapon && WeaponManager->CurrentWeapon->CameraRecoilShake)
	{
		UGameplayStatics::GetPlayerCameraManager(this, 0)
			->StartCameraShake(WeaponManager->CurrentWeapon->CameraRecoilShake);
	}
}

FHitResult AffsCharacter::FireWeapon(bool InitialShot, bool Debug)
{
	FHitResult FireLineTraceResult;

	if (WeaponManager->CurrentWeapon)
	{
		if (!IsLocallyControlled() && HasAuthority())
		{
			FireLineTraceResult = WeaponManager->CurrentWeapon->FireLineTrace(InitialShot, Debug);
		}

		PlayFireAnimation();
		PlayWeaponFireFX(WeaponManager->CurrentWeapon->MuzzleFlashFX, FName("Muzzle"), true);
		PlayWeaponFireFX(WeaponManager->CurrentWeapon->CaseEjectFX, FName("ShellEject"), true);
	}

	return FireLineTraceResult;
}

void AffsCharacter::PlayFireAnimation()
{
	RecoilAnimation->Play();

	WeaponManager->CurrentWeapon->GunMesh->PlayAnimation(WeaponManager->CurrentWeapon->FireMontage, false);

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
	UAnimMontage *FireAnimation = WeaponManager->CurrentWeapon->FireMontage;

	if (FireAnimation)
	{
		WeaponManager->CurrentWeapon->GunMesh3P->PlayAnimation(FireAnimation, false);
	}
}

void AffsCharacter::PlayWeaponFireFX(UNiagaraSystem *FX, FName SocketName, bool bMulticast)
{
	if (WeaponManager->CurrentWeapon)
	{
		FVector SocketLocation = WeaponManager->CurrentWeapon->GunMesh->GetSocketLocation(SocketName);
		FRotator SocketRotation = WeaponManager->CurrentWeapon->GunMesh->GetSocketRotation(SocketName);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), FX, SocketLocation, SocketRotation);

		if (HasAuthority() && bMulticast)
		{
			Server_PlayWeaponFireFX(FX, SocketName);
		}
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

	FVector SocketLocation = WeaponManager->CurrentWeapon->GunMesh3P->GetSocketLocation(SocketName);
	FRotator SocketRotation = WeaponManager->CurrentWeapon->GunMesh3P->GetSocketRotation(SocketName);
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), FX, SocketLocation, SocketRotation);
}

#pragma endregion Weapons

#pragma region Equipping

void AffsCharacter::EquipWeapon()
{
	WeaponManager->CurrentWeapon->GunMesh->SetVisibility(false, false);
	WeaponManager->CurrentWeapon->GunMesh3P->SetVisibility(false, false);
	WeaponManager->CurrentWeapon = WeaponManager->InitializedWeapons[WeaponManager->CurrentGunIndex];
	WeaponManager->CurrentWeapon->GunMesh->SetVisibility(true, false);
	WeaponManager->CurrentWeapon->GunMesh3P->SetVisibility(true, false);

	FVector PlayerPivotOffset = WeaponManager->CurrentWeapon->GunMesh->GetSocketTransform(TEXT("WeaponPivot"), RTS_Component).GetLocation();
	FVector GunPivotOffset = WeaponManager->CurrentWeapon->GunPivotOffset;
	WeaponManager->CurrentWeapon->SetActorRelativeLocation(-PlayerPivotOffset - GunPivotOffset);

	UpdateAnimInstancePose(Cast<UffsAnimInstance>(Mesh1P->GetAnimInstance()), WeaponManager->CurrentWeapon->BasePose1P, WeaponManager->CurrentWeapon->PositionOffset, WeaponManager->CurrentWeapon->PointAim, PlayerPivotOffset, GunPivotOffset, WeaponManager->CurrentWeapon->EditingOffset);
	UpdateAnimInstancePose(Cast<UffsAnimInstance>(Mesh3P->GetAnimInstance()), WeaponManager->CurrentWeapon->BasePose1P, WeaponManager->CurrentWeapon->PositionOffset, WeaponManager->CurrentWeapon->PointAim, PlayerPivotOffset, GunPivotOffset, WeaponManager->CurrentWeapon->EditingOffset);

	if (WeaponManager->EquipMontage)
	{
		UAnimInstance *AnimInstance3P = Mesh3P->GetAnimInstance();
		AnimInstance3P->Montage_Play(WeaponManager->EquipMontage, 1.0f);
		UAnimInstance *AnimInstance1P = Mesh1P->GetAnimInstance();
		AnimInstance1P->Montage_Play(WeaponManager->EquipMontage, 1.0f);
	}

	if (IsLocallyControlled() || HasAuthority())
	{
		OnWeaponEquipped(
			WeaponManager->CurrentWeapon->RecoilAnimData, 
			WeaponManager->CurrentWeapon->FireRate, 
			WeaponManager->CurrentWeapon->Burst
		);
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

void AffsCharacter::UpdateAnimInstancePose(UffsAnimInstance *MeshAnimInstance, UAnimSequence *CharacterPose1P, FVector WeaponOffset, FTransform PointAim, FVector PlayerPivotOffset, FVector GunPivotOffset, FTransform EditingOffset)
{
	if (MeshAnimInstance)
	{
		MeshAnimInstance->CharacterPose1P = CharacterPose1P;
		MeshAnimInstance->WeaponOffset = WeaponOffset;
		MeshAnimInstance->PointAim = PointAim;
		MeshAnimInstance->PlayerPivotOffset = PlayerPivotOffset;
		MeshAnimInstance->GunPivotOffset = GunPivotOffset;
		MeshAnimInstance->EditingOffset = EditingOffset;
	}
}

#pragma endregion Helper Functions