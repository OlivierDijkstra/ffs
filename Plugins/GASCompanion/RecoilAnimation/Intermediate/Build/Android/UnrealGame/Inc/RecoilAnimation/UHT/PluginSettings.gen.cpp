// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RecoilAnimation/Public/PluginSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePluginSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	RECOILANIMATION_API UClass* Z_Construct_UClass_UPluginSettings();
	RECOILANIMATION_API UClass* Z_Construct_UClass_UPluginSettings_NoRegister();
	UPackage* Z_Construct_UPackage__Script_RecoilAnimation();
// End Cross Module References
	void UPluginSettings::StaticRegisterNativesUPluginSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPluginSettings);
	UClass* Z_Construct_UClass_UPluginSettings_NoRegister()
	{
		return UPluginSettings::StaticClass();
	}
	struct Z_Construct_UClass_UPluginSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurvesSavePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_CurvesSavePath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DataSavePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DataSavePath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCreateDataAssetIfNull_MetaData[];
#endif
		static void NewProp_bCreateDataAssetIfNull_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateDataAssetIfNull;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPluginSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_RecoilAnimation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPluginSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PluginSettings.h" },
		{ "ModuleRelativePath", "Public/PluginSettings.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPluginSettings_Statics::NewProp_CurvesSavePath_MetaData[] = {
		{ "Category", "Essentials" },
		{ "Comment", "/** Default location for curves */" },
		{ "ModuleRelativePath", "Public/PluginSettings.h" },
		{ "ToolTip", "Default location for curves" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPluginSettings_Statics::NewProp_CurvesSavePath = { "CurvesSavePath", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UPluginSettings, CurvesSavePath), METADATA_PARAMS(Z_Construct_UClass_UPluginSettings_Statics::NewProp_CurvesSavePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPluginSettings_Statics::NewProp_CurvesSavePath_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPluginSettings_Statics::NewProp_DataSavePath_MetaData[] = {
		{ "Category", "Essentials" },
		{ "Comment", "/** Default location for Stored Data assets */" },
		{ "ModuleRelativePath", "Public/PluginSettings.h" },
		{ "ToolTip", "Default location for Stored Data assets" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPluginSettings_Statics::NewProp_DataSavePath = { "DataSavePath", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UPluginSettings, DataSavePath), METADATA_PARAMS(Z_Construct_UClass_UPluginSettings_Statics::NewProp_DataSavePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPluginSettings_Statics::NewProp_DataSavePath_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPluginSettings_Statics::NewProp_bCreateDataAssetIfNull_MetaData[] = {
		{ "Category", "Essentials" },
		{ "Comment", "/** Should StoredData asset be created if null */" },
		{ "ModuleRelativePath", "Public/PluginSettings.h" },
		{ "ToolTip", "Should StoredData asset be created if null" },
	};
#endif
	void Z_Construct_UClass_UPluginSettings_Statics::NewProp_bCreateDataAssetIfNull_SetBit(void* Obj)
	{
		((UPluginSettings*)Obj)->bCreateDataAssetIfNull = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPluginSettings_Statics::NewProp_bCreateDataAssetIfNull = { "bCreateDataAssetIfNull", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UPluginSettings), &Z_Construct_UClass_UPluginSettings_Statics::NewProp_bCreateDataAssetIfNull_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPluginSettings_Statics::NewProp_bCreateDataAssetIfNull_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPluginSettings_Statics::NewProp_bCreateDataAssetIfNull_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPluginSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPluginSettings_Statics::NewProp_CurvesSavePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPluginSettings_Statics::NewProp_DataSavePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPluginSettings_Statics::NewProp_bCreateDataAssetIfNull,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPluginSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPluginSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPluginSettings_Statics::ClassParams = {
		&UPluginSettings::StaticClass,
		"PluginSetting",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPluginSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPluginSettings_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPluginSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPluginSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPluginSettings()
	{
		if (!Z_Registration_Info_UClass_UPluginSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPluginSettings.OuterSingleton, Z_Construct_UClass_UPluginSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPluginSettings.OuterSingleton;
	}
	template<> RECOILANIMATION_API UClass* StaticClass<UPluginSettings>()
	{
		return UPluginSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPluginSettings);
	UPluginSettings::~UPluginSettings() {}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_PluginSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_PluginSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPluginSettings, UPluginSettings::StaticClass, TEXT("UPluginSettings"), &Z_Registration_Info_UClass_UPluginSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPluginSettings), 1225354972U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_PluginSettings_h_341831943(TEXT("/Script/RecoilAnimation"),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_PluginSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_PluginSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
