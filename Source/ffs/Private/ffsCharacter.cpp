#include "ffsCharacter.h"
#include "ffsAnimInstance.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "ffsCharacterMovementComponent.h"
#include "Animations/GSCNativeAnimInstanceInterface.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "Weapon.h"

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
}

#pragma region Initialization

void AffsCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AffsCharacter, CurrentGunIndex, COND_SkipOwner);
}

void AffsCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (Mesh1P)
	{
		if (IGSCNativeAnimInstanceInterface *AnimInstanceInterface = Cast<IGSCNativeAnimInstanceInterface>(Mesh1P->GetAnimInstance()))
		{
			UAbilitySystemComponent *ASC = reinterpret_cast<UAbilitySystemComponent *>(AbilitySystemComponent);
			AnimInstanceInterface->InitializeWithAbilitySystem(ASC);
		}
	}

	if (Mesh3P)
	{
		if (IGSCNativeAnimInstanceInterface *AnimInstanceInterface = Cast<IGSCNativeAnimInstanceInterface>(Mesh3P->GetAnimInstance()))
		{
			UAbilitySystemComponent *ASC = reinterpret_cast<UAbilitySystemComponent *>(AbilitySystemComponent);
			AnimInstanceInterface->InitializeWithAbilitySystem(ASC);
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
}

#pragma endregion Initialization

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

void AffsCharacter::InitWeapon(int WeaponIndex)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AWeapon *Weapon = GetWorld()->SpawnActor<AWeapon>(WeaponInventory[WeaponIndex], SpawnParams);

	Weapon->GunMesh->AttachToComponent(Mesh1P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
	Weapon->GunMesh->SetOnlyOwnerSee(true);
	Weapon->GunMesh->bCastDynamicShadow = false;
	Weapon->GunMesh->CastShadow = false;

	Weapon->GunMesh3P->AttachToComponent(Mesh3P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
	Weapon->GunMesh3P->SetOwnerNoSee(true);

	Weapon->GunMesh->SetVisibility(false, true);
	Weapon->GunMesh3P->SetVisibility(false, true);

	InitializedWeapons.Add(Weapon);

	Weapon->UpdateFirstPersonGunMeshFOV(90.f);
}

void AffsCharacter::PlayCameraShake()
{
	if (IsLocallyControlled() && CurrentWeapon && CurrentWeapon->CameraRecoilShake)
	{
		UGameplayStatics::GetPlayerCameraManager(this, 0)
			->StartCameraShake(CurrentWeapon->CameraRecoilShake);
	}
}

FFireLineTraceResult AffsCharacter::FireWeapon(bool InitialShot, bool Debug)
{
	FFireLineTraceResult FireLineTraceResult;

	if (CurrentWeapon)
	{
		if (IsLocallyControlled() && !HasAuthority())
		{
			FireLineTraceResult = CurrentWeapon->FireLineTrace(InitialShot, Debug);
		}

		PlayFireAnimation();
	}

	return FireLineTraceResult;
}

void AffsCharacter::PlayFireAnimation()
{
	RecoilAnimation->Play();

	CurrentWeapon->GunMesh->PlayAnimation(CurrentWeapon->FireMontage, false);

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
	UAnimMontage *FireAnimation = CurrentWeapon->FireMontage;

	if (FireAnimation)
	{
		CurrentWeapon->GunMesh3P->PlayAnimation(FireAnimation, false);
	}
}

void AffsCharacter::PlayCaseEjectFX()
{
	if (CurrentWeapon)
	{
		FVector SocketLocation = CurrentWeapon->GunMesh->GetSocketLocation(TEXT("ShellEject"));
		FRotator SocketRotation = CurrentWeapon->GunMesh->GetSocketRotation(TEXT("ShellEject"));

		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), CurrentWeapon->CaseEjectFX, SocketLocation, SocketRotation);

		if (HasAuthority())
		{
			Server_PlayCaseEjectFX();
		}	
	}
}

void AffsCharacter::Server_PlayCaseEjectFX_Implementation()
{
	Multicast_PlayCaseEjectFX();
}

void AffsCharacter::Multicast_PlayCaseEjectFX_Implementation()
{
	// If its the player, skip
	if (IsLocallyControlled())
	{
		return;
	}

	FVector SocketLocation = CurrentWeapon->GunMesh3P->GetSocketLocation(TEXT("ShellEject"));
	FRotator SocketRotation = CurrentWeapon->GunMesh3P->GetSocketRotation(TEXT("ShellEject"));

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), CurrentWeapon->CaseEjectFX, SocketLocation, SocketRotation);
}

#pragma region Equipping

void AffsCharacter::EquipWeapon()
{
	CurrentWeapon->GunMesh->SetVisibility(false, false);
	CurrentWeapon->GunMesh3P->SetVisibility(false, false);
	CurrentWeapon = InitializedWeapons[CurrentGunIndex];
	CurrentWeapon->GunMesh->SetVisibility(true, false);
	CurrentWeapon->GunMesh3P->SetVisibility(true, false);

	FVector PlayerPivotOffset = CurrentWeapon->GunMesh->GetSocketTransform(TEXT("WeaponPivot"), RTS_Component).GetLocation();
	FVector GunPivotOffset = CurrentWeapon->GunPivotOffset;
	CurrentWeapon->SetActorRelativeLocation(-PlayerPivotOffset - GunPivotOffset);

	UpdateAnimInstancePose(Cast<UffsAnimInstance>(Mesh1P->GetAnimInstance()), CurrentWeapon->BasePose1P, CurrentWeapon->PositionOffset, CurrentWeapon->PointAim, PlayerPivotOffset, GunPivotOffset, CurrentWeapon->EditingOffset);
	UpdateAnimInstancePose(Cast<UffsAnimInstance>(Mesh3P->GetAnimInstance()), CurrentWeapon->BasePose1P, CurrentWeapon->PositionOffset, CurrentWeapon->PointAim, PlayerPivotOffset, GunPivotOffset, CurrentWeapon->EditingOffset);

	if (EquipMontage)
	{
		UAnimInstance *AnimInstance1P = Mesh1P->GetAnimInstance();
		AnimInstance1P->Montage_Play(EquipMontage, 0.8f);

		UAnimInstance *AnimInstance3P = Mesh3P->GetAnimInstance();
		AnimInstance3P->Montage_Play(EquipMontage, 0.8f);
	}

	if (IsLocallyControlled() || HasAuthority())
	{
		OnWeaponEquipped(CurrentWeapon->RecoilAnimData, CurrentWeapon->FireRate, CurrentWeapon->Burst);
		// TODO: Set burst and firemode
	}
}

void AffsCharacter::ChangeWeapon()
{
	if (!CurrentWeapon)
	{
		return;
	}

	const int LastIndex = CurrentGunIndex;
	CurrentGunIndex++;

	if (CurrentGunIndex > InitializedWeapons.Num() - 1)
	{
		CurrentGunIndex = 0;
	}

	if (!InitializedWeapons[CurrentGunIndex])
	{
		CurrentGunIndex = LastIndex;
		return;
	}

	UnequipWeapon();
}

void AffsCharacter::UnequipWeapon()
{
	if (UnequipMontage)
	{
		UAnimInstance *AnimInstance1P = Mesh1P->GetAnimInstance();
		AnimInstance1P->Montage_Play(UnequipMontage, 1.0f);
	}

	OnWeaponUnequipped();

	if (IsLocallyControlled() && !HasAuthority())
	{
		Server_UnequipWeapon(CurrentGunIndex);
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
		CurrentGunIndex = WeaponIndex;
		const auto Gun = InitializedWeapons[WeaponIndex];
		OnWeaponEquipped(Gun->RecoilAnimData, Gun->FireRate, Gun->Burst);

		Multicast_UnequipWeapon();
	}
}

void AffsCharacter::Multicast_UnequipWeapon_Implementation()
{
	if (!IsLocallyControlled())
	{
		if (UnequipMontage)
		{
			UAnimInstance *AnimInstance1P = Mesh1P->GetAnimInstance();
			AnimInstance1P->Montage_Play(UnequipMontage, 1.0f);
		}
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