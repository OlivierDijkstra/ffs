// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ffsCharacterMovementComponent.generated.h"

// The main character movement component that extends from UCharacterMovementComponent
UCLASS()
class FFS_API UffsCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	// Default constructor with preset maximum sprint speed
	UffsCharacterMovementComponent();

	// Function overriding the one in the parent class, to update the state of character's sprinting based on received flags
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;

	// Returns the network prediction data specific for this class
	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;

	// Returns the maximum speed the character can have, depending on the sprinting state
	virtual float GetMaxSpeed() const override;

	// Bitfield to track if the character wants to sprint
	uint8 bWantstoSprint : 1;

	// Property defining the maximum sprinting speed
	UPROPERTY(EditDefaultsOnly, Category = "Sprinting")
	float MaxSprintSpeed;

	// BlueprintCallable function allowing to change the sprinting state
	UFUNCTION(BlueprintCallable, Category = "Sprinting")
	void SetSprinting(bool Sprint);	
};

// Class that extends FSavedMove_Character to save additional properties related to sprinting
class FSprintSavedMove_Character : public FSavedMove_Character
{
public:
	// Necessary to get access to parent class's methods
	typedef FSavedMove_Character Super;

	// Overrides the parent's Clear function to also clear the sprinting state
	virtual void Clear() override;

	// Overrides the parent's GetCompressedFlags function to add additional custom flag for sprinting
	virtual uint8 GetCompressedFlags() const override;

	// Overrides the parent's SetMoveFor function to include additional processing for sprinting
	virtual void SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character& ClientData) override;

	// Overrides the parent's PrepMoveFor function to prepare the character's sprinting state for the next move
	virtual void PrepMoveFor(class ACharacter* Character) override;

	// Overrides the parent's CanCombineWith function to add additional check for sprinting state
	virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const override;

	// A bitfield to store the sprinting state
	uint8 bSavedWantsToSprint : 1;
};

// Class that extends FNetworkPredictionData_Client_Character to allocate new moves that save additional properties related to sprinting
class FSprintNetworkPredictionData_Client_Character : public FNetworkPredictionData_Client_Character
{
public:
	// Necessary to get access to parent class's methods
	typedef FNetworkPredictionData_Client_Character Super;

	// Constructor for this class that calls the parent's constructor
	FSprintNetworkPredictionData_Client_Character(const UCharacterMovementComponent& CharacterMovementComponentName) : Super(CharacterMovementComponentName) {}

	// Overrides the parent's AllocateNewMove function to allocate a new move of the type that can save additional properties related to sprinting
	virtual FSavedMovePtr AllocateNewMove() override;
};