#include "Components/ffsInteractionManager.h"
#include "ffsInteractionArea.h"
#include "Interfaces/ffsIsInteractable.h"
#include "Widgets/ffsBaseInteractionWidget.h"
#include "ffsCharacter.h"
#include "Camera/CameraComponent.h"

UffsInteractionManager::UffsInteractionManager()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UffsInteractionManager::BeginPlay()
{
    Super::BeginPlay();
    
    CachedCameraComponent = GetOwner()->FindComponentByClass<UCameraComponent>();
    CachedWorld = GetWorld();
}

void UffsInteractionManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    Trace();
}

void UffsInteractionManager::Trace()
{
    FHitResult HitResult;
    FCollisionQueryParams TraceParams(FName(TEXT("InteractionTrace")), true, this->GetOwner());
    TraceParams.bTraceComplex = true;
    TraceParams.bReturnPhysicalMaterial = false;
    TraceParams.AddIgnoredActor(this->GetOwner());

    FVector Start = GetOwner()->GetActorLocation();
    FVector ForwardVector = GetOwner()->GetActorForwardVector();

    if (CachedCameraComponent)
    {
        Start = CachedCameraComponent->GetComponentLocation();
        ForwardVector = CachedCameraComponent->GetForwardVector();
    }

    const FVector End = ((ForwardVector * InteractionDistance) + Start);

    UWorld* World = GetWorld();
    bool bHit = World->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_GameTraceChannel3, TraceParams);

    if (bHit && HitResult.GetActor() != FocusedActor)
    {
        if (FocusedActor)
        {
            FocusedActor->ToggleFocus(false); // Hide/reset the widget of the previous interactable
            TryToInteract(false); // Stop the interaction with the previous interactable
        }

        AffsInteractionArea* InteractionArea = Cast<AffsInteractionArea>(HitResult.GetActor());

        if (InteractionArea)
        {
            InteractionArea->ToggleFocus(true);
            FocusedActor = InteractionArea;
        }
    }
    else if (!bHit && FocusedActor)
    {
        FocusedActor->ToggleFocus(false);
        TryToInteract(false);
        FocusedActor = nullptr;
    }
}

void UffsInteractionManager::TryToInteract(bool bIsInteracting)
{
    if (bIsInteracting && !bInteractionComplete)
    {
        if (FocusedActor)
        {
            InteractionPercentage = 0.f;

            CachedWorld->GetTimerManager().SetTimer(InteractionTimerHandle, this, &UffsInteractionManager::UpdateInteractionPercentage, UpdateFrequency, true);
        }
    }
    else
    {
        InteractionPercentage = 0.f;
        bInteractionComplete = false;

        CachedWorld->GetTimerManager().ClearTimer(InteractionTimerHandle);

        ResetInteractionWidgetPercentage();
    }
}

void UffsInteractionManager::Server_TryToInteract_Implementation(AffsInteractionArea *InteractionArea)
{
    AActor* ParentActor = InteractionArea->GetAttachParentActor();

    if (ParentActor)
    {
        if (ParentActor->GetClass()->ImplementsInterface(UffsIsInteractable::StaticClass()))
        { 
            // Get the owning character and call the interact function
            AffsCharacter* InteractingCharacter = Cast<AffsCharacter>(GetOwner());

            IffsIsInteractable::Execute_Interact(ParentActor, InteractingCharacter);
        }
    }
}

UffsBaseInteractionWidget* UffsInteractionManager::GetInteractionWidgetFromFocusedActor()
{
    if (FocusedActor && FocusedActor->GetAttachParentActor()->GetClass()->ImplementsInterface(UffsIsInteractable::StaticClass()))
    {
        UUserWidget* InteractionWidget = IffsIsInteractable::Execute_GetInteractionWidget(FocusedActor->GetAttachParentActor());
        
        if (InteractionWidget)
        {
            return Cast<UffsBaseInteractionWidget>(InteractionWidget);
        }
    }
    return nullptr;
}

void UffsInteractionManager::UpdateInteractionPercentage()
{
    if (FocusedActor && InteractionPercentage < 1.f)
    {
        InteractionPercentage += CachedWorld->GetDeltaSeconds() / FocusedActor->InteractionDuration;

        UffsBaseInteractionWidget* BaseInteractionWidget = GetInteractionWidgetFromFocusedActor();

        if (BaseInteractionWidget)
        {
            BaseInteractionWidget->UpdatePercentage(InteractionPercentage);
        }

        if (InteractionPercentage >= 1.f)
        {
            Server_TryToInteract(FocusedActor);
            InteractionPercentage = 0.f;
            bInteractionComplete = true;
            CachedWorld->GetTimerManager().ClearTimer(InteractionTimerHandle);
            
            // Reset the widget's percentage and hide it
            ResetInteractionWidgetPercentage();

            // Reset the FocusedActor to ensure the widget is hidden and ready for a new interaction
            if (FocusedActor)
            {
                FocusedActor->ToggleFocus(false);
                FocusedActor = nullptr;
            }
        }
    }
}


void UffsInteractionManager::ResetInteractionWidgetPercentage()
{
    UffsBaseInteractionWidget* BaseInteractionWidget = GetInteractionWidgetFromFocusedActor();

    if (BaseInteractionWidget)
    {
        BaseInteractionWidget->UpdatePercentage(0.f); // Reset the percentage
    }
}