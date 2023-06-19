// Designed by Hitman's Store 2022

#pragma once

#include "CoreMinimal.h"
#include "Animation/AGRCoreAnimInstance.h"
#include "Animations/GSCNativeAnimInstanceInterface.h"
#include "RecoilAnimationComponent.h"
#include "FfsAnimInstance.generated.h"

class UAbilitySystemComponent;

UCLASS(Blueprintable)
class FFS_API UffsAnimInstance : public UAGRCoreAnimInstance, public IGSCNativeAnimInstanceInterface
{
	GENERATED_BODY()

protected:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// GASCompanion required code to get GameplayTags from AbilitySystemComponent
	UPROPERTY(EditDefaultsOnly, Category = "GameplayTags")
	FGameplayTagBlueprintPropertyMap GameplayTagPropertyMap;

	virtual void InitializeWithAbilitySystem(UAbilitySystemComponent* ASC) override
	{
		GameplayTagPropertyMap.Initialize(this, ASC);
	}
	
public:
	UPROPERTY(BlueprintReadOnly, Category = "AGR|Components")
	URecoilAnimationComponent* RecoilAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pose")
	UAnimSequence* CharacterPose1P;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pose")
	UAnimSequence* CharacterPose3P;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pose")
	FVector WeaponOffset;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pose")
	FTransform PointAim;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pose")
	FVector PlayerPivotOffset;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pose")
	FVector GunPivotOffset;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pose")
	FTransform EditingOffset;
};