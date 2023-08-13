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

	DOREPLIFETIME_CONDITION(UffsWeaponManager, EquippedWeaponType, COND_SkipOwner);
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

AffsWeapon* UffsWeaponManager::SpawnWeaponOnPlayer(AffsCharacter *Player, TSubclassOf<AffsWeapon> WeaponClass)
{
	if (!Player || !WeaponClass) return nullptr;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = Player;
	SpawnParams.Instigator = Player;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AffsWeapon *Weapon = GetWorld()->SpawnActor<AffsWeapon>(WeaponClass, SpawnParams);
	Weapon->AttachToActor(Player, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	Weapon->GunMesh->AttachToComponent(Player->Mesh1P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
	Weapon->GunMesh->SetOnlyOwnerSee(true);
	Weapon->GunMesh->bCastDynamicShadow = false;
	Weapon->GunMesh->CastShadow = false;

	Weapon->GunMesh3P->AttachToComponent(Player->Mesh3P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
	Weapon->GunMesh3P->SetOwnerNoSee(true);

	Weapon->GunMesh->SetVisibility(false, true);
	Weapon->GunMesh3P->SetVisibility(false, true);
	
	Weapon->UpdateFirstPersonGunMeshFOV(90.f);

	return Weapon;
}

void UffsWeaponManager::EquipWeaponOnPlayer(AffsCharacter *Player, AffsWeapon *Weapon)
{
	if (!Player || !Weapon) return;

	SwitchWeaponVisibility(EquippedWeaponType);
	
	CurrentWeapon = Weapon;

	FVector PlayerPivotOffset = CurrentWeapon->GunMesh->GetSocketTransform(TEXT("WeaponPivot"), RTS_Component).GetLocation();
	FVector GunPivotOffset = CurrentWeapon->GunPivotOffset;
	CurrentWeapon->SetActorRelativeLocation(-PlayerPivotOffset - GunPivotOffset);

	if (Player->Mesh1P) 
	{
		UpdateAnimInstancePose(Cast<UffsAnimInstance>(Player->Mesh1P->GetAnimInstance()), CurrentWeapon->BasePose1P, CurrentWeapon->PositionOffset, CurrentWeapon->PointAim, PlayerPivotOffset, GunPivotOffset, CurrentWeapon->EditingOffset);
	}

	if (Player->Mesh3P)
	{
		UpdateAnimInstancePose(Cast<UffsAnimInstance>(Player->Mesh3P->GetAnimInstance()), CurrentWeapon->BasePose1P, CurrentWeapon->PositionOffset, CurrentWeapon->PointAim, PlayerPivotOffset, GunPivotOffset, CurrentWeapon->EditingOffset);
	}

	if (EquipMontage)
	{
		UAnimInstance *AnimInstance3P = Player->Mesh3P->GetAnimInstance();
		AnimInstance3P->Montage_Play(EquipMontage, 1.0f);
		UAnimInstance *AnimInstance1P = Player->Mesh1P->GetAnimInstance();
		AnimInstance1P->Montage_Play(EquipMontage, 1.0f);
	}

	
	Player->OnWeaponEquipped(
		CurrentWeapon->RecoilAnimData,
		CurrentWeapon->FireRate,
		CurrentWeapon->Burst);
}

void UffsWeaponManager::EquipPrimaryWeapon(AffsCharacter *Player)
{
	if (!PrimaryWeapon) return;

	EquippedWeaponType = EEquippedWeapon::PRIMARY;

	SwitchWeaponVisibility(EEquippedWeapon::PRIMARY);
	EquipWeaponOnPlayer(Player, PrimaryWeapon);
}

void UffsWeaponManager::EquipSecondaryWeapon(AffsCharacter *Player)
{
	if (!SecondaryWeapon) return;

	SwitchWeaponVisibility(EEquippedWeapon::SECONDARY);
	EquipWeaponOnPlayer(Player, SecondaryWeapon);
}

void UffsWeaponManager::SwitchWeaponVisibility(EEquippedWeapon WeaponType)
{
	switch (WeaponType)
	{
	case EEquippedWeapon::PRIMARY:
		if (PrimaryWeapon)
		{
			PrimaryWeapon->GunMesh->SetVisibility(true, true);
			PrimaryWeapon->GunMesh3P->SetVisibility(true, true);
		}

		if (SecondaryWeapon)
		{
			SecondaryWeapon->GunMesh->SetVisibility(false, true);
			SecondaryWeapon->GunMesh3P->SetVisibility(false, true);
		}
		break;
	case EEquippedWeapon::SECONDARY:
		if (PrimaryWeapon)
		{
			PrimaryWeapon->GunMesh->SetVisibility(false, true);
			PrimaryWeapon->GunMesh3P->SetVisibility(false, true);
		}

		if (SecondaryWeapon)
		{
			SecondaryWeapon->GunMesh->SetVisibility(true, true);
			SecondaryWeapon->GunMesh3P->SetVisibility(true, true);
		}
		break;
	case EEquippedWeapon::NONE:
		if (PrimaryWeapon)
		{
			PrimaryWeapon->GunMesh->SetVisibility(false, true);
			PrimaryWeapon->GunMesh3P->SetVisibility(false, true);
		}

		if (SecondaryWeapon)
		{
			SecondaryWeapon->GunMesh->SetVisibility(false, true);
			SecondaryWeapon->GunMesh3P->SetVisibility(false, true);
		}
		break;
	default:
		break;
	}
}