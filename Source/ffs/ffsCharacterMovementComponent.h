#pragma once

#include "CoreMinimal.h"
#include "ffsCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ffsCharacterMovementComponent.generated.h"

UENUM(BlueprintType)
enum ECustomMovementMode
{
	CMOVE_None 				UMETA(Hidden),
	CMOVE_Sliding 			UMETA(DisplayName = "Sliding"),
	CMOVE_MAX 				UMETA(Hidden),
};

UCLASS()
class FFS_API UffsCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	// Parameters

		// Sprinting
		UPROPERTY(EditDefaultsOnly, Category = "Sprinting") float MaxSprintSpeed=800.f;

		// Sliding
		UPROPERTY(EditDefaultsOnly, Category = "Sliding") float MinSlideSpeed=400.f;
		UPROPERTY(EditDefaultsOnly, Category = "Sliding") float MaxSlideSpeed=800.f;
		UPROPERTY(EditDefaultsOnly, Category = "Sliding") float SlideEnterImpulse=500.f;
		UPROPERTY(EditDefaultsOnly, Category = "Sliding") float SlideGravityForce=4000.f;
		UPROPERTY(EditDefaultsOnly, Category = "Sliding") float SlideFrictionFactor=.06f;
		UPROPERTY(EditDefaultsOnly, Category = "Sliding") float BrakingDecelerationSliding=1000.f;

	// Transient
		UPROPERTY(Transient) AffsCharacter* ffsCharacterOwner;

		// Flags
		uint8 Safe_bWantsToSprint : 1;
		uint8 Safe_bWantsToSlide : 1;

	int CorrectionCount=0;

public:
	UffsCharacterMovementComponent();

// Character movement component overrides
public:
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;
	virtual void OnClientCorrectionReceived(FNetworkPredictionData_Client_Character& ClientData, float TimeStamp, FVector NewLocation, FVector NewVelocity, UPrimitiveComponent* NewBase, FName NewBaseBoneName, bool bHasBase, bool bBaseRelativePosition, uint8 ServerMovementMode) override;
	virtual FNetworkPredictionData_Client* GetPredictionData_Client() const override;
	virtual bool IsMovingOnGround() const override;
	virtual float GetMaxSpeed() const override;
	virtual float GetMaxBrakingDeceleration() const override;

// Interface
public:
	UFUNCTION(BlueprintPure) bool IsCustomMovementMode(ECustomMovementMode InCustomMovementMode) const;
	UFUNCTION(BlueprintPure) bool IsMovementMode(EMovementMode InMovementMode) const;


// Actor Component
protected:
	virtual void InitializeComponent() override;
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;

// Sprinting
public:	
	UFUNCTION(BlueprintCallable, Category = "Sprinting")
	void SetSprinting(bool Sprint);

// Sliding
public: 
	UFUNCTION(BlueprintCallable, Category = "Sliding")
	void SetSliding(bool Slide);

private:
	void EnterSlide();
	void ExitSlide();
	// Physics function for the slide movement mode. Every custom movement mode has its own physics function
	// to define how the character moves in that mode. Usually Phys<ModeName>.
	void PhysSliding(float deltaTime, int32 Iterations);
	bool GetSlideSurface(FHitResult& OutHit) const;
};

// Class that extends FSavedMove_Character to save additional properties
class FSavedMove_Ffs : public FSavedMove_Character
{
public:
	enum CompressedFlags
	{
		FLAG_Sprint			= 0x10,
		FLAG_Slide			= 0x20,
		FLAG_Custom_2		= 0x40,
		FLAG_Custom_3		= 0x80,
	};

	// Necessary to get access to parent class's methods
	typedef FSavedMove_Character Super;

	// Flags
	uint8 Saved_bWantsToSprint : 1;
	uint8 Saved_bWantsToSlide : 1;

	virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const override;
	virtual void Clear() override;
	virtual uint8 GetCompressedFlags() const override;
	virtual void SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character& ClientData) override;
	virtual void PrepMoveFor(ACharacter* Character) override;
};

// Class that extends FNetworkPredictionData_Client_Character to allocate new moves that save additional properties
class FNetworkPredictionData_Client_Ffs : public FNetworkPredictionData_Client_Character
{
public:
	// Necessary to get access to parent class's methods
	typedef FNetworkPredictionData_Client_Character Super;

	// Constructor for this class that calls the parent's constructor
	FNetworkPredictionData_Client_Ffs(const UCharacterMovementComponent& CharacterMovementComponentName) : Super(CharacterMovementComponentName) {}

	// Overrides the parent's AllocateNewMove function to allocate a new move of the type that can save additional properties
	virtual FSavedMovePtr AllocateNewMove() override;
};