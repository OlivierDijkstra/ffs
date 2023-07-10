// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RecoilAnimation/Public/HelperWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHelperWidget() {}
// Cross Module References
	RECOILANIMATION_API UClass* Z_Construct_UClass_UHelperWidget();
	RECOILANIMATION_API UClass* Z_Construct_UClass_UHelperWidget_NoRegister();
	RECOILANIMATION_API UClass* Z_Construct_UClass_URecoilAnimationComponent_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_RecoilAnimation();
// End Cross Module References
	static FName NAME_UHelperWidget_UpdateValues = FName(TEXT("UpdateValues"));
	void UHelperWidget::UpdateValues()
	{
		ProcessEvent(FindFunctionChecked(NAME_UHelperWidget_UpdateValues),NULL);
	}
	void UHelperWidget::StaticRegisterNativesUHelperWidget()
	{
	}
	struct Z_Construct_UFunction_UHelperWidget_UpdateValues_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHelperWidget_UpdateValues_Statics::Function_MetaDataParams[] = {
		{ "Category", "Update UI Values" },
		{ "ModuleRelativePath", "Public/HelperWidget.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHelperWidget_UpdateValues_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHelperWidget, nullptr, "UpdateValues", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHelperWidget_UpdateValues_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHelperWidget_UpdateValues_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHelperWidget_UpdateValues()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHelperWidget_UpdateValues_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHelperWidget);
	UClass* Z_Construct_UClass_UHelperWidget_NoRegister()
	{
		return UHelperWidget::StaticClass();
	}
	struct Z_Construct_UClass_UHelperWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimationComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AnimationComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAdvancedDisplay_MetaData[];
#endif
		static void NewProp_bAdvancedDisplay_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAdvancedDisplay;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHelperWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_RecoilAnimation,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UHelperWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UHelperWidget_UpdateValues, "UpdateValues" }, // 231062133
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHelperWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "HelperWidget.h" },
		{ "ModuleRelativePath", "Public/HelperWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHelperWidget_Statics::NewProp_AnimationComponent_MetaData[] = {
		{ "Category", "Base" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HelperWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UHelperWidget_Statics::NewProp_AnimationComponent = { "AnimationComponent", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UHelperWidget, AnimationComponent), Z_Construct_UClass_URecoilAnimationComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UHelperWidget_Statics::NewProp_AnimationComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UHelperWidget_Statics::NewProp_AnimationComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHelperWidget_Statics::NewProp_bAdvancedDisplay_MetaData[] = {
		{ "Category", "Display" },
		{ "ModuleRelativePath", "Public/HelperWidget.h" },
	};
#endif
	void Z_Construct_UClass_UHelperWidget_Statics::NewProp_bAdvancedDisplay_SetBit(void* Obj)
	{
		((UHelperWidget*)Obj)->bAdvancedDisplay = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UHelperWidget_Statics::NewProp_bAdvancedDisplay = { "bAdvancedDisplay", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UHelperWidget), &Z_Construct_UClass_UHelperWidget_Statics::NewProp_bAdvancedDisplay_SetBit, METADATA_PARAMS(Z_Construct_UClass_UHelperWidget_Statics::NewProp_bAdvancedDisplay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UHelperWidget_Statics::NewProp_bAdvancedDisplay_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHelperWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHelperWidget_Statics::NewProp_AnimationComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHelperWidget_Statics::NewProp_bAdvancedDisplay,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHelperWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHelperWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHelperWidget_Statics::ClassParams = {
		&UHelperWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UHelperWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UHelperWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UHelperWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UHelperWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UHelperWidget()
	{
		if (!Z_Registration_Info_UClass_UHelperWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHelperWidget.OuterSingleton, Z_Construct_UClass_UHelperWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHelperWidget.OuterSingleton;
	}
	template<> RECOILANIMATION_API UClass* StaticClass<UHelperWidget>()
	{
		return UHelperWidget::StaticClass();
	}
	UHelperWidget::UHelperWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHelperWidget);
	UHelperWidget::~UHelperWidget() {}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_HelperWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_HelperWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UHelperWidget, UHelperWidget::StaticClass, TEXT("UHelperWidget"), &Z_Registration_Info_UClass_UHelperWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHelperWidget), 1195964588U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_HelperWidget_h_2690222947(TEXT("/Script/RecoilAnimation"),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_HelperWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_HelperWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
