#include "Interfaces/ffsIsInteractable.h"
#include "Widgets/ffsBaseInteractionWidget.h"
#include "ffsInteractionArea.h"

AffsInteractionArea::AffsInteractionArea()
{
    InteractionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionBox"));
    InteractionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    InteractionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    InteractionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Block);

    RootComponent = InteractionBox;
}

void AffsInteractionArea::ToggleFocus(bool bFocused)
{
    AActor* ParentActor = GetAttachParentActor();

    this->bIsFocused = bFocused;

    if (ParentActor)
    {
        if (ParentActor->GetClass()->ImplementsInterface(UffsIsInteractable::StaticClass()))
        {
            IffsIsInteractable::Execute_ImplementedToggleFocus(ParentActor, bFocused);
        }
    }
} 