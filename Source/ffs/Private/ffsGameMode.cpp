#include "ffsGameMode.h"
#include "ffsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AffsGameMode::AffsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
