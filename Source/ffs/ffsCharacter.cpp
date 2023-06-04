// Copyright Epic Games, Inc. All Rights Reserved.

#include "ffsCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Animations/GSCNativeAnimInstanceInterface.h"


//////////////////////////////////////////////////////////////////////////
// AffsCharacter

AffsCharacter::AffsCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	// Create a mesh component that will be used when being viewed from a '3rd person' view (when controlling another pawn)
	Mesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh3P"));
	Mesh3P->SetOwnerNoSee(true);
	Mesh3P->SetupAttachment(GetCapsuleComponent());
	Mesh3P->bCastDynamicShadow = true;
	Mesh3P->CastShadow = true;
	//Mesh3P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh3P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

}

void AffsCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	// Console log to the screen	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hello World!"));
	}

	// Setup blueprint property mapping for Mesh1P
	if (Mesh1P)
	{
		if (IGSCNativeAnimInstanceInterface* AnimInstanceInterface = Cast<IGSCNativeAnimInstanceInterface>(Mesh1P->GetAnimInstance()))
		{
			UAbilitySystemComponent* ASC = reinterpret_cast<UAbilitySystemComponent*>(AbilitySystemComponent);
			AnimInstanceInterface->InitializeWithAbilitySystem(ASC);
		}
	}

	// Setup blueprint property mapping for Mesh3P
	if (Mesh3P)
	{
		if (IGSCNativeAnimInstanceInterface* AnimInstanceInterface = Cast<IGSCNativeAnimInstanceInterface>(Mesh3P->GetAnimInstance()))
		{
			UAbilitySystemComponent* ASC = reinterpret_cast<UAbilitySystemComponent*>(AbilitySystemComponent);
			AnimInstanceInterface->InitializeWithAbilitySystem(ASC);
		}
	}
}