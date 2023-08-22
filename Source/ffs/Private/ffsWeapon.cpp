#include "ffsWeapon.h"
#include "GameFramework/Character.h"
#include "Components/ChildActorComponent.h"
#include "Blueprint/UserWidget.h"
#include "ffsCharacter.h"
#include "ffsInteractionArea.h"

AffsWeapon::AffsWeapon()
{
    PrimaryActorTick.bCanEverTick = true;

    bReplicates = true;

    Pivot = CreateDefaultSubobject<USceneComponent>(TEXT("Pivot"));

    GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
    GunMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    GunMesh->bEditableWhenInherited = true;

    GunMesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh3P"));
    GunMesh3P->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    InteractionAreaComponent = CreateDefaultSubobject<UChildActorComponent>(TEXT("InteractionAreaComponent"));
    InteractionAreaComponent->SetupAttachment(GunMesh3P);
    InteractionAreaComponent->SetChildActorClass(AffsInteractionArea::StaticClass());

    InteractionWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WeaponWidgetComponent"));
    InteractionWidgetComponent->SetupAttachment(GunMesh3P);
    InteractionWidgetComponent->SetVisibility(false);
}

void AffsWeapon::EnableInteraction()
{
    if (InteractionAreaComponent)
    {
        // get child actor and cast to interaction area
        AffsInteractionArea *InteractionArea = Cast<AffsInteractionArea>(InteractionAreaComponent->GetChildActor());

        if (InteractionArea)
        {
            InteractionArea->EnableInteraction();
        }
    }
}

void AffsWeapon::DisableInteraction()
{
    if (InteractionAreaComponent)
    {
        // get child actor and cast to interaction area
        AffsInteractionArea *InteractionArea = Cast<AffsInteractionArea>(InteractionAreaComponent->GetChildActor());

        if (InteractionArea)
        {
            InteractionArea->DisableInteraction();
        }
    }
}

void AffsWeapon::PostInitializeComponents()
{
    Super::PostInitializeComponents();

    if (GunMesh->GetSkinnedAsset() != nullptr && GunMesh3P->GetSkinnedAsset() == nullptr)
    {
        GunMesh3P->SetSkinnedAsset(GunMesh->GetSkinnedAsset());
    }
}

void AffsWeapon::UpdateFirstPersonGunMeshFOV(float FOV)
{
    int32 FOVMaterialIndex = -1;
    TArray<FName> MaterialSlotNames = GunMesh->GetMaterialSlotNames();

    // Loop through all the material slots on the gunmesh, determine which one is the FOV material
    for (int i = 0; i < MaterialSlotNames.Num(); i++)
    {
        if (MaterialSlotNames[i] == "FOV")
        {
            FOVMaterialIndex = i;
            break;
        }
    }

    if (FOVMaterialIndex == -1)
        return;

    UMaterialInterface *Material = GunMesh->GetMaterial(FOVMaterialIndex);
    GunMesh->SetMaterial(0, Material);
}

FHitResult AffsWeapon::FireLineTrace(bool Initial, bool Debug)
{
    FHitResult HitResult;

    if (!GunMesh)
        return HitResult;

    ACharacter *GunOwner = Cast<ACharacter>(GetOwner());
    APlayerController *PC = GunOwner ? Cast<APlayerController>(GunOwner->GetController()) : nullptr;

    if (!PC)
        return HitResult;

    FVector PlayerViewpointLocation;
    FRotator PlayerViewpointRotation;
    PC->GetPlayerViewPoint(PlayerViewpointLocation, PlayerViewpointRotation);

    // Get the start location of the line trace, center of the camera
    FVector StartLocation = PlayerViewpointLocation + PlayerViewpointRotation.Vector() * 20.f;

    // Calculate the end location of the line trace with added spread
    float Spread = Initial ? 0.f : WeaponSpread;
    FVector DirectionWithSpread = FMath::VRandCone(PlayerViewpointRotation.Vector(), Spread);
    FVector EndLocation = StartLocation + (DirectionWithSpread * WeaponRange);

    FCollisionQueryParams TraceParams;
    TraceParams.AddIgnoredActor(GunOwner);

    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_GameTraceChannel2, TraceParams);

    if (Debug)
    {
        DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, 1.f, 0, 1.f);
    }

    return HitResult;
}

void AffsWeapon::ImplementedToggleFocus_Implementation(bool bIsFocused)
{
    if (InteractionWidgetComponent)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ImplementedToggleFocus_Implementation() called!"));

        InteractionWidgetComponent->SetVisibility(bIsFocused);
    }
}

class UUserWidget *AffsWeapon::GetInteractionWidget_Implementation()
{
    if (InteractionWidgetComponent)
    {
        return InteractionWidgetComponent->GetUserWidgetObject();
    }

    return nullptr;
}

void AffsWeapon::Interact_Implementation()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Interact_Implementation() called!"));
}