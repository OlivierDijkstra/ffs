#include "Widgets/ffsBaseInteractionWidget.h"

void UffsBaseInteractionWidget::UpdatePercentage_Implementation(float NewPercentage)
{
    Percentage = NewPercentage;

    OnUpdatePercentage(NewPercentage);
}