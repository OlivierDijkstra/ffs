// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ffsCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ffsCharacterMovementComponent.generated.h"

UENUM(BlueprintType)
enum ECustomMovementMode
{
	CMOVE_None UMETA(Hidden),
	CMOVE_Sprinting UMETA(DisplayName = "Sprinting"),
	CMOVE_Sliding UMETA(DisplayName = "Sliding"),
	CMOVE_MAX UMETA(Hidden),
};

// The main character movement component that extends from UCharacterMovementComponent
UCLASS()
class FFS_API UffsCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

	UPROPERTY(Transient) AffsCharacter* ffsCharacterOwner;

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
	uint8 Safe_bWantstoSprint : 1;
	uint8 Safe_bWantsToSlide : 1;

	// Property defining the maximum sprinting speed
	UPROPERTY(EditDefaultsOnly, Category = "Sprinting")
	float MaxSprintSpeed;

	// BlueprintCallable function allowing to change the sprinting state
	UFUNCTION(BlueprintCallable, Category = "Sprinting")
	void SetSprinting(bool Sprint);	
	// BlueprintPure function allowing to check the Sliding state
	UFUNCTION(BlueprintCallable, Category = "Sliding")
	void SetSliding(bool Slide);

	// Function to check if the character is in a specific custom movement mode
	UFUNCTION(BlueprintPure) bool IsCustomMovementMode(ECustomMovementMode InCustomMovementMode) const;

	// Minimum speed required to enter the sliding movement mode, will exit the sliding mode if the speed drops below this value
	// TODO: Update to crouch speed
	UPROPERTY(EditDefaultsOnly, Category = "Sliding")
	float Slide_MinSpeed=350.f;
	// Boost velocity when entering the sliding movement mode
	UPROPERTY(EditDefaultsOnly, Category = "Sliding")
	float Slide_EnterImpulse=500.f;
	// Amount of force applied to keep the character on the ground while sliding
	// Also affects how the slope affects the character's speed
	UPROPERTY(EditDefaultsOnly, Category = "Sliding")
	float Slide_GravityForce=5000.f;
	// How fast you lose velocity while sliding
	UPROPERTY(EditDefaultsOnly, Category = "Sliding")
	float Slide_Friction=1.3f;

public:
	virtual bool IsMovingOnGround() const override;

protected:
	virtual void InitializeComponent() override;
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;

private:
	void EnterSlide();
	void ExitSlide();
	// Physics function for the slide movement mode. Every custom movement mode has its own physics function
	// to define how the character moves in that mode. Usually Phys<ModeName>.
	void PhysSliding(float deltaTime, int32 Iterations);
	bool GetSlideSurface(FHitResult& OutHit) const;
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
	uint8 Saved_bWantsToSprint : 1;
	uint8 Saved_bWantsToSlide : 1;
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