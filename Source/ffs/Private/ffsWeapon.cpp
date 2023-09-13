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
    GunMesh->SetOnlyOwnerSee(true);
    GunMesh->SetupAttachment(Pivot);

    GunMesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh3P"));
    GunMesh3P->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    GunMesh3P->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	GunMesh3P->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Ignore);
	GunMesh3P->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	GunMesh3P->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Ignore);
	GunMesh3P->SetCollisionResponseToChannel(ECC_Vehicle, ECR_Ignore);
	GunMesh3P->SetCollisionResponseToChannel(ECC_Destructible, ECR_Ignore);
    GunMesh3P->SetCollisionResponseToChannel(ECC_GameTraceChannel3, ECR_Block);

    GunMesh3P->SetupAttachment(Pivot);

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

void AffsWeapon::ImplementedToggleFocus_Implementation(bool bIsFocused)
{
    if (InteractionWidgetComponent)
    {
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

void AffsWeapon::Interact_Implementation(AffsCharacter *InteractingCharacter)
{
    if (InteractingCharacter)
    {
        InteractingCharacter->GetWeaponManager()->Server_EquipWeapon(this);
    }
}