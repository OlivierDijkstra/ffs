#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ffsInteractionManager.generated.h"

class AffsInteractionArea;
class UffsBaseInteractionWidget;
class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FFS_API UffsInteractionManager : public UActorComponent
{
    GENERATED_BODY()

protected:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    virtual void BeginPlay() override;

private:
    UffsBaseInteractionWidget* GetInteractionWidgetFromFocusedActor();
    void ResetInteractionWidgetPercentage();

public:    
    UffsInteractionManager();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interaction")
	float InteractionDistance = 300.f;

    void Trace();

    UFUNCTION(BlueprintCallable, Category = "Interaction")
    void TryToInteract(bool bIsInteracting);

    UFUNCTION(Server, Reliable)
    void Server_TryToInteract(AffsInteractionArea* InteractionArea);

    AffsInteractionArea* FocusedActor = nullptr;

    UCameraComponent* CachedCameraComponent = nullptr;
    UWorld* CachedWorld = nullptr;

    void UpdateInteractionPercentage();

    float UpdateFrequency = 0.016667f;

    FTimerHandle InteractionTimerHandle;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
    float InteractionPercentage = 0.f;

    bool bInteractionComplete = false;
};