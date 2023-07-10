// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RecoilAnimation/Public/StoredData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStoredData() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector4();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
	RECOILANIMATION_API UClass* Z_Construct_UClass_UStoredData();
	RECOILANIMATION_API UClass* Z_Construct_UClass_UStoredData_NoRegister();
	RECOILANIMATION_API UScriptStruct* Z_Construct_UScriptStruct_FProgression();
	UPackage* Z_Construct_UPackage__Script_RecoilAnimation();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Progression;
class UScriptStruct* FProgression::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Progression.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Progression.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FProgression, (UObject*)Z_Construct_UPackage__Script_RecoilAnimation(), TEXT("Progression"));
	}
	return Z_Registration_Info_UScriptStruct_Progression.OuterSingleton;
}
template<> RECOILANIMATION_API UScriptStruct* StaticStruct<FProgression>()
{
	return FProgression::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FProgression_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Accel_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Accel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Damping_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Damping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Amount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Amount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProgression_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FProgression_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FProgression>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Accel_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Accel = { "Accel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FProgression, Accel), METADATA_PARAMS(Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Accel_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Accel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Damping_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Damping = { "Damping", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FProgression, Damping), METADATA_PARAMS(Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Damping_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Damping_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Amount_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FProgression, Amount), METADATA_PARAMS(Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Amount_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Amount_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FProgression_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Accel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Damping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProgression_Statics::NewProp_Amount,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FProgression_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RecoilAnimation,
		nullptr,
		&NewStructOps,
		"Progression",
		sizeof(FProgression),
		alignof(FProgression),
		Z_Construct_UScriptStruct_FProgression_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProgression_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FProgression_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FProgression_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FProgression()
	{
		if (!Z_Registration_Info_UScriptStruct_Progression.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Progression.InnerSingleton, Z_Construct_UScriptStruct_FProgression_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_Progression.InnerSingleton;
	}
	void UStoredData::StaticRegisterNativesUStoredData()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStoredData);
	UClass* Z_Construct_UClass_UStoredData_NoRegister()
	{
		return UStoredData::StaticClass();
	}
	struct Z_Construct_UClass_UStoredData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PitchAim_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PitchAim;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_YawAim_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_YawAim;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RollAim_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RollAim;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PitchHip_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PitchHip;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_YawHip_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_YawHip;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RollHip_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RollHip;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KickAim_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_KickAim;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KickAimR_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_KickAimR;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KickAimUp_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_KickAimUp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KickHip_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_KickHip;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KickHipR_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_KickHipR;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KickHipUp_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_KickHipUp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SmoothRot_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SmoothRot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SmoothLoc_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SmoothLoc;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MultiRot_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MultiRot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MultiLoc_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MultiLoc;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSmoothRoll_MetaData[];
#endif
		static void NewProp_bSmoothRoll_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSmoothRoll;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Noise2DTarget_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Noise2DTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Noise2DAccel_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Noise2DAccel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Noise2DZero_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Noise2DZero;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NoiseAimScalar_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_NoiseAimScalar;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pushback_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Pushback;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PushbackZero_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PushbackZero;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PushbackAccel_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PushbackAccel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PitchProgress_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PitchProgress;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZProgress_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ZProgress;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProgressAimAlpha_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ProgressAimAlpha;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlaybackOffset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaybackOffset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayRate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UStoredData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_RecoilAnimation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "StoredData.h" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_PitchAim_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Pitch when aiming\n\x09 * X - min\n\x09 * Y - max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Pitch when aiming\nX - min\nY - max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_PitchAim = { "PitchAim", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, PitchAim), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_PitchAim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_PitchAim_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_YawAim_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Yaw when aiming\n\x09 * X - min min\n\x09 * Y - min max\n\x09 * Z - max min\n\x09 * W - max max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Yaw when aiming\nX - min min\nY - min max\nZ - max min\nW - max max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_YawAim = { "YawAim", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, YawAim), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_YawAim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_YawAim_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_RollAim_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Roll when aiming\n\x09 * X - min min\n\x09 * Y - min max\n\x09 * Z - max min\n\x09 * W - max max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Roll when aiming\nX - min min\nY - min max\nZ - max min\nW - max max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_RollAim = { "RollAim", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, RollAim), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_RollAim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_RollAim_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_PitchHip_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Pitch when not aiming\n\x09 * X - min\n\x09 * Y - max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Pitch when not aiming\nX - min\nY - max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_PitchHip = { "PitchHip", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, PitchHip), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_PitchHip_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_PitchHip_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_YawHip_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Yaw when not aiming\n\x09 * X - min min\n\x09 * Y - min max\n\x09 * Z - max min\n\x09 * W - max max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Yaw when not aiming\nX - min min\nY - min max\nZ - max min\nW - max max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_YawHip = { "YawHip", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, YawHip), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_YawHip_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_YawHip_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_RollHip_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Roll when not aiming\n\x09 * X - min min\n\x09 * Y - min max\n\x09 * Z - max min\n\x09 * W - max max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Roll when not aiming\nX - min min\nY - min max\nZ - max min\nW - max max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_RollHip = { "RollHip", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, RollHip), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_RollHip_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_RollHip_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_KickAim_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Kickback when aiming\n\x09 * X - min\n\x09 * Y - max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Kickback when aiming\nX - min\nY - max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_KickAim = { "KickAim", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, KickAim), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_KickAim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_KickAim_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_KickAimR_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Kickback Right when aiming\n\x09 * X - min\n\x09 * Y - max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Kickback Right when aiming\nX - min\nY - max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_KickAimR = { "KickAimR", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, KickAimR), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_KickAimR_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_KickAimR_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_KickAimUp_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Kickback Up when aiming\n\x09 * X - min\n\x09 * Y - max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Kickback Up when aiming\nX - min\nY - max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_KickAimUp = { "KickAimUp", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, KickAimUp), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_KickAimUp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_KickAimUp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_KickHip_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Kickback when not aiming\n\x09 * X - min\n\x09 * Y - max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Kickback when not aiming\nX - min\nY - max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_KickHip = { "KickHip", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, KickHip), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_KickHip_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_KickHip_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_KickHipR_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Kickback Right when not aiming\n\x09 * X - min\n\x09 * Y - max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Kickback Right when not aiming\nX - min\nY - max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_KickHipR = { "KickHipR", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, KickHipR), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_KickHipR_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_KickHipR_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_KickHipUp_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Target values for Kickback Up when not aiming\n\x09 * X - min\n\x09 * Y - max\n\x09 */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Target values for Kickback Up when not aiming\nX - min\nY - max" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_KickHipUp = { "KickHipUp", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, KickHipUp), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_KickHipUp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_KickHipUp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_SmoothRot_MetaData[] = {
		{ "Category", "Smoothing" },
		{ "Comment", "/** Smooth amount in Auto mode. 0 means no smoothing */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Smooth amount in Auto mode. 0 means no smoothing" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_SmoothRot = { "SmoothRot", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, SmoothRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_SmoothRot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_SmoothRot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_SmoothLoc_MetaData[] = {
		{ "Category", "Smoothing" },
		{ "Comment", "/** Smooth amount in Auto mode. 0 means no smoothing */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Smooth amount in Auto mode. 0 means no smoothing" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_SmoothLoc = { "SmoothLoc", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, SmoothLoc), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_SmoothLoc_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_SmoothLoc_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_MultiRot_MetaData[] = {
		{ "Category", "Smoothing" },
		{ "Comment", "/** Multiplier for each rotation axis while in Semi/Auto state */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Multiplier for each rotation axis while in Semi/Auto state" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_MultiRot = { "MultiRot", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, MultiRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_MultiRot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_MultiRot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_MultiLoc_MetaData[] = {
		{ "Category", "Smoothing" },
		{ "Comment", "/** Multiplier for each translation axis while in Semi/Auto state */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Multiplier for each translation axis while in Semi/Auto state" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_MultiLoc = { "MultiLoc", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, MultiLoc), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_MultiLoc_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_MultiLoc_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_bSmoothRoll_MetaData[] = {
		{ "Category", "Smoothing" },
		{ "Comment", "/** Enables smoothing for Roll target values */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Enables smoothing for Roll target values" },
	};
#endif
	void Z_Construct_UClass_UStoredData_Statics::NewProp_bSmoothRoll_SetBit(void* Obj)
	{
		((UStoredData*)Obj)->bSmoothRoll = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_bSmoothRoll = { "bSmoothRoll", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UStoredData), &Z_Construct_UClass_UStoredData_Statics::NewProp_bSmoothRoll_SetBit, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_bSmoothRoll_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_bSmoothRoll_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DTarget_MetaData[] = {
		{ "Category", "Noise 2D Layer" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DTarget = { "Noise2DTarget", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, Noise2DTarget), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DTarget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DAccel_MetaData[] = {
		{ "Category", "Noise 2D Layer" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DAccel = { "Noise2DAccel", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, Noise2DAccel), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DAccel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DAccel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DZero_MetaData[] = {
		{ "Category", "Noise 2D Layer" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DZero = { "Noise2DZero", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, Noise2DZero), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DZero_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DZero_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_NoiseAimScalar_MetaData[] = {
		{ "Category", "Noise 2D Layer" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_NoiseAimScalar = { "NoiseAimScalar", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, NoiseAimScalar), METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_NoiseAimScalar_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_NoiseAimScalar_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_Pushback_MetaData[] = {
		{ "Category", "Pushback" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_Pushback = { "Pushback", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, Pushback), METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_Pushback_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_Pushback_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_PushbackZero_MetaData[] = {
		{ "Category", "Pushback" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_PushbackZero = { "PushbackZero", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, PushbackZero), METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_PushbackZero_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_PushbackZero_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_PushbackAccel_MetaData[] = {
		{ "Category", "Pushback" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_PushbackAccel = { "PushbackAccel", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, PushbackAccel), METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_PushbackAccel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_PushbackAccel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_PitchProgress_MetaData[] = {
		{ "Category", "Progression" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_PitchProgress = { "PitchProgress", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, PitchProgress), Z_Construct_UScriptStruct_FProgression, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_PitchProgress_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_PitchProgress_MetaData)) }; // 2286891156
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_ZProgress_MetaData[] = {
		{ "Category", "Progression" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_ZProgress = { "ZProgress", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, ZProgress), Z_Construct_UScriptStruct_FProgression, METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_ZProgress_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_ZProgress_MetaData)) }; // 2286891156
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_ProgressAimAlpha_MetaData[] = {
		{ "Category", "Progression" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_ProgressAimAlpha = { "ProgressAimAlpha", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, ProgressAimAlpha), METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_ProgressAimAlpha_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_ProgressAimAlpha_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_PlaybackOffset_MetaData[] = {
		{ "Category", "Timeline" },
		{ "Comment", "/** Playback position used for getting start value during Semi-Auto transition */" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
		{ "ToolTip", "Playback position used for getting start value during Semi-Auto transition" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_PlaybackOffset = { "PlaybackOffset", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, PlaybackOffset), METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_PlaybackOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_PlaybackOffset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UStoredData_Statics::NewProp_PlayRate_MetaData[] = {
		{ "Category", "Timeline" },
		{ "ModuleRelativePath", "Public/StoredData.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UStoredData_Statics::NewProp_PlayRate = { "PlayRate", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UStoredData, PlayRate), METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::NewProp_PlayRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::NewProp_PlayRate_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UStoredData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_PitchAim,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_YawAim,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_RollAim,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_PitchHip,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_YawHip,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_RollHip,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_KickAim,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_KickAimR,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_KickAimUp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_KickHip,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_KickHipR,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_KickHipUp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_SmoothRot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_SmoothLoc,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_MultiRot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_MultiLoc,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_bSmoothRoll,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DAccel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_Noise2DZero,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_NoiseAimScalar,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_Pushback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_PushbackZero,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_PushbackAccel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_PitchProgress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_ZProgress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_ProgressAimAlpha,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_PlaybackOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UStoredData_Statics::NewProp_PlayRate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UStoredData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStoredData>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UStoredData_Statics::ClassParams = {
		&UStoredData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UStoredData_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UStoredData_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UStoredData_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UStoredData()
	{
		if (!Z_Registration_Info_UClass_UStoredData.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStoredData.OuterSingleton, Z_Construct_UClass_UStoredData_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UStoredData.OuterSingleton;
	}
	template<> RECOILANIMATION_API UClass* StaticClass<UStoredData>()
	{
		return UStoredData::StaticClass();
	}
	UStoredData::UStoredData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UStoredData);
	UStoredData::~UStoredData() {}
	struct Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_StoredData_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_StoredData_h_Statics::ScriptStructInfo[] = {
		{ FProgression::StaticStruct, Z_Construct_UScriptStruct_FProgression_Statics::NewStructOps, TEXT("Progression"), &Z_Registration_Info_UScriptStruct_Progression, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FProgression), 2286891156U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_StoredData_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UStoredData, UStoredData::StaticClass, TEXT("UStoredData"), &Z_Registration_Info_UClass_UStoredData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStoredData), 1988341129U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_StoredData_h_2061916070(TEXT("/Script/RecoilAnimation"),
		Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_StoredData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_StoredData_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_StoredData_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_StoredData_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
