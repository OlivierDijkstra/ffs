﻿#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RecoilAnimationComponent.h"
#include "Weapon.generated.h"

USTRUCT(BlueprintType)
struct FFireLineTraceResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    ACharacter* HitCharacter;

    UPROPERTY(BlueprintReadOnly)
    AActor* HitActor;
};


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
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void PlayFireAnim() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	USkeletalMeshComponent* GunMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mesh")
	USkeletalMeshComponent* GunMesh3P;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimSequence* BasePose1P;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	UAnimSequence* BasePose3P;

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float WeaponRange = 1000.f; // Default 1000 units range

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Firing")
	float WeaponSpread = 0.1f; // Default 10% spread

	UFUNCTION(BlueprintCallable, Category = "Animation")
	FFireLineTraceResult FireLineTrace(bool Initial, bool Debug);
};