// Copyright Epic Games, Inc. All Rights Reserved.

#include "ffsGameMode.h"
#include "ffsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AffsGameMode::AffsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
