#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "NiagaraSystem.h"
#include "RecoilAnimationComponent.h"
#include "Interfaces/ffsIsInteractable.h"
#include "ffsWeapon.generated.h"

class UChildActorComponent;
class UUserWidget;
class AffsInteractionArea;
class AffsCharacter;

UCLASS(BlueprintType)
class FFS_API AffsWeapon : public AActor, public IffsIsInteractable
{
	GENERATED_BODY()
	
	AffsWeapon();

protected:
	virtual void PostInitializeComponents() override;

public:
	//
	// Core
	//
	UPROPERTY()
	USceneComponent* Pivot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	USkeletalMeshComponent* GunMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	USkeletalMeshComponent* GunMesh3P;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	float FireRate = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	int Burst = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	bool bFullAuto = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	bool bBursts = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Crosshair")
	UTexture2D* CrosshairTexture;

	//
	// Replication
	//
	// Might not be needed
	UPROPERTY(BlueprintReadOnly, Category = "Weapon")
	bool bIsAttached = false;

	//
	// Interaction
	//
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UChildActorComponent* InteractionAreaComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    UWidgetComponent* InteractionWidgetComponent;

	void ImplementedToggleFocus_Implementation(bool bIsFocused) override;
	void Interact_Implementation(AffsCharacter *InteractingCharacter) override;
	UUserWidget* GetInteractionWidget_Implementation() override;

	UFUNCTION()
	void EnableInteraction();
	UFUNCTION()
	void DisableInteraction();

	//
	// Animation
	//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
	UNiagaraSystem* CaseEjectFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
	UNiagaraSystem* MuzzleFlashFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* FireMontage;

	// TODO: Rename to just BasePose
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimSequence* BasePose;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimSequence* SprintPose;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* EquipMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* UnequipMontage;

	// Changes the position of the gun using IK to keep the hands in the same place
	// Useful for tweaking animations.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	FVector PositionOffset = FVector::ZeroVector;
	
	// Changes where the gun's recoil originates from
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	FVector GunPivotOffset = FVector::ZeroVector;
	
	// Where the nose of the barrel is pointing
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	FTransform PointAim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	FRecoilAnimData RecoilAnimData;

	//
	// Damage
	//
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float WeaponDamage = 20.f; // Default 20 damage per shot

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float HeadshotMultiplier = 2.f; // Default 2x multiplier

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float WeaponRange = 3000.f; // Default 1000 units range

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float WeaponSpread = 0.1f; // Default 10% spread

	//
	// Utility
	//
	UFUNCTION(BlueprintCallable, Category = "Mesh")
	void UpdateFirstPersonGunMeshFOV(float FOV);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Animation")
	TSubclassOf<UCameraShakeBase> CameraRecoilShake;
};