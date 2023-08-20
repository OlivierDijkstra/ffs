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
	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("%s OnRep_CurrentWeapon: %s"), GetOwnerRole() == ROLE_Authority ? TEXT("Server") : TEXT("Client"), *CurrentWeapon->GetName()));

	OnWeaponEquipped.Broadcast();

	CurrentWeapon->SetActorHiddenInGame(false);

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

	AffsCharacter *Player = Cast<AffsCharacter>(GetOwner());

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
}

void UffsWeaponManager::OnRep_Weapons()
{
	AffsCharacter *Player = Cast<AffsCharacter>(GetOwner());

	if (Player)
	{
		for (int32 i = 0; i < Weapons.Num(); i++)
		{
			if (Weapons[i] && !Weapons[i]->bIsAttached)
			{
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("Initializing weapon: %s for %s"), *Weapons[i]->GetName(), GetOwnerRole() == ROLE_Authority ? TEXT("Server") : TEXT("Client")));

				Weapons[i]->AttachToActor(Player, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

				Weapons[i]->GunMesh->AttachToComponent(Player->Mesh1P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
				Weapons[i]->GunMesh->SetOnlyOwnerSee(true);
				Weapons[i]->GunMesh->bCastDynamicShadow = false;
				Weapons[i]->GunMesh->CastShadow = false;

				Weapons[i]->GunMesh3P->AttachToComponent(Player->Mesh3P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("GripPoint"));
				Weapons[i]->GunMesh3P->SetOwnerNoSee(true);

				Weapons[i]->SetActorHiddenInGame(true);
				Weapons[i]->UpdateFirstPersonGunMeshFOV(90.f);

				Weapons[i]->bIsAttached = true;
			}
		}
	}

	if (CurrentWeapon)
    {
        CurrentWeapon->SetActorHiddenInGame(false);
    }
}

FHitResult UffsWeaponManager::FireLineTrace(bool InitialShot, bool Debug)
{
	FHitResult FireLineTraceResult;
	APawn *OwnerPawn = Cast<APawn>(GetOwner());

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
	if (!Player || !WeaponClass)
		return nullptr;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = Player;
	SpawnParams.Instigator = Player;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AffsWeapon *Weapon = GetWorld()->SpawnActor<AffsWeapon>(WeaponClass, SpawnParams);

	Weapons.Add(Weapon);

	GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("Spawned weapon: %s for %s"), *Weapon->GetName(), GetOwnerRole() == ROLE_Authority ? TEXT("Server") : TEXT("Client")));

	if (!CurrentWeapon)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, FString::Printf(TEXT("Setting current weapon: %s for %s"), *Weapon->GetName(), GetOwnerRole() == ROLE_Authority ? TEXT("Server") : TEXT("Client")));

		CurrentWeapon = Weapon;
		CurrentWeaponIndex = 0;
		OnRep_CurrentWeapon();
	}

	return Weapon;
}

void UffsWeaponManager::NextWeapon()
{
	int32 NewWeaponIndex = IncrementCurrentWeaponIndex();

	if (Weapons.IsValidIndex(NewWeaponIndex))
	{
		CurrentWeapon = Weapons[NewWeaponIndex];
		OnRep_CurrentWeapon();
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