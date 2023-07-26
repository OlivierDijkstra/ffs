#include "Components/ffsWeaponManager.h"
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

void UffsWeaponManager::PlayWeaponFireFX(UNiagaraSystem *FX, FName SocketName)
{
    if (CurrentWeapon)
	{
		FVector SocketLocation = CurrentWeapon->GunMesh->GetSocketLocation(SocketName);
		FRotator SocketRotation = CurrentWeapon->GunMesh->GetSocketRotation(SocketName);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), FX, SocketLocation, SocketRotation);
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
