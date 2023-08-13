#pragma once

#include "CoreMinimal.h"
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
    UFUNCTION(BlueprintImplementableEvent, Category = "ffs|Interaction")
    void ImplementedToggleFocus(bool bIsFocused);

    UFUNCTION(BlueprintImplementableEvent, Category = "ffs|Interaction")
    void Interact();

    UFUNCTION(BlueprintImplementableEvent, Category = "ffs|Interaction")
    class UUserWidget* GetInteractionWidget();
};