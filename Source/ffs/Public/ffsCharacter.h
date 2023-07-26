#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "GameFramework/SpringArmComponent.h"

#include "ModularGameplayActors/GSCModularCharacter.h"
#include "Components/AGRAnimMasterComponent.h"
#include "RecoilAnimationComponent.h"

#include "Components/ffsWeaponManager.h"
#include "ffsAnimInstance.h"

#include "ffsCharacter.generated.h"

class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class AffsWeapon;

UCLASS(config = Game)
class AffsCharacter : public AGSCModularCharacter
{
	GENERATED_BODY()

public:
	AffsCharacter(const FObjectInitializer &ObjectInitializer);

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	FDelegateHandle HealthChangedDelegateHandle;

    void OnHealthChanged(const FOnAttributeChangeData& Data);
    void Die();

    UFUNCTION(Server, Reliable)
    void ServerRagdoll();
    virtual void ServerRagdoll_Implementation();

    UFUNCTION(NetMulticast, Reliable)
    void MulticastRagdoll();
    virtual void MulticastRagdoll_Implementation();

	UFUNCTION(BlueprintCallable)
    void Ragdoll();

	UFUNCTION(BlueprintCallable)
	UffsAnimInstance *GetAnimInstance1P() const { return Cast<UffsAnimInstance>(Mesh1P->GetAnimInstance()); }

	UFUNCTION(BlueprintCallable)
	UffsAnimInstance *GetAnimInstance3P() const { return Cast<UffsAnimInstance>(Mesh3P->GetAnimInstance()); }

	// First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent *FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent *CameraBoom;

	// Procudueral Recoil Animation
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Recoil Animation", meta = (AllowPrivateAccess = "true"))
	URecoilAnimationComponent *RecoilAnimation;

	// AGRPRO
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	UAGRAnimMasterComponent *AnimMasterComponent;

	// Weapon Manager
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
    UffsWeaponManager* WeaponManager;

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void EquipWeapon();

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void ChangeWeapon();

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	virtual FHitResult FireWeapon(bool InitialShot, bool Debug);

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void PlayFireAnimation();
	UFUNCTION(Server, Reliable, Category = "Net")
	void Server_PlayFireAnimation();
	UFUNCTION(NetMulticast, Reliable, Category = "Net")
	void Multicast_PlayFireAnimation();

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void PlayWeaponFireFX(UNiagaraSystem *FX, FName SocketName);
	UFUNCTION(Server, Reliable, Category = "Net")
	void Server_PlayWeaponFireFX(UNiagaraSystem *FX, FName SocketName);
	UFUNCTION(NetMulticast, Reliable, Category = "Net")
	void Multicast_PlayWeaponFireFX(UNiagaraSystem *FX, FName SocketName);

	void UnequipWeapon();
	UFUNCTION(Server, Reliable, Category = "Net")
	void Server_UnequipWeapon(int Index);
	UFUNCTION(NetMulticast, Reliable, Category = "Net")
	void Multicast_UnequipWeapon();

	UFUNCTION(BlueprintImplementableEvent, Category = "Weapons")
	void OnWeaponEquipped(const FRecoilAnimData Data, const float Rate = 0.0f, const int Bursts = 0);

	UFUNCTION(BlueprintImplementableEvent, Category = "Weapons")
	void OnWeaponUnequipped();

	UFUNCTION()
	void PlayCameraShake();

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent *Mesh1P;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent *Mesh3P;

	UCameraComponent *GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	URecoilAnimationComponent *GetRecoilAnimation() const { return RecoilAnimation; }

	FCollisionQueryParams GetIgnoreCharacterParams() const;
};
