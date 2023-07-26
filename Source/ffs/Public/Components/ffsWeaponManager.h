#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
#include "Components/ActorComponent.h"
#include "ffsAnimInstance.h"
#include "ffsWeaponManager.generated.h"

class AffsWeapon;
class AffsCharacter;

UENUM(BlueprintType)
enum class EFireMode : uint8
{
    SINGLE UMETA(DisplayName = "Single"),
    AUTO UMETA(DisplayName = "Auto"),
    BURST UMETA(DisplayName = "Burst")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FFS_API UffsWeaponManager : public UActorComponent
{
    GENERATED_BODY()

protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

public:    
    UffsWeaponManager();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapons", meta = (AllowPrivateAccess = "true"))
	TArray<TSubclassOf<AffsWeapon>> WeaponInventory;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapons")
	TArray<AffsWeapon *> InitializedWeapons;

    UPROPERTY(Replicated, BlueprintReadWrite, Category = "Weapons")
	int CurrentGunIndex = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
    EFireMode CurrentFireMode;

    UPROPERTY(BlueprintReadWrite, Category = "Weapons")
	AffsWeapon *CurrentWeapon = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	AffsWeapon *GetWeapon() const { return CurrentWeapon; }

    UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage *EquipMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage *UnequipMontage;

    UFUNCTION(BlueprintCallable, Category = "Weapons")
	void InitWeapon(int Index, AffsCharacter* Owner);

	virtual FHitResult FireLineTrace(bool InitialShot, bool Debug);
    void PlayFireAnimation(bool ThirdPerson);
    void PlayWeaponFireFX(UNiagaraSystem *FX, FName SocketName);
	void UpdateAnimInstancePose(UffsAnimInstance *MeshAnimInstance, UAnimSequence *CharacterPose1P, FVector WeaponOffset, FTransform PointAim, FVector PlayerPivotOffset, FVector GunPivotOffset, FTransform EditingOffset);
};