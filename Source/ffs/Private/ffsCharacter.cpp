#include "ffsCharacter.h"
#include "ffsAnimInstance.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "ffsCharacterMovementComponent.h"
#include "Animations/GSCNativeAnimInstanceInterface.h"
#include "Weapon.h"

AffsCharacter::AffsCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UffsCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetCapsuleComponent());
	CameraBoom->TargetArmLength = 300.0f;		// The length of the arm.
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a CameraComponent
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	// Update camera setup
	FirstPersonCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	// Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	// Create a mesh component that will be used when being viewed from a '3rd person' view (when controlling another pawn)
	Mesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh3P"));
	Mesh3P->SetOwnerNoSee(true);
	Mesh3P->SetupAttachment(GetCapsuleComponent());
	Mesh3P->bCastDynamicShadow = true;
	Mesh3P->CastShadow = true;
	// Mesh3P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	//  Mesh3P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	RecoilAnimation = CreateDefaultSubobject<URecoilAnimationComponent>(TEXT("RecoilAnimComp"));
	AnimMasterComponent = CreateDefaultSubobject<UAGRAnimMasterComponent>(TEXT("AGRAnimMaster"));
}

#pragma region Initialization

void AffsCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AffsCharacter, CurrentGunIndex, COND_SkipOwner);
}

void AffsCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Setup blueprint property mapping for Mesh1P
	if (Mesh1P)
	{
		if (IGSCNativeAnimInstanceInterface *AnimInstanceInterface = Cast<IGSCNativeAnimInstanceInterface>(Mesh1P->GetAnimInstance()))
		{
			UAbilitySystemComponent *ASC = reinterpret_cast<UAbilitySystemComponent *>(AbilitySystemComponent);
			AnimInstanceInterface->InitializeWithAbilitySystem(ASC);
		}
	}

	// Setup blueprint property mapping for Mesh3P
	if (Mesh3P)
	{
		if (IGSCNativeAnimInstanceInterface *AnimInstanceInterface = Cast<IGSCNativeAnimInstanceInterface>(Mesh3P->GetAnimInstance()))
		{
			UAbilitySystemComponent *ASC = reinterpret_cast<UAbilitySystemComponent *>(AbilitySystemComponent);
			AnimInstanceInterface->InitializeWithAbilitySystem(ASC);
		}
	}
}

#pragma endregion Initialization

void AffsCharacter::UpdateAnimInstancePose(UffsAnimInstance *MeshAnimInstance, UAnimSequence *CharacterPose1P, UAnimSequence *CharacterPose3P, FVector WeaponOffset, FTransform PointAim, FVector PlayerPivotOffset, FVector GunPivotOffset, FTransform EditingOffset)
{
	if (MeshAnimInstance)
	{
		MeshAnimInstance->CharacterPose1P = CharacterPose1P;
		MeshAnimInstance->CharacterPose3P = CharacterPose3P;
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

	AWeapon* Weapon = GetWorld()->SpawnActor<AWeapon>(WeaponInventory[WeaponIndex], SpawnParams);

	Weapon->GunMesh->AttachToComponent(Mesh1P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
	Weapon->GunMesh->SetOnlyOwnerSee(true);

	Weapon->GunMesh3P->AttachToComponent(Mesh3P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
	Weapon->GunMesh3P->SetOwnerNoSee(true);

	Weapon->GunMesh->SetVisibility(false, true);
	Weapon->GunMesh3P->SetVisibility(false, true);

	InitializedWeapons.Add(Weapon);
}

#pragma region Equipping

void AffsCharacter::EquipWeapon(int WeaponIndex)
{
    if (IsLocallyControlled())
    {
        Server_EquipWeapon(WeaponIndex);
    }
}

void AffsCharacter::Server_EquipWeapon_Implementation(int WeaponIndex)
{
    if (WeaponIndex >= 0 && WeaponIndex < InitializedWeapons.Num())
    {
        Multicast_EquipWeapon(WeaponIndex);
    }
}

bool AffsCharacter::Server_EquipWeapon_Validate(int WeaponIndex)
{
    return WeaponIndex >= 0 && WeaponIndex < InitializedWeapons.Num();
}

void AffsCharacter::Multicast_EquipWeapon_Implementation(int WeaponIndex)
{
    if (CurrentWeapon != nullptr)
    {
        CurrentWeapon->GunMesh->SetVisibility(false, false);
        CurrentWeapon->GunMesh3P->SetVisibility(false, false);
    }

    CurrentWeapon = InitializedWeapons[WeaponIndex];
    CurrentWeapon->GunMesh->SetVisibility(true, false);
    CurrentWeapon->GunMesh3P->SetVisibility(true, false);

    FVector PlayerPivotOffset = CurrentWeapon->GunMesh->GetSocketTransform(TEXT("WeaponPivot"), RTS_Component).GetLocation();

    CurrentWeapon->SetActorRelativeLocation(-PlayerPivotOffset - CurrentWeapon->GunPivotOffset);
    
    UpdateAnimInstancePose(Cast<UffsAnimInstance>(Mesh1P->GetAnimInstance()), CurrentWeapon->BasePose1P, CurrentWeapon->BasePose3P, CurrentWeapon->PositionOffset, CurrentWeapon->PointAim, PlayerPivotOffset, CurrentWeapon->GunPivotOffset, CurrentWeapon->EditingOffset);
    
    if(IsLocallyControlled() || HasAuthority())
    {
        OnWeaponEquipped(CurrentWeapon->RecoilAnimData, CurrentWeapon->FireRate, CurrentWeapon->Burst);
        // TODO: Set burst and firemode
    }
}

#pragma endregion Equipping

void AffsCharacter::ChangeWeapon()
{
	CurrentGunIndex = (CurrentGunIndex + 1) % WeaponInventory.Num();

	UnequipWeapon();
}

#pragma region UnEquipping

void AffsCharacter::UnequipWeapon()
{
	// TODO: Unequip montage

	if(IsLocallyControlled() && !HasAuthority())
	{
		Server_UnequipWeapon(CurrentGunIndex);
	} else if(HasAuthority()) {
		Multicast_UnequipWeapon();
	}
}

void AffsCharacter::Server_UnequipWeapon_Implementation(int WeaponIndex)
{
	if(HasAuthority())
	{
		CurrentGunIndex = WeaponIndex;
		const auto Gun = InitializedWeapons[WeaponIndex];
		OnWeaponEquipped(Gun->RecoilAnimData, Gun->FireRate, Gun->Burst);

		Multicast_UnequipWeapon();
	}
}

void AffsCharacter::Multicast_UnequipWeapon_Implementation()
{
	if(!IsLocallyControlled())
	{
		// TODO: Unequip animation
	}
}

#pragma endregion UnEquipping

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