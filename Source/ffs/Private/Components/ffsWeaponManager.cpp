#include "Components/ffsWeaponManager.h"
#include "Animation/AnimInstance.h"
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