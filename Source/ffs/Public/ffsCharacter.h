// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "GameFramework/SpringArmComponent.h"

#include "ModularGameplayActors/GSCModularCharacter.h"
#include "Components/AGRAnimMasterComponent.h"
#include "RecoilAnimationComponent.h"

#include "ffsAnimInstance.h"

#include "ffsCharacter.generated.h"

class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class AWeapon;

UCLASS(config = Game)
class AffsCharacter : public AGSCModularCharacter
{
	GENERATED_BODY()

public:
	AffsCharacter(const FObjectInitializer &ObjectInitializer);

protected:
	// APawn interface
	virtual void BeginPlay();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;
	// End of APawn interface

	// Pawn mesh: 1st person view (arms; seen only by self)
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent *Mesh1P;

	UFUNCTION(BlueprintCallable)
	UffsAnimInstance *GetAnimInstance1P() const { return Cast<UffsAnimInstance>(Mesh1P->GetAnimInstance()); }

	// Pawn mesh 3p: 3rd person view (body; seen only by others)
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent *Mesh3P;

	UFUNCTION(BlueprintCallable)
	UffsAnimInstance *GetAnimInstance3P() const { return Cast<UffsAnimInstance>(Mesh3P->GetAnimInstance()); }

	UFUNCTION(BlueprintCallable)
	void UpdateAnimInstancePose(UffsAnimInstance *MeshAnimInstance, UAnimSequence *CharacterPose1P, UAnimSequence *CharacterPose3P, FVector WeaponOffset, FTransform PointAim, FVector PlayerPivotOffset, FVector GunPivotOffset, FTransform EditingOffset);

	// First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent *FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent *CameraBoom;

	// Procudueral Recoil Animation
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Recoil Animation", meta = (AllowPrivateAccess="true"))
	URecoilAnimationComponent* RecoilAnimation;

	// AGRPRO
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	UAGRAnimMasterComponent *AnimMasterComponent;

	// Weapons
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapons", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<AWeapon>> WeaponInventory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapons")
	TArray<AWeapon*> InitializedWeapons;

	UPROPERTY(Replicated, BlueprintReadWrite, Category = "Weapons")
	int CurrentGunIndex = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Weapons")
	TEnumAsByte<EFireMode_PRAS> FireMode;

	UPROPERTY(BlueprintReadWrite, Category = "Weapons")
	AWeapon* CurrentWeapon = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	AWeapon* GetWeapon() const { return CurrentWeapon; }

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void InitWeapon(int Index);

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void EquipWeapon(int Index);
	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation, Category = "Net")
	void Server_EquipWeapon(int Index);
	UFUNCTION(BlueprintCallable, NetMulticast, Reliable, Category = "Net")
	void Multicast_EquipWeapon(int Index);

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void ChangeWeapon();

	void UnequipWeapon();
	UFUNCTION(Server, Reliable, Category = "Net")
	void Server_UnequipWeapon(int Index);
	UFUNCTION(NetMulticast, Reliable, Category = "Net")
	void Multicast_UnequipWeapon();

	UFUNCTION(BlueprintImplementableEvent, Category = "Weapons")
	void OnWeaponEquipped(const FRecoilAnimData Data, const float Rate = 0.0f, const int Bursts = 0);

public:
	USkeletalMeshComponent *GetMesh1P() const { return Mesh1P; }
	USkeletalMeshComponent *GetMesh3P() const { return Mesh3P; }

	UCameraComponent *GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	URecoilAnimationComponent* GetRecoilAnimation() const { return RecoilAnimation; }

	FCollisionQueryParams GetIgnoreCharacterParams() const;
};
