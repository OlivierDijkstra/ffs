#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ffsInteractionArea.generated.h"

class ffsBaseInteractionWidget;

UCLASS()
class FFS_API AffsInteractionArea : public AActor
{
    GENERATED_BODY()

public:
    AffsInteractionArea();

    UPROPERTY(VisibleAnywhere, Category = "Interaction")
    UBoxComponent* InteractionBox;

    UFUNCTION(BlueprintCallable, Category = "Interaction")
    void ToggleFocus(bool bFocused);

    bool bIsFocused = false;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interaction")
    float InteractionDuration = 0.f;
};