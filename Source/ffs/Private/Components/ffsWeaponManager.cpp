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

	DOREPLIFETIME(UffsWeaponManager, Weapons);
	DOREPLIFETIME(UffsWeaponManager, CurrentWeapon);
	DOREPLIFETIME(UffsWeaponManager, CurrentWeaponIndex);
}

void UffsWeaponManager::OnRep_CurrentWeapon()
{
	if (Weapons.Num() > 0)
	{
		for (int32 i = 0; i < Weapons.Num(); i++)
		{
			if (Weapons[i] && Weapons[i] != CurrentWeapon)
			{
				Weapons[i]->SetActorHiddenInGame(true);
			}
		}
	}

	if (!CurrentWeapon)
	{
		return;
	}

	OnWeaponEquipped.Broadcast();

	CurrentWeapon->SetActorHiddenInGame(false);

	AffsCharacter *Player = Cast<AffsCharacter>(GetOwner());

	if (!Player)
	{
		return;
	}

	FVector PlayerPivotOffset = CurrentWeapon->GunMesh->GetSocketTransform(TEXT("WeaponPivot"), RTS_Component).GetLocation();
	FVector GunPivotOffset = CurrentWeapon->GunPivotOffset;
	CurrentWeapon->SetActorRelativeLocation(-PlayerPivotOffset - GunPivotOffset);

	if (Player->Mesh1P)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Player->Mesh1P"));
		// Print the name of CurrentWeapon->BasePose
		// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, CurrentWeapon->BasePose->GetName());
		if (CurrentWeapon && CurrentWeapon->BasePose) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, CurrentWeapon->BasePose->GetName());
		}
		
		UpdateAnimInstancePose(Cast<UffsAnimInstance>(Player->Mesh1P->GetAnimInstance()), CurrentWeapon->BasePose, CurrentWeapon->PositionOffset, CurrentWeapon->PointAim, PlayerPivotOffset, GunPivotOffset);
	}

	// TODO This is not working, fix it, <- update: not sure why this comment is here, still gotta investigate.
	if (Player->GetMesh())
	{
		UpdateAnimInstancePose(Cast<UffsAnimInstance>(Player->GetMesh()->GetAnimInstance()), CurrentWeapon->BasePose, CurrentWeapon->PositionOffset, CurrentWeapon->PointAim, PlayerPivotOffset, GunPivotOffset);
	}
}

void UffsWeaponManager::OnRep_Weapons()
{
	if (Weapons.Num() == 0) return;

	AffsCharacter *Player = Cast<AffsCharacter>(GetOwner());

	if (Player)
	{
		for (int32 i = 0; i < Weapons.Num(); i++)
		{
			if (Weapons[i] && !Weapons[i]->bIsAttached)
			{
				Weapons[i]->GunMesh3P->SetSimulatePhysics(false);
				Weapons[i]->GunMesh3P->SetCollisionEnabled(ECollisionEnabled::NoCollision);

				Weapons[i]->AttachToActor(Player, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

				Weapons[i]->GunMesh->AttachToComponent(Player->Mesh1P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
				Weapons[i]->GunMesh->SetOnlyOwnerSee(true);
				Weapons[i]->GunMesh->bCastDynamicShadow = false;
				Weapons[i]->GunMesh->CastShadow = false;

				Weapons[i]->GunMesh3P->AttachToComponent(Player->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
				Weapons[i]->GunMesh3P->SetOwnerNoSee(true);
				Weapons[i]->bIsAttached = true;

				Weapons[i]->SetActorHiddenInGame(true);
				Weapons[i]->UpdateFirstPersonGunMeshFOV(90.f);

				Weapons[i]->DisableInteraction();
			}
		}
	}

	if (CurrentWeapon)
    {
        CurrentWeapon->SetActorHiddenInGame(false);
    }
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

int32 UffsWeaponManager::IncrementCurrentWeaponIndex()
{
	if (CurrentWeaponIndex < Weapons.Num() - 1)
	{
		CurrentWeaponIndex++;
	}
	else
	{
		CurrentWeaponIndex = 0;
	}

	return CurrentWeaponIndex;
}

AffsWeapon *UffsWeaponManager::SpawnWeaponOnPlayer(AffsCharacter *Player, TSubclassOf<AffsWeapon> WeaponClass)
{
	if (!Player || !WeaponClass || !Player->HasAuthority())
		return nullptr;

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	FVector SpawnLocation = Player->GetActorLocation();
	FRotator SpawnRotation = Player->GetActorRotation();

	AffsWeapon *Weapon = GetWorld()->SpawnActor<AffsWeapon>(WeaponClass, SpawnLocation, SpawnRotation, SpawnParams);

	if (!Weapon)
		return nullptr;

	if (!CurrentWeapon)
	{
		Server_EquipWeapon(Weapon);
	}

	return Weapon;
}

void UffsWeaponManager::NextWeapon()
{
	int32 NewWeaponIndex = IncrementCurrentWeaponIndex();
	AffsCharacter *Player = Cast<AffsCharacter>(GetOwner());

	if (Weapons.IsValidIndex(NewWeaponIndex))
	{
		CurrentWeapon = Weapons[NewWeaponIndex];
		
		Player->GetRecoilAnimation()->Init(
			CurrentWeapon->RecoilAnimData,
			CurrentWeapon->FireRate,
			CurrentWeapon->Burst
		);
	}

}

void UffsWeaponManager::DropWeapon(bool SwapToNext)
{
	APawn *Owner = Cast<APawn>(GetOwner());

	if (Owner->IsLocallyControlled() && !Owner->HasAuthority())
	{
		Server_DropWeapon(Owner, SwapToNext);
	}
}

void UffsWeaponManager::Server_DropWeapon_Implementation(APawn *Owner, bool SwapToNext)
{
	if (Owner->HasAuthority())
	{
		if (Weapons.Num() <= 1)
		{
			return;
		}

		AffsWeapon *WeaponBackup = Weapons[CurrentWeaponIndex];
		WeaponBackup->SetOwner(nullptr);

		Multicast_DropWeapon(WeaponBackup);

		CurrentWeapon = nullptr;
		Weapons.Remove(WeaponBackup);

		if (Weapons.Num() > 0 && SwapToNext)
		{
			NextWeapon();
		}
	}
}

void UffsWeaponManager::Multicast_DropWeapon_Implementation(AffsWeapon *Weapon)
{	
	Weapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

	Weapon->GunMesh->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	
	Weapon->GunMesh3P->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	Weapon->GunMesh3P->SetOwnerNoSee(false);

	Weapon->GunMesh3P->SetSimulatePhysics(true);
	Weapon->GunMesh3P->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Weapon->GunMesh3P->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	Weapon->GunMesh3P->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Ignore);
	Weapon->GunMesh3P->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	Weapon->GunMesh3P->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Ignore);
	Weapon->GunMesh3P->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Ignore);
	Weapon->GunMesh3P->SetCollisionResponseToChannel(ECC_Destructible, ECR_Ignore);
    Weapon->GunMesh3P->SetCollisionResponseToChannel(ECC_GameTraceChannel3, ECR_Block);

	Weapon->bIsAttached = false;
	Weapon->EnableInteraction();
}

void UffsWeaponManager::EquipWeapon(AffsWeapon* Weapon)
{
	APawn* Owner = Cast<APawn>(GetOwner());

	if (Owner->IsLocallyControlled() && !Owner->HasAuthority())
	{
		Server_EquipWeapon(Weapon);
	}
}

void UffsWeaponManager::Server_EquipWeapon_Implementation(AffsWeapon* Weapon)
{
	if (GetOwner()->HasAuthority() && Weapon)
	{
		AffsCharacter* Player = Cast<AffsCharacter>(GetOwner());

		if (Weapons.Num() >= 2)
		{
			Server_DropWeapon(Player, false);
		}

		Weapon->SetOwner(Player);
		Weapons.Add(Weapon);

		NextWeapon();

		Multicast_EquipWeapon();
	}
}

void UffsWeaponManager::Multicast_EquipWeapon_Implementation()
{
	OnWeaponAdded.Broadcast();
}

void UffsWeaponManager::UpdateAnimInstancePose(UffsAnimInstance *MeshAnimInstance, UAnimSequence *CharacterPose, FVector WeaponOffset, FTransform PointAim, FVector PlayerPivotOffset, FVector GunPivotOffset)
{
	if (MeshAnimInstance)
	{
		MeshAnimInstance->CharacterPose = CharacterPose;
		MeshAnimInstance->WeaponOffset = WeaponOffset;
		MeshAnimInstance->PointAim = PointAim;
		MeshAnimInstance->PlayerPivotOffset = PlayerPivotOffset;
		MeshAnimInstance->GunPivotOffset = GunPivotOffset;
	}
}