// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputActionValue.h"
#include "GameFramework/SpringArmComponent.h"
#include "ModularGameplayActors/GSCModularCharacter.h"
#include "Components/AGRAnimMasterComponent.h"
#include "RecoilAnimationComponent.h"

#include "ffsCharacter.generated.h"

class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UffsAnimInstance;

UCLASS(config = Game)
class AffsCharacter : public AGSCModularCharacter
{
	GENERATED_BODY()

public:
	AffsCharacter(const FObjectInitializer &ObjectInitializer);

protected:
	// APawn interface
	virtual void BeginPlay();
	virtual void PostInitializeComponents() override;
	// End of APawn interface

	// Pawn mesh: 1st person view (arms; seen only by self)
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent *Mesh1P;

	// Pawn mesh 3p: 3rd person view (body; seen only by others)
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent *Mesh3P;

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

	UPROPERTY()
	UffsAnimInstance *AnimInstance;

public:
	USkeletalMeshComponent *GetMesh1P() const { return Mesh1P; }
	USkeletalMeshComponent *GetMesh3P() const { return Mesh3P; }
	UCameraComponent *GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	URecoilAnimationComponent* GetRecoilAnimation() const { return RecoilAnimation; }

	FCollisionQueryParams GetIgnoreCharacterParams() const;
};
