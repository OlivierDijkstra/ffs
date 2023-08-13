#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ffsBaseInteractionWidget.generated.h"

UCLASS(Blueprintable)
class FFS_API UffsBaseInteractionWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, Category = "Progress")
    void UpdatePercentage(float NewPercentage);

    // Implementable event for BP to get the percentage
    UFUNCTION(BlueprintImplementableEvent, Category = "Progress")
    void OnUpdatePercentage(float NewPercentage);

    UPROPERTY(BlueprintReadOnly, Category = "Progress")
    float Percentage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Progress")
    class UMaterialInstanceDynamic* ProgressBarMaterialInstance = nullptr;
};
