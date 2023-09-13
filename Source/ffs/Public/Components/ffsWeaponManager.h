#pragma once

#include "CoreMinimal.h"
#include "NiagaraSystem.h"
#include "Components/ActorComponent.h"
#include "ffsAnimInstance.h"
#include "ffsWeaponManager.generated.h"

class USkeletalMeshComponent;
class AffsWeapon;
class AffsCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FComponentCustomStartSignature);

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

    UPROPERTY(ReplicatedUsing = OnRep_Weapons, BlueprintReadOnly, Category = "Weapons")
    TArray<AffsWeapon*> Weapons;

    UFUNCTION()
    void OnRep_Weapons();

    UPROPERTY(ReplicatedUsing = OnRep_CurrentWeapon, BlueprintReadWrite, Category = "Weapons")
	AffsWeapon *CurrentWeapon = nullptr;

    UFUNCTION()
    void OnRep_CurrentWeapon();

    UPROPERTY(BlueprintAssignable, Category = "Custom")
    FComponentCustomStartSignature OnWeaponEquipped;

    UPROPERTY(Replicated, BlueprintReadWrite, Category = "Weapons")
    int32 CurrentWeaponIndex = 0;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
	UAnimMontage *EquipMontage;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Animation")
	UAnimMontage *UnequipMontage;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapons")
    TSubclassOf<AffsWeapon> SpawnPrimaryWeaponClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapons")
    TSubclassOf<AffsWeapon> SpawnSecondaryWeaponClass;

    UFUNCTION(BlueprintCallable, Category = "Weapons")
    AffsWeapon* SpawnWeaponOnPlayer(AffsCharacter *Player, TSubclassOf<AffsWeapon> WeaponClass);
    
    UFUNCTION(BlueprintCallable, Category = "Weapons")
    int32 IncrementCurrentWeaponIndex();

    UFUNCTION(BlueprintCallable, Category = "Weapons")
    void NextWeapon();

    UPROPERTY(EditDefaultsOnly, Category = "Weapons")
    float DropImpulse = 1000.0f;

    UFUNCTION(BlueprintCallable, Category = "Weapons")
    void DropWeapon();
    UFUNCTION(Server, Reliable)
    void Server_DropWeapon(APawn *Owner);
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_DropWeapon(AffsWeapon *Weapon);

    UFUNCTION(BlueprintCallable, Category = "Weapons")
    void EquipWeapon(AffsWeapon *Weapon);
    UFUNCTION(Server, Reliable)
    void Server_EquipWeapon(AffsWeapon *Weapon);

    void PlayFireAnimation(bool ThirdPerson);
    void PlayWeaponFireFX(UNiagaraSystem *FX, FName SocketName, bool ThirdPerson);
    void UpdateAnimInstancePose(UffsAnimInstance *MeshAnimInstance, UAnimSequence *CharacterPose1P, FVector WeaponOffset, FTransform PointAim, FVector PlayerPivotOffset, FVector GunPivotOffset, FTransform EditingOffset);
};