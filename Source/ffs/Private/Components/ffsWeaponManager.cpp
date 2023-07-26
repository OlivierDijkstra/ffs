#include "Components/ffsWeaponManager.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "NiagaraFunctionLibrary.h"
#include "ffsCharacter.h"
#include "ffsWeapon.h"

UffsWeaponManager::UffsWeaponManager()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UffsWeaponManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(UffsWeaponManager, CurrentGunIndex, COND_SkipOwner);
}

void UffsWeaponManager::InitWeapon(int WeaponIndex, AffsCharacter* Owner)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = Owner;
	SpawnParams.Instigator = Owner;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AffsWeapon *Weapon = GetWorld()->SpawnActor<AffsWeapon>(WeaponInventory[WeaponIndex], SpawnParams);

	Weapon->GunMesh->AttachToComponent(Owner->Mesh1P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
	Weapon->GunMesh->SetOnlyOwnerSee(true);
	Weapon->GunMesh->bCastDynamicShadow = false;
	Weapon->GunMesh->CastShadow = false;

	Weapon->GunMesh3P->AttachToComponent(Owner->Mesh3P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
	Weapon->GunMesh3P->SetOwnerNoSee(true);

	Weapon->GunMesh->SetVisibility(false, true);
	Weapon->GunMesh3P->SetVisibility(false, true);

	InitializedWeapons.Add(Weapon);

	Weapon->UpdateFirstPersonGunMeshFOV(90.f);
}

FHitResult UffsWeaponManager::FireLineTrace(bool InitialShot, bool Debug)
{
	FHitResult FireLineTraceResult;
    APawn* OwnerPawn = Cast<APawn>(GetOwner());

	if (CurrentWeapon && OwnerPawn && !OwnerPawn->IsLocallyControlled() && OwnerPawn->HasAuthority())
	{
		FireLineTraceResult = CurrentWeapon->FireLineTrace(InitialShot, Debug);
	}

	return FireLineTraceResult;
}

void UffsWeaponManager::PlayFireAnimation(bool ThirdPerson)
{
    if (CurrentWeapon && CurrentWeapon->FireMontage)
    {
        if (ThirdPerson)
        {
            CurrentWeapon->GunMesh3P->PlayAnimation(CurrentWeapon->FireMontage, false);
        }
        else 
        {
            CurrentWeapon->GunMesh->PlayAnimation(CurrentWeapon->FireMontage, false);
        }
    }
}

void UffsWeaponManager::PlayWeaponFireFX(UNiagaraSystem *FX, FName SocketName, bool ThirdPerson)
{
    if (CurrentWeapon)
	{
		USkeletalMeshComponent *Mesh = ThirdPerson ? CurrentWeapon->GunMesh3P : CurrentWeapon->GunMesh;

		FVector SocketLocation = Mesh->GetSocketLocation(SocketName);
		FRotator SocketRotation = Mesh->GetSocketRotation(SocketName);
	
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), FX, SocketLocation, SocketRotation);
	}
}

void UffsWeaponManager::EquipWeapon(USkeletalMeshComponent *Mesh1P, USkeletalMeshComponent *Mesh3P)
{
	CurrentWeapon->GunMesh->SetVisibility(false, false);
	CurrentWeapon->GunMesh3P->SetVisibility(false, false);
	CurrentWeapon = InitializedWeapons[CurrentGunIndex];
	CurrentWeapon->GunMesh->SetVisibility(true, false);
	CurrentWeapon->GunMesh3P->SetVisibility(true, false);

	FVector PlayerPivotOffset = CurrentWeapon->GunMesh->GetSocketTransform(TEXT("WeaponPivot"), RTS_Component).GetLocation();
	FVector GunPivotOffset = CurrentWeapon->GunPivotOffset;
	CurrentWeapon->SetActorRelativeLocation(-PlayerPivotOffset - GunPivotOffset);

	if (Mesh1P) 
	{
		UpdateAnimInstancePose(Cast<UffsAnimInstance>(Mesh1P->GetAnimInstance()), CurrentWeapon->BasePose1P, CurrentWeapon->PositionOffset, CurrentWeapon->PointAim, PlayerPivotOffset, GunPivotOffset, CurrentWeapon->EditingOffset);
	}

	if (Mesh3P)
	{
		UpdateAnimInstancePose(Cast<UffsAnimInstance>(Mesh3P->GetAnimInstance()), CurrentWeapon->BasePose1P, CurrentWeapon->PositionOffset, CurrentWeapon->PointAim, PlayerPivotOffset, GunPivotOffset, CurrentWeapon->EditingOffset);
	}

	if (EquipMontage)
	{
		UAnimInstance *AnimInstance3P = Mesh3P->GetAnimInstance();
		AnimInstance3P->Montage_Play(EquipMontage, 1.0f);
		UAnimInstance *AnimInstance1P = Mesh1P->GetAnimInstance();
		AnimInstance1P->Montage_Play(EquipMontage, 1.0f);
	}
}

void UffsWeaponManager::UpdateAnimInstancePose(UffsAnimInstance *MeshAnimInstance, UAnimSequence *CharacterPose1P, FVector WeaponOffset, FTransform PointAim, FVector PlayerPivotOffset, FVector GunPivotOffset, FTransform EditingOffset)
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
