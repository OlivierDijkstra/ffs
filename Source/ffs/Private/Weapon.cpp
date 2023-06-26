﻿#include "GameFramework/Character.h"
#include "Weapon.h"

AWeapon::AWeapon()
{
	Pivot = CreateDefaultSubobject<USceneComponent>(TEXT("Pivot"));

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh"));
	GunMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GunMesh->bEditableWhenInherited = true;

	GunMesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GunMesh3P"));
	GunMesh3P->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GunMesh3P->bEditableWhenInherited = true;
}

void AWeapon::PlayFireAnim() const
{
	if (FireMontage)
	{
		GunMesh->PlayAnimation(FireMontage, false);
	}
}

FFireLineTraceResult AWeapon::FireLineTrace(bool Initial, bool Debug)
{
    FFireLineTraceResult Result;
    Result.HitActor = nullptr;
    Result.HitCharacter = nullptr;

    if (!GunMesh) return Result;

    ACharacter* GunOwner = Cast<ACharacter>(GetOwner());
    APlayerController* PC = GunOwner ? Cast<APlayerController>(GunOwner->GetController()) : nullptr;

    if (!PC) return Result;

    FVector PlayerViewpointLocation;
    FRotator PlayerViewpointRotation;
    PC->GetPlayerViewPoint(PlayerViewpointLocation, PlayerViewpointRotation);

    // Get the start location of the line trace
    FVector StartLocation = GunMesh->GetSocketLocation(FName("Muzzle"));

    // Calculate the end location of the line trace with added spread
    float Spread = Initial ? 0.f : WeaponSpread;
    FVector DirectionWithSpread = FMath::VRandCone(PlayerViewpointRotation.Vector(), Spread);
    FVector EndLocation = StartLocation + (DirectionWithSpread * WeaponRange);

    FHitResult HitResult;
    FCollisionQueryParams TraceParams;
    TraceParams.AddIgnoredActor(GunOwner);

    // Perform the line trace
    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Camera, TraceParams);

    if (bHit)
    {
        Result.HitActor = HitResult.GetActor();
        if (IsValid(Result.HitActor))
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hit Actor: %s"), *Result.HitActor->GetName()));

            // Cast the actor to ACharacter to check if it's a character
            Result.HitCharacter = Cast<ACharacter>(Result.HitActor);
        }
    }

    // If Debug is true, draw the line trace for visualization
    if (Debug)
    {
        DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, 1.f, 0, 1.f);
    }

    return Result;
}