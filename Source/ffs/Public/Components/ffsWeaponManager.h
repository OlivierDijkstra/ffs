#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
#include "Components/ActorComponent.h"
#include "ffsAnimInstance.h"
#include "ffsWeaponManager.generated.h"

class USkeletalMeshComponent;
class AffsWeapon;
class AffsCharacter;

UENUM(BlueprintType)
enum class EFireMode : uint8
{
    SINGLE UMETA(DisplayName = "Single"),
    AUTO UMETA(DisplayName = "Auto"),
    BURST UMETA(DisplayName = "Burst")
};
// @
UENUM(BlueprintType)
enum class EEquippedWeapon : uint8
{
    PRIMARY UMETA(DisplayName = "Primary"),
    SECONDARY UMETA(DisplayName = "Secondary"),
    NONE UMETA(DisplayName = "None")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FFS_API UffsWeaponManager : public UActorComponent
{
    GENERATED_BODY()

protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

public:    
    UffsWeaponManager();

    UPROPERTY(Replicated, BlueprintReadWrite, Category = "Weapons")
	AffsWeapon *CurrentWeapon = nullptr;

    UPROPERTY(Replicated, BlueprintReadWrite, Category = "Weapons")
    int32 CurrentWeaponIndex = 0;

    UPROPERTY(Replicated, BlueprintReadOnly, Category = "Weapons")
    TArray<AffsWeapon*> Weapons;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
	UAnimMontage *EquipMontage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
	UAnimMontage *UnequipMontage;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapons")
    TSubclassOf<AffsWeapon> SpawnPrimaryWeaponClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapons")
    TSubclassOf<AffsWeapon> SpawnSecondaryWeaponClass;
    // @
    UPROPERTY(BlueprintReadWrite, Category = "Weapons")
    AffsWeapon *PrimaryWeapon = nullptr;
    // @
    UPROPERTY(BlueprintReadWrite, Category = "Weapons")
    AffsWeapon *SecondaryWeapon = nullptr;
    // @
    UPROPERTY(Replicated, BlueprintReadWrite, Category = "Weapons")
    EEquippedWeapon EquippedWeaponType = EEquippedWeapon::NONE;

    UFUNCTION(BlueprintCallable, Category = "Weapons")
    AffsWeapon* SpawnWeaponOnPlayer(AffsCharacter *Player, TSubclassOf<AffsWeapon> WeaponClass);

    UFUNCTION(BlueprintCallable, Category = "Weapons")
    void EquipWeaponOnPlayer(AffsCharacter *Player, AffsWeapon *Weapon);

    UFUNCTION(BlueprintCallable, Category = "Weapons")
    void IncrementCurrentWeaponIndex();
    // @
    UFUNCTION(BlueprintCallable, Category = "Weapons")
    void EquipPrimaryWeapon(AffsCharacter *Player);
    // @
    UFUNCTION(BlueprintCallable, Category = "Weapons")
    void EquipSecondaryWeapon(AffsCharacter *Player);

	virtual FHitResult FireLineTrace(bool InitialShot, bool Debug);
    // @
    void SwitchWeaponVisibility(EEquippedWeapon WeaponType);
    void PlayFireAnimation(bool ThirdPerson);
    void PlayWeaponFireFX(UNiagaraSystem *FX, FName SocketName, bool ThirdPerson);
	void UpdateAnimInstancePose(UffsAnimInstance *MeshAnimInstance, UAnimSequence *CharacterPose1P, FVector WeaponOffset, FTransform PointAim, FVector PlayerPivotOffset, FVector GunPivotOffset, FTransform EditingOffset);
};