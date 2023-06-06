// Fill out your copyright notice in the Description page of Project Settings.


#include "ffsCharacterMovementComponent.h"
#include "GameFramework/Character.h"

UffsCharacterMovementComponent::UffsCharacterMovementComponent()
{
    // MaxSprintSpeed = 600.0f;  // Default sprinting speed
}

void UffsCharacterMovementComponent::SetSprinting(bool Sprint)
{
    bWantstoSprint = Sprint;  // Setter for sprinting state
}

void UffsCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
    Super::UpdateFromCompressedFlags(Flags);
    // Unpack sprinting state from compressed flags
    bWantstoSprint = (Flags & FSavedMove_Character::FLAG_Custom_0) != 0;
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

    if (bWantstoSprint)
    {
        Speed = MaxSprintSpeed;
    }

    return Speed;
}

// Clear the saved move state and the sprinting state
void FSprintSavedMove_Character::Clear()
{
    Super::Clear();
    bSavedWantsToSprint = false;
}

// Get the parent's compressed flags and add additional flag for sprinting state
uint8 FSprintSavedMove_Character::GetCompressedFlags() const
{
    uint8 Result = Super::GetCompressedFlags();

    if (bSavedWantsToSprint)
    {
        Result |= FLAG_Custom_0;
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
            bSavedWantsToSprint = MovementComponent->bWantstoSprint;
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
            MovementComponent->bWantstoSprint = bSavedWantsToSprint;
        }
    }
}

// Determine if this saved move can be combined with a new one, with an additional check for sprinting state
bool FSprintSavedMove_Character::CanCombineWith(const FSavedMovePtr &NewMove, ACharacter *InCharacter, float MaxDelta) const
{
    if (bSavedWantsToSprint != ((FSprintSavedMove_Character*)&NewMove)->bSavedWantsToSprint)
    {
        return false;
    }

    return Super::CanCombineWith(NewMove, InCharacter, MaxDelta);
}

// Allocate a new saved move of the type that can save additional properties related to sprinting
FSavedMovePtr FSprintNetworkPredictionData_Client_Character::AllocateNewMove()
{
    return FSavedMovePtr(new FSprintSavedMove_Character());
}
