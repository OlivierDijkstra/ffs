// Designed by Hitman's Store, 2022

#include "CurveExtractor.h"

#include "AnimationBlueprintLibrary/Public/AnimationBlueprintLibrary.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/SavePackage.h"
#include "RecoilAnimation/Public/PluginSettings.h"

void UCurveExtractor::OnApply_Implementation(UAnimSequence* AnimationSequence)
{
	Super::OnApply_Implementation(AnimationSequence);
	
	FTransform RefPose;
	UAnimationBlueprintLibrary::GetBonePoseForFrame(AnimationSequence, BoneName, 0, false,
	                                                RefPose);

	TArray<FName> BoneChain;
	UAnimationBlueprintLibrary::FindBonePathToRoot(AnimationSequence, BoneName, BoneChain);

	RefPose = GetComponentBonePose(BoneChain, AnimationSequence, 0);

	TArray<FTransform> BonePoses;

	FVector MaxLoc = FVector::ZeroVector;
	FRotator MaxRot = FRotator::ZeroRotator;

	/** Filling poses array with additive data */
	for(int i = 0; i < AnimationSequence->GetNumberOfSampledKeys(); i++)
	{
		FVector DeltaLoc;
		FRotator DeltaRot;

		FTransform CurrentPose;
		CurrentPose = GetComponentBonePose(BoneChain, AnimationSequence, i);
		
		DeltaLoc = CurrentPose.GetLocation() - RefPose.GetLocation();

		DeltaRot = CurrentPose.GetRotation().Rotator() - RefPose.GetRotation().Rotator();

		if(FMath::Abs(DeltaLoc.X) > FMath::Abs(MaxLoc.X))
		{
			MaxLoc.X = FMath::Abs(DeltaLoc.X);
		}

		if(FMath::Abs(DeltaLoc.Y) > FMath::Abs(MaxLoc.Y))
		{
			MaxLoc.Y = FMath::Abs(DeltaLoc.Y);
		}

		if(FMath::Abs(DeltaLoc.Z) > FMath::Abs(MaxLoc.Z))
		{
			MaxLoc.Z = FMath::Abs(DeltaLoc.Z);
		}
		
		if(FMath::Abs(DeltaRot.Pitch) > FMath::Abs(MaxRot.Pitch))
		{
			MaxRot.Pitch = FMath::Abs(DeltaRot.Pitch);
		}

		if(FMath::Abs(DeltaRot.Yaw) > FMath::Abs(MaxRot.Yaw))
		{
			MaxRot.Yaw = FMath::Abs(DeltaRot.Yaw);
		}

		if(FMath::Abs(DeltaRot.Roll) > FMath::Abs(MaxRot.Roll))
		{
			MaxRot.Roll = FMath::Abs(DeltaRot.Roll);
		}
		
		BonePoses.Add(FTransform(DeltaRot, DeltaLoc));
	}

	/** Remapping to [0;1] */
	for (int i = 0; i < AnimationSequence->GetNumberOfSampledKeys(); i++)
	{
		FVector NormalizedVector;
		NormalizedVector.X = BonePoses[i].GetLocation().X / FMath::Max(0.001f, MaxLoc.X);
		NormalizedVector.Y = BonePoses[i].GetLocation().Y / FMath::Max(0.001f, MaxLoc.Y);
		NormalizedVector.Z = BonePoses[i].GetLocation().Z / FMath::Max(0.001f, MaxLoc.Z);
		
		FRotator NormalizedRotator;

		NormalizedRotator.Pitch = BonePoses[i].GetRotation().Rotator().Pitch / FMath::Max(0.001f, MaxRot.Pitch);
		NormalizedRotator.Yaw = BonePoses[i].GetRotation().Rotator().Yaw / FMath::Max(0.001f, MaxRot.Yaw);
		NormalizedRotator.Roll = BonePoses[i].GetRotation().Rotator().Roll / FMath::Max(0.001f, MaxRot.Roll);

		BonePoses[i] = FTransform(NormalizedRotator, NormalizedVector);
	}

	auto PluginSettings = GetMutableDefault<UPluginSettings>();

	if(!PluginSettings)
	{
		UE_LOG(LogTemp, Error, TEXT("Plugin Settings Are NULL"))
		return;
	}

	const FString PackagePath = PluginSettings->CurvesSavePath + WeaponName + FString("_Curves/");

	UPackage* PackageLoc = CreatePackage(*(PackagePath + AnimName.ToString() + FString("Loc")));
	PackageLoc->FullyLoad();
	
	UPackage* PackageRot = CreatePackage(*(PackagePath + AnimName.ToString() + FString("Rot")));
	PackageRot->FullyLoad();

	UCurveVector* Loc = NewObject<UCurveVector>(PackageLoc, *(AnimName.ToString() + FString("Loc")),
	                                            RF_Public | RF_Standalone);
	UCurveVector* Rot = NewObject<UCurveVector>(PackageRot, *(AnimName.ToString() + FString("Rot")),
	                                            RF_Public | RF_Standalone);

	for (int i = 0; i < AnimationSequence->GetNumberOfSampledKeys(); i++)
	{
		float FrameTime;
		UAnimationBlueprintLibrary::GetTimeAtFrame(AnimationSequence, i, FrameTime);
		
		Loc->FloatCurves[0].AutoSetTangents();
		Rot->FloatCurves[1].AutoSetTangents();
		Rot->FloatCurves[2].AutoSetTangents();

		Loc->FloatCurves[1].SetKeyInterpMode(Loc->FloatCurves[1].AddKey(FrameTime, BonePoses[i].GetLocation().X),
		                                     RCIM_Cubic);
		Loc->FloatCurves[0].SetKeyInterpMode(Loc->FloatCurves[0].AddKey(FrameTime, BonePoses[i].GetLocation().Y),
		                                     RCIM_Cubic);
		Loc->FloatCurves[2].SetKeyInterpMode(Loc->FloatCurves[2].AddKey(FrameTime, BonePoses[i].GetLocation().Z),
		                                     RCIM_Cubic);

		Rot->FloatCurves[0].SetKeyInterpMode(
			Rot->FloatCurves[0].AddKey(FrameTime, BonePoses[i].GetRotation().Rotator().Roll),
			RCIM_Cubic);
		Rot->FloatCurves[1].SetKeyInterpMode(
			Rot->FloatCurves[1].AddKey(FrameTime, BonePoses[i].GetRotation().Rotator().Yaw),
			RCIM_Cubic);
		Rot->FloatCurves[2].SetKeyInterpMode(
			Rot->FloatCurves[2].AddKey(FrameTime, BonePoses[i].GetRotation().Rotator().Pitch),
			RCIM_Cubic);
	}

	SaveCurve(PackageLoc, Loc, PackagePath + AnimName.ToString() + FString("Loc"));
	SaveCurve(PackageRot, Rot, PackagePath + AnimName.ToString() + FString("Rot"));
}

FTransform UCurveExtractor::GetComponentBonePose(const TArray<FName>& BoneChain, UAnimSequence* AnimSequence, int Frame)
{
	FTransform ComponentPose;
	for(int i = BoneChain.Num() - 1; i > -1; i--)
	{
		FTransform LocalPose;
		UAnimationBlueprintLibrary::GetBonePoseForFrame(AnimSequence, BoneChain[i], Frame, false,
														LocalPose);
		
		FVector Loc = ComponentPose.GetRotation().RotateVector(LocalPose.GetLocation());
		FRotator Rot = LocalPose.GetRotation().Rotator() + ComponentPose.GetRotation().Rotator();

		ComponentPose.AddToTranslation(Loc);
		ComponentPose.SetRotation(Rot.Quaternion());
	}
	
	return ComponentPose;
}

void UCurveExtractor::SaveCurve(UPackage* Package, UCurveVector* Curve, const FString& PackagePath)
{
	FAssetRegistryModule::AssetCreated(Curve);

	/** Getting the full path to the file */
	const FString FilePath = FPackageName::LongPackageNameToFilename(PackagePath,
																	 FPackageName::GetAssetPackageExtension());

	/** Finally saving just created package */
	FSavePackageArgs SavePackageArgs;
	SavePackageArgs.TopLevelFlags = EObjectFlags::RF_Public | EObjectFlags::RF_Standalone;
	const bool bSuccess = UPackage::SavePackage(Package, Curve, *FilePath, SavePackageArgs);
	
	Package->SetDirtyFlag(true);

	UE_LOG(LogTemp, Warning, TEXT("Saved Package: %s"), bSuccess ? TEXT("SUCCESS") : TEXT("ERROR"))
}