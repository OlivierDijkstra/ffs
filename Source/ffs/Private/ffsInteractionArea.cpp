#include "ffsInteractionArea.h"
#include "Interfaces/ffsIsInteractable.h"
#include "Widgets/ffsBaseInteractionWidget.h"

AffsInteractionArea::AffsInteractionArea()
{
    InteractionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionBox"));

    if (bIsInteractable)
    {
        EnableInteraction();
    }
    else
    {
        DisableInteraction();
    }

    RootComponent = InteractionBox;
}

void AffsInteractionArea::ToggleFocus(bool bFocused)
{
    if (!bIsInteractable) return;

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

void AffsInteractionArea::EnableInteraction()
{
    bIsInteractable = true;

    InteractionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    InteractionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    InteractionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel3, ECollisionResponse::ECR_Block);
}

void AffsInteractionArea::DisableInteraction()
{
    bIsInteractable = false;

    InteractionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}