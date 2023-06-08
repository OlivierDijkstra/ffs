// Fill out your copyright notice in the Description page of Project Settings.


#include "ffsCharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"

UffsCharacterMovementComponent::UffsCharacterMovementComponent()
{
}

bool UffsCharacterMovementComponent::IsCustomMovementMode(ECustomMovementMode InCustomMovementMode) const
{
    return MovementMode == MOVE_Custom && CustomMovementMode == InCustomMovementMode;
}

bool UffsCharacterMovementComponent::GetSlideSurface(FHitResult& OutHit) const
{
    FVector Start = UpdatedComponent->GetComponentLocation();
    FVector End = Start + CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight() * 2.f * FVector::DownVector;
    FName ProfileName = FName(TEXT("BlockAll"));
    return GetWorld()->LineTraceSingleByProfile(OutHit, Start, End, ProfileName, ffsCharacterOwner->GetIgnoreCharacterParams());
}

// Overwrite the default IsMovingOnGround to also account for the sliding movement mode
bool UffsCharacterMovementComponent::IsMovingOnGround() const
{
    return Super::IsMovingOnGround() || IsCustomMovementMode(CMOVE_Sliding);
}

void UffsCharacterMovementComponent::InitializeComponent()
{
    Super::InitializeComponent();

    ffsCharacterOwner = Cast<AffsCharacter>(GetOwner());
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

void UffsCharacterMovementComponent::EnterSlide()
{
    // Piggy back of the crouching mechanics to handle the capsule size
    bWantsToCrouch = true;
    Velocity += Velocity.GetSafeNormal2D() * Slide_EnterImpulse;
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
    if (!GetSlideSurface(SurfaceHit) || Velocity.SizeSquared() < pow(Slide_MinSpeed, 2.f))
    {
        ExitSlide();
        // Start new physics as we are no longer sliding.
        StartNewPhysics(deltaTime, Iterations);
        return;
    }

    // Surface Gravity
    Velocity += Slide_GravityForce * FVector::DownVector * deltaTime;

    // Strafe
    // Only allow acceleration to be left or right.
    if (FMath::Abs(FVector::DotProduct(Acceleration.GetSafeNormal(), UpdatedComponent->GetRightVector())) > .5f)
    {
        Acceleration = Acceleration.ProjectOnTo(UpdatedComponent->GetRightVector());
    }
    else
    {
        Acceleration = FVector::ZeroVector;
    }

    // Calculate Velocity
    // More boilerplate for root motion handling but could be useful later
    if (!HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
    {
        CalcVelocity(deltaTime, Slide_Friction, true, GetMaxBrakingDeceleration());
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
    FHitResult NewSurfaceHit;
    if (!GetSlideSurface(NewSurfaceHit) || Velocity.SizeSquared() < pow(Slide_MinSpeed, 2.f))
    {
        ExitSlide();
    }

    // Update Outgoing Velocity & Acceleration
    if (!bJustTeleported && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
    {
        Velocity = (UpdatedComponent->GetComponentLocation() - OldLocation) / deltaTime; // v = dx / dt
    }
}

void UffsCharacterMovementComponent::SetSprinting(bool Sprint)
{
    Safe_bWantstoSprint = Sprint;  // Setter for sprinting state
}

void UffsCharacterMovementComponent::SetSliding(bool Slide)
{
    Safe_bWantsToSlide = Slide; // Setter for sliding state

    FHitResult PotentialSlideSurface;
    if (Slide && Velocity.SizeSquared() > pow(Slide_MinSpeed, 2.f) && GetSlideSurface(PotentialSlideSurface))
    {
        EnterSlide();
    }
    else if (!Slide)
    {
        ExitSlide();
    }
}

void UffsCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
    Super::UpdateFromCompressedFlags(Flags);
    // Unpack sprinting state from compressed flags
    Safe_bWantstoSprint = (Flags & FSavedMove_Character::FLAG_Custom_0) != 0;
    Safe_bWantsToSlide = (Flags & FSavedMove_Character::FLAG_Custom_1) != 0;
}

FNetworkPredictionData_Client *UffsCharacterMovementComponent::GetPredictionData_Client() const
{
    // This checks if prediction data exists. If it doesn't, it creates a new one
    if (!ClientPredictionData)
    {
        if (UffsCharacterMovementComponent* TempComponent = const_cast<UffsCharacterMovementComponent *>(this))
        {
            TempComponent->ClientPredictionData = new FSprintNetworkPredictionData_Client_Character(*this);
        }
    }

    return ClientPredictionData;
}

float UffsCharacterMovementComponent::GetMaxSpeed() const
{
    // If sprinting, return sprinting speed. Else, call parent's GetMaxSpeed() function
    float Speed = Super::GetMaxSpeed();

    if (Safe_bWantstoSprint)
    {
        Speed = MaxSprintSpeed;
    }

    return Speed;
}

// Clear the saved move state and the sprinting state
void FSprintSavedMove_Character::Clear()
{
    Super::Clear();
    Saved_bWantsToSprint = false;
    Saved_bWantsToSlide = false;
}

// Get the parent's compressed flags and add additional flag for sprinting state
uint8 FSprintSavedMove_Character::GetCompressedFlags() const
{
    uint8 Result = Super::GetCompressedFlags();

    if (Saved_bWantsToSprint)
    {
        Result |= FLAG_Custom_0;
    }

    if (Saved_bWantsToSlide)
    {
        Result |= FLAG_Custom_1;
    }

    return Result;
}

// Set the move for the character including the additional sprinting state
void FSprintSavedMove_Character::SetMoveFor(ACharacter *Character, float InDeltaTime, FVector const& NewAccel, FNetworkPredictionData_Client_Character& ClientData)
{
    Super::SetMoveFor(Character, InDeltaTime, NewAccel, ClientData);

    if (Character)
    {
        if (UffsCharacterMovementComponent* MovementComponent = Cast<UffsCharacterMovementComponent>(Character->GetMovementComponent()))
        {
            Saved_bWantsToSprint = MovementComponent->Safe_bWantstoSprint;
            Saved_bWantsToSlide = MovementComponent->Safe_bWantsToSlide;
        }
    }
}

// Prepare the character's sprinting state for the next move
void FSprintSavedMove_Character::PrepMoveFor(ACharacter *Character)
{
    Super::PrepMoveFor(Character);

    if (Character)
    {
        if (UffsCharacterMovementComponent* MovementComponent = Cast<UffsCharacterMovementComponent>(Character->GetMovementComponent()))
        {
            MovementComponent->Safe_bWantstoSprint = Saved_bWantsToSprint;
            MovementComponent->Safe_bWantsToSlide = Saved_bWantsToSlide;
        }
    }
}

// Determine if this saved move can be combined with a new one, with an additional check for sprinting state
bool FSprintSavedMove_Character::CanCombineWith(const FSavedMovePtr &NewMove, ACharacter *InCharacter, float MaxDelta) const
{
    if (Saved_bWantsToSprint != ((FSprintSavedMove_Character*)&NewMove)->Saved_bWantsToSprint)
    {
        return false;
    }

    // TODO: Could be useful
    // if (Saved_bWantsToSlide != ((FSprintSavedMove_Character*)&NewMove)->Saved_bWantsToSlide)
    // {
    //     return false;
    // }

    return Super::CanCombineWith(NewMove, InCharacter, MaxDelta);
}

// Allocate a new saved move of the type that can save additional properties related to sprinting
FSavedMovePtr FSprintNetworkPredictionData_Client_Character::AllocateNewMove()
{
    return FSavedMovePtr(new FSprintSavedMove_Character());
}
