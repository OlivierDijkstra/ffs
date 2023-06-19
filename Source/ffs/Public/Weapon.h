// Designed by Hitman's Store 2022

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RecoilAnimationComponent.h"
#include "Weapon.generated.h"

UCLASS(BlueprintType)
class FFS_API AWeapon : public AActor
{
	GENERATED_BODY()
	
	AWeapon();

	UPROPERTY()
	USceneComponent* Pivot;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* FireMontage;

public:
	void PlayFireAnim() const;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	USkeletalMeshComponent* GunMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	USkeletalMeshComponent* GunMesh3P;
	
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimSequence* BasePose;

	// Gun offset in mesh space
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	FVector PositionOffset = FVector::ZeroVector;
	
	// Gun offset in mesh space
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	FVector GunPivotOffset = FVector::ZeroVector;
	
	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	FTransform PointAim;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	FTransform EditingOffset;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	FRecoilAnimData RecoilAnimData;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	float FireRate = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	int Burst = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	bool bFullAuto = false;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	bool bBursts = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera Animation")
	TSubclassOf<UCameraShakeBase> CameraRecoilShake;
};