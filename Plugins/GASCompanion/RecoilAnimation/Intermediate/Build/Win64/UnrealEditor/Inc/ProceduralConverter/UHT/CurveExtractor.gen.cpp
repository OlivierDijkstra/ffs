// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProceduralConverter/Public/CurveExtractor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCurveExtractor() {}
// Cross Module References
	ANIMATIONMODIFIERS_API UClass* Z_Construct_UClass_UAnimationModifier();
	ENGINE_API UClass* Z_Construct_UClass_UAnimSequence_NoRegister();
	PROCEDURALCONVERTER_API UClass* Z_Construct_UClass_UCurveExtractor();
	PROCEDURALCONVERTER_API UClass* Z_Construct_UClass_UCurveExtractor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ProceduralConverter();
// End Cross Module References
	void UCurveExtractor::StaticRegisterNativesUCurveExtractor()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCurveExtractor);
	UClass* Z_Construct_UClass_UCurveExtractor_NoRegister()
	{
		return UCurveExtractor::StaticClass();
	}
	struct Z_Construct_UClass_UCurveExtractor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoneName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_BoneName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_AnimName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_WeaponName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SampleRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SampleRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bNormalize_MetaData[];
#endif
		static void NewProp_bNormalize_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bNormalize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAddToAnimation_MetaData[];
#endif
		static void NewProp_bAddToAnimation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAddToAnimation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RefAnimation_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RefAnimation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurveName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_CurveName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCurveExtractor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimationModifier,
		(UObject* (*)())Z_Construct_UPackage__Script_ProceduralConverter,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCurveExtractor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "CurveExtractor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/CurveExtractor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCurveExtractor_Statics::NewProp_BoneName_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/** Bone which will be captured */" },
		{ "ModuleRelativePath", "Public/CurveExtractor.h" },
		{ "ToolTip", "Bone which will be captured" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UCurveExtractor_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UCurveExtractor, BoneName), METADATA_PARAMS(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_BoneName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_BoneName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCurveExtractor_Statics::NewProp_AnimName_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/CurveExtractor.h" },
		{ "ToolTip", "Semi, Burst or Auto" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UCurveExtractor_Statics::NewProp_AnimName = { "AnimName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UCurveExtractor, AnimName), METADATA_PARAMS(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_AnimName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_AnimName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCurveExtractor_Statics::NewProp_WeaponName_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "/** Weapon name */" },
		{ "ModuleRelativePath", "Public/CurveExtractor.h" },
		{ "ToolTip", "Weapon name" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCurveExtractor_Statics::NewProp_WeaponName = { "WeaponName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UCurveExtractor, WeaponName), METADATA_PARAMS(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_WeaponName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_WeaponName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCurveExtractor_Statics::NewProp_SampleRate_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/CurveExtractor.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UCurveExtractor_Statics::NewProp_SampleRate = { "SampleRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UCurveExtractor, SampleRate), METADATA_PARAMS(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_SampleRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_SampleRate_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bNormalize_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/CurveExtractor.h" },
		{ "ToolTip", "Should the curves be mapped [-1;1]" },
	};
#endif
	void Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bNormalize_SetBit(void* Obj)
	{
		((UCurveExtractor*)Obj)->bNormalize = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bNormalize = { "bNormalize", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UCurveExtractor), &Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bNormalize_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bNormalize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bNormalize_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bAddToAnimation_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/CurveExtractor.h" },
		{ "ToolTip", "Should the curves be added to the clip" },
	};
#endif
	void Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bAddToAnimation_SetBit(void* Obj)
	{
		((UCurveExtractor*)Obj)->bAddToAnimation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bAddToAnimation = { "bAddToAnimation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UCurveExtractor), &Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bAddToAnimation_SetBit, METADATA_PARAMS(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bAddToAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bAddToAnimation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCurveExtractor_Statics::NewProp_RefAnimation_MetaData[] = {
		{ "Category", "Settings" },
		{ "EditCondition", "bAddToAnimation" },
		{ "ModuleRelativePath", "Public/CurveExtractor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCurveExtractor_Statics::NewProp_RefAnimation = { "RefAnimation", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UCurveExtractor, RefAnimation), Z_Construct_UClass_UAnimSequence_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_RefAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_RefAnimation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCurveExtractor_Statics::NewProp_CurveName_MetaData[] = {
		{ "Category", "Settings" },
		{ "EditCondition", "bAddToAnimation" },
		{ "ModuleRelativePath", "Public/CurveExtractor.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UCurveExtractor_Statics::NewProp_CurveName = { "CurveName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UCurveExtractor, CurveName), METADATA_PARAMS(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_CurveName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCurveExtractor_Statics::NewProp_CurveName_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCurveExtractor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCurveExtractor_Statics::NewProp_BoneName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCurveExtractor_Statics::NewProp_AnimName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCurveExtractor_Statics::NewProp_WeaponName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCurveExtractor_Statics::NewProp_SampleRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bNormalize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCurveExtractor_Statics::NewProp_bAddToAnimation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCurveExtractor_Statics::NewProp_RefAnimation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCurveExtractor_Statics::NewProp_CurveName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCurveExtractor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCurveExtractor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCurveExtractor_Statics::ClassParams = {
		&UCurveExtractor::StaticClass,
		"Editor",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCurveExtractor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCurveExtractor_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UCurveExtractor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCurveExtractor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCurveExtractor()
	{
		if (!Z_Registration_Info_UClass_UCurveExtractor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCurveExtractor.OuterSingleton, Z_Construct_UClass_UCurveExtractor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCurveExtractor.OuterSingleton;
	}
	template<> PROCEDURALCONVERTER_API UClass* StaticClass<UCurveExtractor>()
	{
		return UCurveExtractor::StaticClass();
	}
	UCurveExtractor::UCurveExtractor() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCurveExtractor);
	UCurveExtractor::~UCurveExtractor() {}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_ProceduralConverter_Public_CurveExtractor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_ProceduralConverter_Public_CurveExtractor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCurveExtractor, UCurveExtractor::StaticClass, TEXT("UCurveExtractor"), &Z_Registration_Info_UClass_UCurveExtractor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCurveExtractor), 3627350036U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_ProceduralConverter_Public_CurveExtractor_h_864901936(TEXT("/Script/ProceduralConverter"),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_ProceduralConverter_Public_CurveExtractor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_ProceduralConverter_Public_CurveExtractor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
