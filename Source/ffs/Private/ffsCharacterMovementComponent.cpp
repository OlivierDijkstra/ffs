#include "ffsCharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"

#pragma region Saved Move

// Clear the saved move state and the sprinting state
void FSavedMove_Ffs::Clear()
{
    Super::Clear();
    Saved_bWantsToSprint = false;
    Saved_bWantsToSlide = false;
}

// Get the parent's compressed flags and add additional flag for sprinting state
uint8 FSavedMove_Ffs::GetCompressedFlags() const
{
    uint8 Result = Super::GetCompressedFlags();

    if (Saved_bWantsToSprint) Result |= FLAG_Sprint;
    if (Saved_bWantsToSlide) Result |= FLAG_Slide;

    return Result;
}

// Set the move for the character including the additional sprinting state
void FSavedMove_Ffs::SetMoveFor(ACharacter *Character, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData)
{
    Super::SetMoveFor(Character, InDeltaTime, NewAccel, ClientData);

    if (Character)
    {
        if (UffsCharacterMovementComponent* MovementComponent = Cast<UffsCharacterMovementComponent>(Character->GetMovementComponent()))
        {
            Saved_bWantsToSprint = MovementComponent->Safe_bWantsToSprint;
            Saved_bWantsToSlide = MovementComponent->Safe_bWantsToSlide;
        }
    }
}

// Prepare the character's sprinting state for the next move
void FSavedMove_Ffs::PrepMoveFor(ACharacter *Character)
{
    Super::PrepMoveFor(Character);

    if (Character)
    {
        if (UffsCharacterMovementComponent* MovementComponent = Cast<UffsCharacterMovementComponent>(Character->GetMovementComponent()))
        {
            MovementComponent->Safe_bWantsToSprint = Saved_bWantsToSprint;
            MovementComponent->Safe_bWantsToSlide = Saved_bWantsToSlide;
        }
    }
}

#pragma endregion

#pragma region Client Network Prediction Data

// Allocate a new saved move of the type that can save additional properties related to sprinting
FSavedMovePtr FNetworkPredictionData_Client_Ffs::AllocateNewMove()
{
    return FSavedMovePtr(new FSavedMove_Ffs());
}

// Determine if this saved move can be combined with a new one, with an additional check for sprinting state
bool FSavedMove_Ffs::CanCombineWith(const FSavedMovePtr &NewMove, ACharacter *InCharacter, float MaxDelta) const
{
    if (Saved_bWantsToSprint != ((FSavedMove_Ffs*)&NewMove)->Saved_bWantsToSprint)
    {
        return false;
    }

    // TODO: Could be useful
    // if (Saved_bWantsToSlide != ((FSavedMove_Ffs*)&NewMove)->Saved_bWantsToSlide)
    // {
    //     return false;
    // }

    return Super::CanCombineWith(NewMove, InCharacter, MaxDelta);
}

#pragma endregion

UffsCharacterMovementComponent::UffsCharacterMovementComponent()
{
}

#pragma region CMC

void UffsCharacterMovementComponent::InitializeComponent()
{
    Super::InitializeComponent();

    ffsCharacterOwner = Cast<AffsCharacter>(GetOwner());
}

void UffsCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
    Super::UpdateFromCompressedFlags(Flags);

    Safe_bWantsToSprint = (Flags & FSavedMove_Ffs::FLAG_Sprint) != 0;
    Safe_bWantsToSlide = (Flags & FSavedMove_Ffs::FLAG_Slide) != 0;
}

FNetworkPredictionData_Client *UffsCharacterMovementComponent::GetPredictionData_Client() const
{
    check(PawnOwner != nullptr);

    // This checks if prediction data exists. If it doesn't, it creates a new one
    if (ClientPredictionData ==  nullptr)
    {
        if (UffsCharacterMovementComponent* MutableThis = const_cast<UffsCharacterMovementComponent *>(this))
        {
            MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_Ffs(*this);
            // TODO: Look into this
            MutableThis->ClientPredictionData->MaxSmoothNetUpdateDist = 92.f;
		    MutableThis->ClientPredictionData->NoSmoothNetUpdateDist = 140.f; 
        }
    }

    return ClientPredictionData;
}

float UffsCharacterMovementComponent::GetMaxSpeed() const
{
    if (IsMovementMode(MOVE_Walking) && Safe_bWantsToSprint && !IsCrouching()) return MaxSprintSpeed;

    if (MovementMode != MOVE_Custom) return Super::GetMaxSpeed();

    switch (CustomMovementMode)
	{
	case CMOVE_Sliding:
		return MaxSlideSpeed;
	default:
		UE_LOG(LogTemp, Fatal, TEXT("Invalid Movement Mode"))
		return -1.f;
	}
}

float UffsCharacterMovementComponent::GetMaxBrakingDeceleration() const
{
	if (MovementMode != MOVE_Custom) return Super::GetMaxBrakingDeceleration();

	switch (CustomMovementMode)
	{
	case CMOVE_Sliding:
		return BrakingDecelerationSliding;
	default:
		UE_LOG(LogTemp, Fatal, TEXT("Invalid Movement Mode"))
		return -1.f;
	}
}

// Overwrite the default IsMovingOnGround to also account for the sliding movement mode
bool UffsCharacterMovementComponent::IsMovingOnGround() const
{
    return Super::IsMovingOnGround() || IsCustomMovementMode(CMOVE_Sliding);
}

void UffsCharacterMovementComponent::PhysCustom(float deltaTime, int32 Iterations)
{
    Super::PhysCustom(deltaTime, Iterations);

    switch (CustomMovementMode)
    {
    case CMOVE_Sliding:
        PhysSliding(deltaTime, Iterations);
        break;
    default:
        UE_LOG(LogTemp, Fatal, TEXT("UffsCharacterMovementComponent::PhysCustom: Unknown CustomMovementMode"));
        break;
    }
}

#pragma endregion

#pragma region Sliding

bool UffsCharacterMovementComponent::GetSlideSurface(FHitResult& OutHit) const
{
    FVector Start = UpdatedComponent->GetComponentLocation();
    FVector End = Start + CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * 2.f * FVector::DownVector;
    FName ProfileName = FName(TEXT("BlockAll"));
    return GetWorld()->LineTraceSingleByProfile(OutHit, Start, End, ProfileName, ffsCharacterOwner->GetIgnoreCharacterParams());
}

void UffsCharacterMovementComponent::EnterSlide()
{
    // Piggy back of the crouching mechanics to handle the capsule size
    bWantsToCrouch = true;
    Velocity += Velocity.GetSafeNormal2D() * SlideEnterImpulse;
    SetMovementMode(MOVE_Custom, CMOVE_Sliding);
}

void UffsCharacterMovementComponent::ExitSlide()
{
    bWantsToCrouch = false;

    FQuat NewRotation = FRotationMatrix::MakeFromXZ(UpdatedComponent->GetForwardVector().GetSafeNormal2D(), FVector::UpVector).ToQuat();
    FHitResult Hit;
    SafeMoveUpdatedComponent(FVector::ZeroVector, NewRotation, true, Hit);
    SetMovementMode(MOVE_Walking);
}

void UffsCharacterMovementComponent::PhysSliding(float deltaTime, int32 Iterations)
{
    // Some default character movement component code. Don't do any physics stuff
    // when the delta time is too small
    if (deltaTime < MIN_TICK_TIME)
    {
        return;
    }

    // Probably not needed as Root Motion is not really used in sliding
    RestorePreAdditiveRootMotionVelocity();

    FHitResult SurfaceHit;
    // If we can't get a slide surface or the velocity is too low, exit the sliding movement mode
    // if (!GetSlideSurface(SurfaceHit) || Velocity.SizeSquared() < pow(MinSlideSpeed, 2.f))
    // {
    //     ExitSlide();
    //     // Start new physics as we are no longer sliding.
    //     StartNewPhysics(deltaTime, Iterations);
    //     // Print out to screen that we exited the slide
    //     // GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("C++ Exited Slide"));
    //     return;
    // }

    // Surface Gravity
    Velocity += SlideGravityForce * FVector::DownVector * deltaTime;
    // GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("C++ Slide Velocity: %f"), Velocity.Size()));

    // Strafe
    // Only allow acceleration to be left or right.
    // if (FMath::Abs(FVector::DotProduct(Acceleration.GetSafeNormal(), UpdatedComponent->GetRightVector())) > .5)
    // {
    //     Acceleration = Acceleration.ProjectOnTo(UpdatedComponent->GetRightVector());
    // }
    // else
    // {
    //     Acceleration = FVector::ZeroVector;
    // }

    Acceleration = FVector::ZeroVector;

    // Calculate Velocity
    // More boilerplate for root motion handling but could be useful later
    if (!HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
    {
        CalcVelocity(deltaTime, SlideFrictionFactor, true, GetMaxBrakingDeceleration());
    }
    ApplyRootMotionToVelocity(deltaTime);

    // Perform Move
    Iterations++;
    bJustTeleported = false;

    FVector OldLocation = UpdatedComponent->GetComponentLocation();
    FQuat OldRotation = UpdatedComponent->GetComponentRotation().Quaternion();
    FHitResult Hit(1.f);
    FVector Adjusted = Velocity * deltaTime; // x = v * dt
    FVector VelocityPlaneDirection = FVector::VectorPlaneProject(Velocity, SurfaceHit.Normal).GetSafeNormal();
    FQuat NewRotation = FRotationMatrix::MakeFromZX(VelocityPlaneDirection, SurfaceHit.Normal).ToQuat();

    // This actually moves the character
    SafeMoveUpdatedComponent(Adjusted, NewRotation, true, Hit);

    // If we hit an object with the slide movement, handle the impact
    if (Hit.Time < 1.f)
    {
        HandleImpact(Hit, deltaTime, Adjusted);
        // Helps with sliding along a surface instead of just stopping
        SlideAlongSurface(Adjusted, (1.f - Hit.Time), Hit.Normal, Hit, true);
    }

    // Recheck if we still have enough speed to slide after the impact, if not, exit the slide movement mode
    // FHitResult NewSurfaceHit;
    // if (!GetSlideSurface(NewSurfaceHit) || Velocity.SizeSquared() < pow(MinSlideSpeed, 2.f))
    // {
    //     ExitSlide();
    // }

    // Update Outgoing Velocity & Acceleration
    if (!bJustTeleported && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
    {
        Velocity = (UpdatedComponent->GetComponentLocation() - OldLocation) / deltaTime; // v = dx / dt
    }
}

#pragma endregion

#pragma region Sprinting

void UffsCharacterMovementComponent::SetSprinting(bool Sprint)
{
    Safe_bWantsToSprint = Sprint;  // Setter for sprinting state
}

void UffsCharacterMovementComponent::SetSliding(bool Slide)
{
    Safe_bWantsToSlide = Slide; // Setter for sliding state

    FHitResult PotentialSlideSurface;
    if (Slide && Velocity.SizeSquared() > pow(MinSlideSpeed, 2.f) && GetSlideSurface(PotentialSlideSurface))
    {
        EnterSlide();
    }
    else if (!Slide)
    {
        ExitSlide();
    }
}

#pragma endregion

#pragma region Interface

bool UffsCharacterMovementComponent::IsCustomMovementMode(ECustomMovementMode InCustomMovementMode) const
{
    return MovementMode == MOVE_Custom && CustomMovementMode == InCustomMovementMode;
}
bool UffsCharacterMovementComponent::IsMovementMode(EMovementMode InMovementMode) const
{
	return InMovementMode == MovementMode;
}

#pragma endregion
