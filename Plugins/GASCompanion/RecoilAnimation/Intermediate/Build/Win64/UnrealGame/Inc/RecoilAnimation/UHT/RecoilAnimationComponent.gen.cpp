// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RecoilAnimation/Public/RecoilAnimationComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRecoilAnimationComponent() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector4();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UCurveVector_NoRegister();
	RECOILANIMATION_API UClass* Z_Construct_UClass_UHelperWidget_NoRegister();
	RECOILANIMATION_API UClass* Z_Construct_UClass_URecoilAnimationComponent();
	RECOILANIMATION_API UClass* Z_Construct_UClass_URecoilAnimationComponent_NoRegister();
	RECOILANIMATION_API UClass* Z_Construct_UClass_UStoredData_NoRegister();
	RECOILANIMATION_API UEnum* Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS();
	RECOILANIMATION_API UEnum* Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS();
	RECOILANIMATION_API UScriptStruct* Z_Construct_UScriptStruct_FAnimState_PRAS();
	RECOILANIMATION_API UScriptStruct* Z_Construct_UScriptStruct_FInputScale_PRAS();
	RECOILANIMATION_API UScriptStruct* Z_Construct_UScriptStruct_FMuteAxis();
	RECOILANIMATION_API UScriptStruct* Z_Construct_UScriptStruct_FRecoilAnimData();
	RECOILANIMATION_API UScriptStruct* Z_Construct_UScriptStruct_FStartRest();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_RecoilAnimation();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESolverType_PRAS;
	static UEnum* ESolverType_PRAS_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESolverType_PRAS.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESolverType_PRAS.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS, (UObject*)Z_Construct_UPackage__Script_RecoilAnimation(), TEXT("ESolverType_PRAS"));
		}
		return Z_Registration_Info_UEnum_ESolverType_PRAS.OuterSingleton;
	}
	template<> RECOILANIMATION_API UEnum* StaticEnum<ESolverType_PRAS>()
	{
		return ESolverType_PRAS_StaticEnum();
	}
	struct Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS_Statics::Enumerators[] = {
		{ "Legacy", (int64)Legacy },
		{ "Advanced", (int64)Advanced },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS_Statics::Enum_MetaDataParams[] = {
		{ "Advanced.DisplayName", "Advanced" },
		{ "Advanced.Name", "Advanced" },
		{ "Advanced.ToolTip", "Based on curves" },
		{ "BlueprintType", "true" },
		{ "Legacy.DisplayName", "Legacy" },
		{ "Legacy.Name", "Legacy" },
		{ "Legacy.ToolTip", "Based on Lerp and SpringInterp" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_RecoilAnimation,
		nullptr,
		"ESolverType_PRAS",
		"ESolverType_PRAS",
		Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS()
	{
		if (!Z_Registration_Info_UEnum_ESolverType_PRAS.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESolverType_PRAS.InnerSingleton, Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESolverType_PRAS.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFireMode_PRAS;
	static UEnum* EFireMode_PRAS_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EFireMode_PRAS.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EFireMode_PRAS.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS, (UObject*)Z_Construct_UPackage__Script_RecoilAnimation(), TEXT("EFireMode_PRAS"));
		}
		return Z_Registration_Info_UEnum_EFireMode_PRAS.OuterSingleton;
	}
	template<> RECOILANIMATION_API UEnum* StaticEnum<EFireMode_PRAS>()
	{
		return EFireMode_PRAS_StaticEnum();
	}
	struct Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS_Statics::Enumerators[] = {
		{ "Semi", (int64)Semi },
		{ "Auto", (int64)Auto },
		{ "Burst", (int64)Burst },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS_Statics::Enum_MetaDataParams[] = {
		{ "Auto.DisplayName", "Auto" },
		{ "Auto.Name", "Auto" },
		{ "BlueprintType", "true" },
		{ "Burst.DisplayName", "Burst" },
		{ "Burst.Name", "Burst" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
		{ "Semi.DisplayName", "Semi" },
		{ "Semi.Name", "Semi" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_RecoilAnimation,
		nullptr,
		"EFireMode_PRAS",
		"EFireMode_PRAS",
		Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS()
	{
		if (!Z_Registration_Info_UEnum_EFireMode_PRAS.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFireMode_PRAS.InnerSingleton, Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EFireMode_PRAS.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RecoilAnimData;
class UScriptStruct* FRecoilAnimData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RecoilAnimData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RecoilAnimData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRecoilAnimData, (UObject*)Z_Construct_UPackage__Script_RecoilAnimation(), TEXT("RecoilAnimData"));
	}
	return Z_Registration_Info_UScriptStruct_RecoilAnimData.OuterSingleton;
}
template<> RECOILANIMATION_API UScriptStruct* StaticStruct<FRecoilAnimData>()
{
	return FRecoilAnimData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FRecoilAnimData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SingleRot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SingleRot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SingleLoc_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SingleLoc;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutoRot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AutoRot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutoLoc_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AutoLoc;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RestRot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RestRot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RestLoc_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RestLoc;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SlotName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SolverType_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_SolverType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StoredData_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StoredData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRecoilAnimData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** Essentials for procedural animation solver */" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
		{ "ToolTip", "Essentials for procedural animation solver" },
	};
#endif
	void* Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRecoilAnimData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SingleRot_MetaData[] = {
		{ "Category", "Advanced | Curve" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SingleRot = { "SingleRot", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FRecoilAnimData, SingleRot), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SingleRot_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SingleRot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SingleLoc_MetaData[] = {
		{ "Category", "Advanced | Curve" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SingleLoc = { "SingleLoc", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FRecoilAnimData, SingleLoc), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SingleLoc_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SingleLoc_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_AutoRot_MetaData[] = {
		{ "Category", "Advanced | Curve" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_AutoRot = { "AutoRot", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FRecoilAnimData, AutoRot), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_AutoRot_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_AutoRot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_AutoLoc_MetaData[] = {
		{ "Category", "Advanced | Curve" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_AutoLoc = { "AutoLoc", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FRecoilAnimData, AutoLoc), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_AutoLoc_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_AutoLoc_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_RestRot_MetaData[] = {
		{ "Category", "Advanced | Curve" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_RestRot = { "RestRot", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FRecoilAnimData, RestRot), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_RestRot_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_RestRot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_RestLoc_MetaData[] = {
		{ "Category", "Advanced | Curve" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_RestLoc = { "RestLoc", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FRecoilAnimData, RestLoc), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_RestLoc_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_RestLoc_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SlotName_MetaData[] = {
		{ "Category", "Common" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FRecoilAnimData, SlotName), METADATA_PARAMS(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SlotName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SlotName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SolverType_MetaData[] = {
		{ "Category", "Common" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SolverType = { "SolverType", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FRecoilAnimData, SolverType), Z_Construct_UEnum_RecoilAnimation_ESolverType_PRAS, METADATA_PARAMS(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SolverType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SolverType_MetaData)) }; // 2679816925
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_StoredData_MetaData[] = {
		{ "Category", "Values" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_StoredData = { "StoredData", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FRecoilAnimData, StoredData), Z_Construct_UClass_UStoredData_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_StoredData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_StoredData_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRecoilAnimData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SingleRot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SingleLoc,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_AutoRot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_AutoLoc,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_RestRot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_RestLoc,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SlotName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_SolverType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewProp_StoredData,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRecoilAnimData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RecoilAnimation,
		nullptr,
		&NewStructOps,
		"RecoilAnimData",
		sizeof(FRecoilAnimData),
		alignof(FRecoilAnimData),
		Z_Construct_UScriptStruct_FRecoilAnimData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRecoilAnimData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FRecoilAnimData()
	{
		if (!Z_Registration_Info_UScriptStruct_RecoilAnimData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RecoilAnimData.InnerSingleton, Z_Construct_UScriptStruct_FRecoilAnimData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_RecoilAnimData.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MuteAxis;
class UScriptStruct* FMuteAxis::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MuteAxis.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MuteAxis.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMuteAxis, (UObject*)Z_Construct_UPackage__Script_RecoilAnimation(), TEXT("MuteAxis"));
	}
	return Z_Registration_Info_UScriptStruct_MuteAxis.OuterSingleton;
}
template<> RECOILANIMATION_API UScriptStruct* StaticStruct<FMuteAxis>()
{
	return FMuteAxis::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FMuteAxis_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_X_MetaData[];
#endif
		static void NewProp_X_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_X;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Y_MetaData[];
#endif
		static void NewProp_Y_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Y;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Z_MetaData[];
#endif
		static void NewProp_Z_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Z;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMuteAxis_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** Disables axis */" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
		{ "ToolTip", "Disables axis" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMuteAxis_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMuteAxis>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_X_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_X_SetBit(void* Obj)
	{
		((FMuteAxis*)Obj)->X = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FMuteAxis), &Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_X_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_X_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_X_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Y_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Y_SetBit(void* Obj)
	{
		((FMuteAxis*)Obj)->Y = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FMuteAxis), &Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Y_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Y_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Y_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Z_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Z_SetBit(void* Obj)
	{
		((FMuteAxis*)Obj)->Z = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Z = { "Z", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FMuteAxis), &Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Z_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Z_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Z_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMuteAxis_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_X,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Y,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMuteAxis_Statics::NewProp_Z,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMuteAxis_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RecoilAnimation,
		nullptr,
		&NewStructOps,
		"MuteAxis",
		sizeof(FMuteAxis),
		alignof(FMuteAxis),
		Z_Construct_UScriptStruct_FMuteAxis_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMuteAxis_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMuteAxis_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMuteAxis_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMuteAxis()
	{
		if (!Z_Registration_Info_UScriptStruct_MuteAxis.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MuteAxis.InnerSingleton, Z_Construct_UScriptStruct_FMuteAxis_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_MuteAxis.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_StartRest;
class UScriptStruct* FStartRest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_StartRest.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_StartRest.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FStartRest, (UObject*)Z_Construct_UPackage__Script_RecoilAnimation(), TEXT("StartRest"));
	}
	return Z_Registration_Info_UScriptStruct_StartRest.OuterSingleton;
}
template<> RECOILANIMATION_API UScriptStruct* StaticStruct<FStartRest>()
{
	return FStartRest::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FStartRest_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStartRest_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FStartRest_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStartRest>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStartRest_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RecoilAnimation,
		nullptr,
		&NewStructOps,
		"StartRest",
		sizeof(FStartRest),
		alignof(FStartRest),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FStartRest_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStartRest_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FStartRest()
	{
		if (!Z_Registration_Info_UScriptStruct_StartRest.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_StartRest.InnerSingleton, Z_Construct_UScriptStruct_FStartRest_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_StartRest.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimState_PRAS;
class UScriptStruct* FAnimState_PRAS::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimState_PRAS.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimState_PRAS.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimState_PRAS, (UObject*)Z_Construct_UPackage__Script_RecoilAnimation(), TEXT("AnimState_PRAS"));
	}
	return Z_Registration_Info_UScriptStruct_AnimState_PRAS.OuterSingleton;
}
template<> RECOILANIMATION_API UScriptStruct* StaticStruct<FAnimState_PRAS>()
{
	return FAnimState_PRAS::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimState_PRAS_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimState_PRAS_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimState_PRAS_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimState_PRAS>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimState_PRAS_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RecoilAnimation,
		nullptr,
		&NewStructOps,
		"AnimState_PRAS",
		sizeof(FAnimState_PRAS),
		alignof(FAnimState_PRAS),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimState_PRAS_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimState_PRAS_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAnimState_PRAS()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimState_PRAS.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimState_PRAS.InnerSingleton, Z_Construct_UScriptStruct_FAnimState_PRAS_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimState_PRAS.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_InputScale_PRAS;
class UScriptStruct* FInputScale_PRAS::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_InputScale_PRAS.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_InputScale_PRAS.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInputScale_PRAS, (UObject*)Z_Construct_UPackage__Script_RecoilAnimation(), TEXT("InputScale_PRAS"));
	}
	return Z_Registration_Info_UScriptStruct_InputScale_PRAS.OuterSingleton;
}
template<> RECOILANIMATION_API UScriptStruct* StaticStruct<FInputScale_PRAS>()
{
	return FInputScale_PRAS::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FInputScale_PRAS_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Pitch_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Pitch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Kick_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Kick;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KickR_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_KickR;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KickUp_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_KickUp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Yaw_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Yaw;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Roll_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Roll;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Noise_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Noise;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Progression_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Progression;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInputScale_PRAS>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Pitch_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Pitch = { "Pitch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FInputScale_PRAS, Pitch), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Pitch_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Pitch_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Kick_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Kick = { "Kick", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FInputScale_PRAS, Kick), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Kick_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Kick_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_KickR_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_KickR = { "KickR", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FInputScale_PRAS, KickR), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_KickR_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_KickR_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_KickUp_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_KickUp = { "KickUp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FInputScale_PRAS, KickUp), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_KickUp_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_KickUp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Yaw_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Yaw = { "Yaw", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FInputScale_PRAS, Yaw), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Yaw_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Yaw_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Roll_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Roll = { "Roll", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FInputScale_PRAS, Roll), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Roll_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Roll_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Noise_MetaData[] = {
		{ "Category", "General" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Noise = { "Noise", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FInputScale_PRAS, Noise), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Noise_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Noise_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Progression_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "// X - Pitch, Y - Z offset\n" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
		{ "ToolTip", "X - Pitch, Y - Z offset" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Progression = { "Progression", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FInputScale_PRAS, Progression), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Progression_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Progression_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Pitch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Kick,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_KickR,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_KickUp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Yaw,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Roll,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Noise,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewProp_Progression,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RecoilAnimation,
		nullptr,
		&NewStructOps,
		"InputScale_PRAS",
		sizeof(FInputScale_PRAS),
		alignof(FInputScale_PRAS),
		Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FInputScale_PRAS()
	{
		if (!Z_Registration_Info_UScriptStruct_InputScale_PRAS.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_InputScale_PRAS.InnerSingleton, Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_InputScale_PRAS.InnerSingleton;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execCalculateTargetData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CalculateTargetData();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execAnimationUpdate)
	{
		P_GET_STRUCT(FVector,Z_Param_VectorAlpha);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AnimationUpdate(Z_Param_VectorAlpha);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execHideUI)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HideUI();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execShowUI)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ShowUI();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execSimulate)
	{
		P_GET_UBOOL(Z_Param_bStartSim);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Simulate(Z_Param_bStartSim);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execGetDelta)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetDelta();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execGetFireMode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TEnumAsByte<EFireMode_PRAS>*)Z_Param__Result=P_THIS->GetFireMode();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execResetInputScale)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetInputScale();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execUnscaleInput)
	{
		P_GET_STRUCT(FInputScale_PRAS,Z_Param_NewScale);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnscaleInput(Z_Param_NewScale);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execScaleInput)
	{
		P_GET_STRUCT(FInputScale_PRAS,Z_Param_NewScale);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ScaleInput(Z_Param_NewScale);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execSaveData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SaveData();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execSetAimingStatus)
	{
		P_GET_UBOOL(Z_Param_bStatus);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAimingStatus(Z_Param_bStatus);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execSetFireMode)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_NewMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFireMode(EFireMode_PRAS(Z_Param_NewMode));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execStop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Stop();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execPlay)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Play();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(URecoilAnimationComponent::execInit)
	{
		P_GET_STRUCT(FRecoilAnimData,Z_Param_Data);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Rate);
		P_GET_PROPERTY(FIntProperty,Z_Param_Bursts);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Init(Z_Param_Data,Z_Param_Rate,Z_Param_Bursts);
		P_NATIVE_END;
	}
	void URecoilAnimationComponent::StaticRegisterNativesURecoilAnimationComponent()
	{
		UClass* Class = URecoilAnimationComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AnimationUpdate", &URecoilAnimationComponent::execAnimationUpdate },
			{ "CalculateTargetData", &URecoilAnimationComponent::execCalculateTargetData },
			{ "GetDelta", &URecoilAnimationComponent::execGetDelta },
			{ "GetFireMode", &URecoilAnimationComponent::execGetFireMode },
			{ "HideUI", &URecoilAnimationComponent::execHideUI },
			{ "Init", &URecoilAnimationComponent::execInit },
			{ "Play", &URecoilAnimationComponent::execPlay },
			{ "ResetInputScale", &URecoilAnimationComponent::execResetInputScale },
			{ "SaveData", &URecoilAnimationComponent::execSaveData },
			{ "ScaleInput", &URecoilAnimationComponent::execScaleInput },
			{ "SetAimingStatus", &URecoilAnimationComponent::execSetAimingStatus },
			{ "SetFireMode", &URecoilAnimationComponent::execSetFireMode },
			{ "ShowUI", &URecoilAnimationComponent::execShowUI },
			{ "Simulate", &URecoilAnimationComponent::execSimulate },
			{ "Stop", &URecoilAnimationComponent::execStop },
			{ "UnscaleInput", &URecoilAnimationComponent::execUnscaleInput },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics
	{
		struct RecoilAnimationComponent_eventAnimationUpdate_Parms
		{
			FVector VectorAlpha;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_VectorAlpha;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics::NewProp_VectorAlpha = { "VectorAlpha", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecoilAnimationComponent_eventAnimationUpdate_Parms, VectorAlpha), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics::NewProp_VectorAlpha,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "AnimationUpdate", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics::RecoilAnimationComponent_eventAnimationUpdate_Parms), Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_CalculateTargetData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_CalculateTargetData_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_CalculateTargetData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "CalculateTargetData", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_CalculateTargetData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_CalculateTargetData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_CalculateTargetData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_CalculateTargetData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics
	{
		struct RecoilAnimationComponent_eventGetDelta_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecoilAnimationComponent_eventGetDelta_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics::Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "Comment", "/** Returns time since the last shot */" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
		{ "ToolTip", "Returns time since the last shot" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "GetDelta", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics::RecoilAnimationComponent_eventGetDelta_Parms), Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_GetDelta()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_GetDelta_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics
	{
		struct RecoilAnimationComponent_eventGetFireMode_Parms
		{
			TEnumAsByte<EFireMode_PRAS> ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecoilAnimationComponent_eventGetFireMode_Parms, ReturnValue), Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS, METADATA_PARAMS(nullptr, 0) }; // 703739452
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "GetFireMode", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics::RecoilAnimationComponent_eventGetFireMode_Parms), Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_HideUI_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_HideUI_Statics::Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_HideUI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "HideUI", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_HideUI_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_HideUI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_HideUI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_HideUI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics
	{
		struct RecoilAnimationComponent_eventInit_Parms
		{
			FRecoilAnimData Data;
			float Rate;
			int32 Bursts;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Data;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Rate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Rate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bursts_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_Bursts;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecoilAnimationComponent_eventInit_Parms, Data), Z_Construct_UScriptStruct_FRecoilAnimData, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Data_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Data_MetaData)) }; // 3801075470
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Rate_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Rate = { "Rate", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecoilAnimationComponent_eventInit_Parms, Rate), METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Rate_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Rate_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Bursts_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Bursts = { "Bursts", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecoilAnimationComponent_eventInit_Parms, Bursts), METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Bursts_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Bursts_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Rate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::NewProp_Bursts,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::Function_MetaDataParams[] = {
		{ "Category", "Essentials" },
		{ "CPP_Default_Bursts", "0" },
		{ "CPP_Default_Rate", "0.000000" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "Init", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::RecoilAnimationComponent_eventInit_Parms), Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_Init()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_Init_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_Play_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_Play_Statics::Function_MetaDataParams[] = {
		{ "Category", "Essentials" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_Play_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "Play", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_Play_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_Play_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_Play()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_Play_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_ResetInputScale_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_ResetInputScale_Statics::Function_MetaDataParams[] = {
		{ "Category", "Essentials" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_ResetInputScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "ResetInputScale", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_ResetInputScale_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_ResetInputScale_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_ResetInputScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_ResetInputScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_SaveData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_SaveData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Essentials" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_SaveData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "SaveData", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_SaveData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_SaveData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_SaveData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_SaveData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics
	{
		struct RecoilAnimationComponent_eventScaleInput_Parms
		{
			FInputScale_PRAS NewScale;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewScale;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics::NewProp_NewScale = { "NewScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecoilAnimationComponent_eventScaleInput_Parms, NewScale), Z_Construct_UScriptStruct_FInputScale_PRAS, METADATA_PARAMS(nullptr, 0) }; // 920599549
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics::NewProp_NewScale,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics::Function_MetaDataParams[] = {
		{ "Category", "Essentials" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "ScaleInput", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics::RecoilAnimationComponent_eventScaleInput_Parms), Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics
	{
		struct RecoilAnimationComponent_eventSetAimingStatus_Parms
		{
			bool bStatus;
		};
		static void NewProp_bStatus_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStatus;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::NewProp_bStatus_SetBit(void* Obj)
	{
		((RecoilAnimationComponent_eventSetAimingStatus_Parms*)Obj)->bStatus = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::NewProp_bStatus = { "bStatus", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(RecoilAnimationComponent_eventSetAimingStatus_Parms), &Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::NewProp_bStatus_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::NewProp_bStatus,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "Essentials" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "SetAimingStatus", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::RecoilAnimationComponent_eventSetAimingStatus_Parms), Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics
	{
		struct RecoilAnimationComponent_eventSetFireMode_Parms
		{
			TEnumAsByte<EFireMode_PRAS> NewMode;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_NewMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics::NewProp_NewMode = { "NewMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecoilAnimationComponent_eventSetFireMode_Parms, NewMode), Z_Construct_UEnum_RecoilAnimation_EFireMode_PRAS, METADATA_PARAMS(nullptr, 0) }; // 703739452
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics::NewProp_NewMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Essentials" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "SetFireMode", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics::RecoilAnimationComponent_eventSetFireMode_Parms), Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_ShowUI_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_ShowUI_Statics::Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_ShowUI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "ShowUI", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_ShowUI_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_ShowUI_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_ShowUI()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_ShowUI_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics
	{
		struct RecoilAnimationComponent_eventSimulate_Parms
		{
			bool bStartSim;
		};
		static void NewProp_bStartSim_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStartSim;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::NewProp_bStartSim_SetBit(void* Obj)
	{
		((RecoilAnimationComponent_eventSimulate_Parms*)Obj)->bStartSim = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::NewProp_bStartSim = { "bStartSim", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(RecoilAnimationComponent_eventSimulate_Parms), &Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::NewProp_bStartSim_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::NewProp_bStartSim,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Debug" },
		{ "DevelopmentOnly", "" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "Simulate", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::RecoilAnimationComponent_eventSimulate_Parms), Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_Simulate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_Simulate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_Stop_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_Stop_Statics::Function_MetaDataParams[] = {
		{ "Category", "Essentials" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_Stop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "Stop", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_Stop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_Stop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_Stop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_Stop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics
	{
		struct RecoilAnimationComponent_eventUnscaleInput_Parms
		{
			FInputScale_PRAS NewScale;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewScale;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics::NewProp_NewScale = { "NewScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(RecoilAnimationComponent_eventUnscaleInput_Parms, NewScale), Z_Construct_UScriptStruct_FInputScale_PRAS, METADATA_PARAMS(nullptr, 0) }; // 920599549
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics::NewProp_NewScale,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics::Function_MetaDataParams[] = {
		{ "Category", "Essentials" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URecoilAnimationComponent, nullptr, "UnscaleInput", nullptr, nullptr, sizeof(Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics::RecoilAnimationComponent_eventUnscaleInput_Parms), Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URecoilAnimationComponent);
	UClass* Z_Construct_UClass_URecoilAnimationComponent_NoRegister()
	{
		return URecoilAnimationComponent::StaticClass();
	}
	struct Z_Construct_UClass_URecoilAnimationComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MuteRot_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MuteRot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MuteLoc_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MuteLoc;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AnimData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputScale_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InputScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OutRot_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutRot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OutLoc_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutLoc;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WidgetClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_WidgetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TempRot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TempRot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TempLoc_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TempLoc;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Widget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Widget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsAiming_MetaData[];
#endif
		static void NewProp_bIsAiming_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAiming;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URecoilAnimationComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_RecoilAnimation,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_URecoilAnimationComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_URecoilAnimationComponent_AnimationUpdate, "AnimationUpdate" }, // 2962711684
		{ &Z_Construct_UFunction_URecoilAnimationComponent_CalculateTargetData, "CalculateTargetData" }, // 4022611531
		{ &Z_Construct_UFunction_URecoilAnimationComponent_GetDelta, "GetDelta" }, // 3885610670
		{ &Z_Construct_UFunction_URecoilAnimationComponent_GetFireMode, "GetFireMode" }, // 28719750
		{ &Z_Construct_UFunction_URecoilAnimationComponent_HideUI, "HideUI" }, // 2770514594
		{ &Z_Construct_UFunction_URecoilAnimationComponent_Init, "Init" }, // 2259692858
		{ &Z_Construct_UFunction_URecoilAnimationComponent_Play, "Play" }, // 3219557914
		{ &Z_Construct_UFunction_URecoilAnimationComponent_ResetInputScale, "ResetInputScale" }, // 1765103091
		{ &Z_Construct_UFunction_URecoilAnimationComponent_SaveData, "SaveData" }, // 2631299951
		{ &Z_Construct_UFunction_URecoilAnimationComponent_ScaleInput, "ScaleInput" }, // 3921273446
		{ &Z_Construct_UFunction_URecoilAnimationComponent_SetAimingStatus, "SetAimingStatus" }, // 2539999807
		{ &Z_Construct_UFunction_URecoilAnimationComponent_SetFireMode, "SetFireMode" }, // 3735668140
		{ &Z_Construct_UFunction_URecoilAnimationComponent_ShowUI, "ShowUI" }, // 3988861440
		{ &Z_Construct_UFunction_URecoilAnimationComponent_Simulate, "Simulate" }, // 3328137669
		{ &Z_Construct_UFunction_URecoilAnimationComponent_Stop, "Stop" }, // 4124423939
		{ &Z_Construct_UFunction_URecoilAnimationComponent_UnscaleInput, "UnscaleInput" }, // 360165713
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "RecoilAnimation" },
		{ "IncludePath", "RecoilAnimationComponent.h" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_MuteRot_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_MuteRot = { "MuteRot", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URecoilAnimationComponent, MuteRot), Z_Construct_UScriptStruct_FMuteAxis, METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_MuteRot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_MuteRot_MetaData)) }; // 1645869385
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_MuteLoc_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_MuteLoc = { "MuteLoc", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URecoilAnimationComponent, MuteLoc), Z_Construct_UScriptStruct_FMuteAxis, METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_MuteLoc_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_MuteLoc_MetaData)) }; // 1645869385
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_AnimData_MetaData[] = {
		{ "Category", "Recoil Animation" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_AnimData = { "AnimData", nullptr, (EPropertyFlags)0x0010000000000024, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URecoilAnimationComponent, AnimData), Z_Construct_UScriptStruct_FRecoilAnimData, METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_AnimData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_AnimData_MetaData)) }; // 3801075470
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_InputScale_MetaData[] = {
		{ "Category", "Recoil Animation" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_InputScale = { "InputScale", nullptr, (EPropertyFlags)0x0010000000000024, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URecoilAnimationComponent, InputScale), Z_Construct_UScriptStruct_FInputScale_PRAS, METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_InputScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_InputScale_MetaData)) }; // 920599549
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_OutRot_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Recoil Animation Output" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_OutRot = { "OutRot", nullptr, (EPropertyFlags)0x0040000000000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URecoilAnimationComponent, OutRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_OutRot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_OutRot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_OutLoc_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Recoil Animation Output" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_OutLoc = { "OutLoc", nullptr, (EPropertyFlags)0x0040000000000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URecoilAnimationComponent, OutLoc), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_OutLoc_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_OutLoc_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_WidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_WidgetClass = { "WidgetClass", nullptr, (EPropertyFlags)0x0044000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URecoilAnimationComponent, WidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_WidgetClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_WidgetClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_TempRot_MetaData[] = {
		{ "Comment", "/** Temporary container for rotation curve */" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
		{ "ToolTip", "Temporary container for rotation curve" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_TempRot = { "TempRot", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URecoilAnimationComponent, TempRot), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_TempRot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_TempRot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_TempLoc_MetaData[] = {
		{ "Comment", "/** Temporary container for location curve */" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
		{ "ToolTip", "Temporary container for location curve" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_TempLoc = { "TempLoc", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URecoilAnimationComponent, TempLoc), Z_Construct_UClass_UCurveVector_NoRegister, METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_TempLoc_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_TempLoc_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_Widget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_Widget = { "Widget", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(URecoilAnimationComponent, Widget), Z_Construct_UClass_UHelperWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_Widget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_Widget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_bIsAiming_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Essentials" },
		{ "ModuleRelativePath", "Public/RecoilAnimationComponent.h" },
	};
#endif
	void Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_bIsAiming_SetBit(void* Obj)
	{
		((URecoilAnimationComponent*)Obj)->bIsAiming = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_bIsAiming = { "bIsAiming", nullptr, (EPropertyFlags)0x0040000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(URecoilAnimationComponent), &Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_bIsAiming_SetBit, METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_bIsAiming_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_bIsAiming_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URecoilAnimationComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_MuteRot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_MuteLoc,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_AnimData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_InputScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_OutRot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_OutLoc,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_WidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_TempRot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_TempLoc,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_Widget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URecoilAnimationComponent_Statics::NewProp_bIsAiming,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URecoilAnimationComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URecoilAnimationComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URecoilAnimationComponent_Statics::ClassParams = {
		&URecoilAnimationComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_URecoilAnimationComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_URecoilAnimationComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_URecoilAnimationComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_URecoilAnimationComponent()
	{
		if (!Z_Registration_Info_UClass_URecoilAnimationComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URecoilAnimationComponent.OuterSingleton, Z_Construct_UClass_URecoilAnimationComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URecoilAnimationComponent.OuterSingleton;
	}
	template<> RECOILANIMATION_API UClass* StaticClass<URecoilAnimationComponent>()
	{
		return URecoilAnimationComponent::StaticClass();
	}

	void URecoilAnimationComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_AnimData(TEXT("AnimData"));
		static const FName Name_InputScale(TEXT("InputScale"));
		static const FName Name_OutRot(TEXT("OutRot"));
		static const FName Name_OutLoc(TEXT("OutLoc"));

		const bool bIsValid = true
			&& Name_AnimData == ClassReps[(int32)ENetFields_Private::AnimData].Property->GetFName()
			&& Name_InputScale == ClassReps[(int32)ENetFields_Private::InputScale].Property->GetFName()
			&& Name_OutRot == ClassReps[(int32)ENetFields_Private::OutRot].Property->GetFName()
			&& Name_OutLoc == ClassReps[(int32)ENetFields_Private::OutLoc].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in URecoilAnimationComponent"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URecoilAnimationComponent);
	URecoilAnimationComponent::~URecoilAnimationComponent() {}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_Statics::EnumInfo[] = {
		{ ESolverType_PRAS_StaticEnum, TEXT("ESolverType_PRAS"), &Z_Registration_Info_UEnum_ESolverType_PRAS, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2679816925U) },
		{ EFireMode_PRAS_StaticEnum, TEXT("EFireMode_PRAS"), &Z_Registration_Info_UEnum_EFireMode_PRAS, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 703739452U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_Statics::ScriptStructInfo[] = {
		{ FRecoilAnimData::StaticStruct, Z_Construct_UScriptStruct_FRecoilAnimData_Statics::NewStructOps, TEXT("RecoilAnimData"), &Z_Registration_Info_UScriptStruct_RecoilAnimData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRecoilAnimData), 3801075470U) },
		{ FMuteAxis::StaticStruct, Z_Construct_UScriptStruct_FMuteAxis_Statics::NewStructOps, TEXT("MuteAxis"), &Z_Registration_Info_UScriptStruct_MuteAxis, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMuteAxis), 1645869385U) },
		{ FStartRest::StaticStruct, Z_Construct_UScriptStruct_FStartRest_Statics::NewStructOps, TEXT("StartRest"), &Z_Registration_Info_UScriptStruct_StartRest, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FStartRest), 2101935157U) },
		{ FAnimState_PRAS::StaticStruct, Z_Construct_UScriptStruct_FAnimState_PRAS_Statics::NewStructOps, TEXT("AnimState_PRAS"), &Z_Registration_Info_UScriptStruct_AnimState_PRAS, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimState_PRAS), 378391896U) },
		{ FInputScale_PRAS::StaticStruct, Z_Construct_UScriptStruct_FInputScale_PRAS_Statics::NewStructOps, TEXT("InputScale_PRAS"), &Z_Registration_Info_UScriptStruct_InputScale_PRAS, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInputScale_PRAS), 920599549U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URecoilAnimationComponent, URecoilAnimationComponent::StaticClass, TEXT("URecoilAnimationComponent"), &Z_Registration_Info_UClass_URecoilAnimationComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URecoilAnimationComponent), 1627026117U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_3218355664(TEXT("/Script/RecoilAnimation"),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
