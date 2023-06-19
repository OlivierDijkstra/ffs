// Designed by Hitman's Store 2022

#include "Weapon.h"

AWeapon::AWeapon()
{
	Pivot = CreateDefaultSubobject<USceneComponent>(TEXT("Pivot"));

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	GunMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GunMesh->bEditableWhenInherited = true;

	GunMesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh3P"));
	GunMesh3P->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GunMesh3P->bEditableWhenInherited = true;
}

void AWeapon::PlayFireAnim() const
{
	if(FireMontage)
	{
		GunMesh->PlayAnimation(FireMontage, false);
	}
}