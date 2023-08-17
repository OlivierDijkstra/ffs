#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RecoilAnimationComponent.h"
#include "NiagaraSystem.h"
#include "ffsWeapon.generated.h"

UCLASS(BlueprintType)
class FFS_API AffsWeapon : public AActor
{
	GENERATED_BODY()
	
	AffsWeapon();

	UPROPERTY()
	USceneComponent* Pivot;

protected:
	virtual void PostInitializeComponents() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
	UNiagaraSystem* CaseEjectFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
	UNiagaraSystem* MuzzleFlashFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* FireMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float WeaponDamage = 20.f; // Default 20 damage per shot

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float HeadshotMultiplier = 2.f; // Default 2x multiplier

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float WeaponRange = 3000.f; // Default 1000 units range

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float WeaponSpread = 0.1f; // Default 10% spread
	
	FHitResult FireLineTrace(bool Initial, bool Debug);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	USkeletalMeshComponent* GunMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	USkeletalMeshComponent* GunMesh3P;

	UFUNCTION(BlueprintCallable, Category = "Mesh")
	void UpdateFirstPersonGunMeshFOV(float FOV);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimSequence* BasePose1P;

	// Gun offset in mesh space
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	FVector PositionOffset = FVector::ZeroVector;
	
	// Gun offset in mesh space
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	FVector GunPivotOffset = FVector::ZeroVector;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	FTransform PointAim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	FTransform EditingOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	FRecoilAnimData RecoilAnimData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	float FireRate = 0.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	int Burst = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	bool bFullAuto = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	bool bBursts = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Animation")
	TSubclassOf<UCameraShakeBase> CameraRecoilShake;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Crosshair")
	UTexture2D* CrosshairTexture;
};