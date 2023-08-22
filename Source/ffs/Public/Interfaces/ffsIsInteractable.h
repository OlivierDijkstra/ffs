#pragma once

#include "CoreMinimal.h"
#include "ffsCharacter.h"
#include "ffsIsInteractable.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UffsIsInteractable : public UInterface
{
    GENERATED_BODY()
};

class IffsIsInteractable
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ffs|Interaction")
    void ImplementedToggleFocus(bool bIsFocused);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ffs|Interaction")
    void Interact(AffsCharacter* InteractingCharacter);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ffs|Interaction")
    class UUserWidget* GetInteractionWidget();
};