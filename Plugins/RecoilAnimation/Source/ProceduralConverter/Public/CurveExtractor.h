// Designed by Hitman's Store, 2022

#pragma once

#include "CoreMinimal.h"
#include "AnimationModifiers/Public/AnimationModifier.h"
#include "Curves/CurveVector.h"
#include "CurveExtractor.generated.h"

UCLASS(Blueprintable)
class PROCEDURALCONVERTER_API UCurveExtractor : public UAnimationModifier
{
	GENERATED_BODY()

public:
	virtual void OnApply_Implementation(UAnimSequence* AnimationSequence) override;

	void SaveCurve(UPackage* Package, UCurveVector* Curve, const FString& PackagePath);

	/** Bone which will be captured */
	UPROPERTY(EditAnywhere, Category = "Pivot Bone Name")
	FName BoneName;

	/** Name of procedural animation. Note: _Rot and _Loc postfixes are added automatically */
	UPROPERTY(EditAnywhere, Category = "Animation Name", meta = (ToolTip="Semi, Burst or Auto"))
	FName AnimName;

	/** Weapon name */
	UPROPERTY(EditAnywhere, Category = "Gun Name")
	FString WeaponName;

	/** Return bone transform in root bone space */
	FTransform GetComponentBonePose(const TArray<FName>& BoneChain, UAnimSequence* AnimSequence, int Frame);
};