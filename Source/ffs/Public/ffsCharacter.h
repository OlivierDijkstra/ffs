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
	virtual void Tick(float DeltaTime) override;

protected:
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

	// Time before the player respawns after dying, in seconds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn")
	float RespawnTime = 3.f;

	// Radius of the sphere used to find a spawn point
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn")
	float SpawnPointSearchRadius = 1000.f;

	// Default spawn point for the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Respawn")
	FVector DefaultSpawnPoint = FVector(0.f, 0.f, 0.f);

	// Camera used when the player is dead
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* DeathCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* DeathCameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
	bool bIsDead;

	//
	// State
	//
	FDelegateHandle HealthChangedDelegateHandle;

    void OnHealthChanged(const FOnAttributeChangeData& Data);
    void Die();

	UFUNCTION(Server, Reliable)
	void Server_TeleportPlayer();
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_FixPlayer();

	UFUNCTION(BlueprintCallable)
    void Ragdoll();
	UFUNCTION(Server, Reliable)
    void Server_Ragdoll();
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_Ragdoll();

	UFUNCTION(BlueprintCallable, Category = "Respawn")
	void Respawn();

	void ResetAttributes();

	//
	// Weapons
	//
	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void FireWeapon();

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

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void PlayThirdPersonMontage(UAnimMontage *Montage, float Rate = 1.0f);
	UFUNCTION(Server, Reliable, Category = "Net")
	void Server_PlayThirdPersonMontage(UAnimMontage *Montage, float Rate = 1.0f);
	UFUNCTION(NetMulticast, Reliable, Category = "Net")
	void Multicast_PlayThirdPersonMontage(UAnimMontage *Montage, float Rate = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void PlayThirdPersonUnequipMontage(float Rate = 1.0f);
	UFUNCTION(BlueprintCallable, Category = "Weapons")
	void PlayThirdPersonEquipMontage(float Rate = 1.0f);

	UFUNCTION()
	void PlayCameraShake();

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent *Mesh1P;
	UCameraComponent *GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	URecoilAnimationComponent *GetRecoilAnimation() const { return RecoilAnimation; }

	UffsWeaponManager *GetWeaponManager() const { return WeaponManager; }

	FCollisionQueryParams GetIgnoreCharacterParams() const;

private:
	FTimerHandle RespawnTimerHandle;

	void SwitchToDeathCamera();
	void SwitchToFirstPersonCamera();
};
