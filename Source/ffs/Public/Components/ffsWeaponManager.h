#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ffsWeaponManager.generated.h"

class AffsWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FFS_API UffsWeaponManager : public UActorComponent
{
    GENERATED_BODY()

public:    
    UffsWeaponManager();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapons", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<AffsWeapon>> WeaponInventory;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapons")
	TArray<AffsWeapon *> InitializedWeapons;
};