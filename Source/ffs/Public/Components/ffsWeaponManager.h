#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ffsWeaponManager.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FFS_API UffsWeaponManager : public UActorComponent
{
    GENERATED_BODY()

public:    
    UffsWeaponManager();

    // TODO: Add your function declarations here
};
