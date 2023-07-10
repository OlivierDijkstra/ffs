// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RecoilAnimationComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInputScale_PRAS;
struct FRecoilAnimData;
#ifdef RECOILANIMATION_RecoilAnimationComponent_generated_h
#error "RecoilAnimationComponent.generated.h already included, missing '#pragma once' in RecoilAnimationComponent.h"
#endif
#define RECOILANIMATION_RecoilAnimationComponent_generated_h

#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_39_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FRecoilAnimData_Statics; \
	RECOILANIMATION_API static class UScriptStruct* StaticStruct();


template<> RECOILANIMATION_API UScriptStruct* StaticStruct<struct FRecoilAnimData>();

#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_73_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMuteAxis_Statics; \
	RECOILANIMATION_API static class UScriptStruct* StaticStruct();


template<> RECOILANIMATION_API UScriptStruct* StaticStruct<struct FMuteAxis>();

#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_88_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStartRest_Statics; \
	RECOILANIMATION_API static class UScriptStruct* StaticStruct();


template<> RECOILANIMATION_API UScriptStruct* StaticStruct<struct FStartRest>();

#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_104_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAnimState_PRAS_Statics; \
	RECOILANIMATION_API static class UScriptStruct* StaticStruct();


template<> RECOILANIMATION_API UScriptStruct* StaticStruct<struct FAnimState_PRAS>();

#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_119_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FInputScale_PRAS_Statics; \
	RECOILANIMATION_API static class UScriptStruct* StaticStruct();


template<> RECOILANIMATION_API UScriptStruct* StaticStruct<struct FInputScale_PRAS>();

#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_SPARSE_DATA
#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCalculateTargetData); \
	DECLARE_FUNCTION(execAnimationUpdate); \
	DECLARE_FUNCTION(execHideUI); \
	DECLARE_FUNCTION(execShowUI); \
	DECLARE_FUNCTION(execSimulate); \
	DECLARE_FUNCTION(execGetDelta); \
	DECLARE_FUNCTION(execGetFireMode); \
	DECLARE_FUNCTION(execResetInputScale); \
	DECLARE_FUNCTION(execUnscaleInput); \
	DECLARE_FUNCTION(execScaleInput); \
	DECLARE_FUNCTION(execSaveData); \
	DECLARE_FUNCTION(execSetAimingStatus); \
	DECLARE_FUNCTION(execSetFireMode); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execPlay); \
	DECLARE_FUNCTION(execInit);


#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCalculateTargetData); \
	DECLARE_FUNCTION(execAnimationUpdate); \
	DECLARE_FUNCTION(execHideUI); \
	DECLARE_FUNCTION(execShowUI); \
	DECLARE_FUNCTION(execSimulate); \
	DECLARE_FUNCTION(execGetDelta); \
	DECLARE_FUNCTION(execGetFireMode); \
	DECLARE_FUNCTION(execResetInputScale); \
	DECLARE_FUNCTION(execUnscaleInput); \
	DECLARE_FUNCTION(execScaleInput); \
	DECLARE_FUNCTION(execSaveData); \
	DECLARE_FUNCTION(execSetAimingStatus); \
	DECLARE_FUNCTION(execSetFireMode); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execPlay); \
	DECLARE_FUNCTION(execInit);


#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_ACCESSORS
#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURecoilAnimationComponent(); \
	friend struct Z_Construct_UClass_URecoilAnimationComponent_Statics; \
public: \
	DECLARE_CLASS(URecoilAnimationComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RecoilAnimation"), NO_API) \
	DECLARE_SERIALIZER(URecoilAnimationComponent) \
	NO_API void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		AnimData=NETFIELD_REP_START, \
		InputScale, \
		OutRot, \
		OutLoc, \
		NETFIELD_REP_END=OutLoc	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_INCLASS \
private: \
	static void StaticRegisterNativesURecoilAnimationComponent(); \
	friend struct Z_Construct_UClass_URecoilAnimationComponent_Statics; \
public: \
	DECLARE_CLASS(URecoilAnimationComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/RecoilAnimation"), NO_API) \
	DECLARE_SERIALIZER(URecoilAnimationComponent) \
	NO_API void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		AnimData=NETFIELD_REP_START, \
		InputScale, \
		OutRot, \
		OutLoc, \
		NETFIELD_REP_END=OutLoc	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URecoilAnimationComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URecoilAnimationComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URecoilAnimationComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URecoilAnimationComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URecoilAnimationComponent(URecoilAnimationComponent&&); \
	NO_API URecoilAnimationComponent(const URecoilAnimationComponent&); \
public: \
	NO_API virtual ~URecoilAnimationComponent();


#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URecoilAnimationComponent(URecoilAnimationComponent&&); \
	NO_API URecoilAnimationComponent(const URecoilAnimationComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URecoilAnimationComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URecoilAnimationComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(URecoilAnimationComponent) \
	NO_API virtual ~URecoilAnimationComponent();


#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_205_PROLOG
#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_SPARSE_DATA \
	FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_RPC_WRAPPERS \
	FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_ACCESSORS \
	FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_INCLASS \
	FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_SPARSE_DATA \
	FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_ACCESSORS \
	FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_INCLASS_NO_PURE_DECLS \
	FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h_208_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RECOILANIMATION_API UClass* StaticClass<class URecoilAnimationComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_RecoilAnimation_Source_RecoilAnimation_Public_RecoilAnimationComponent_h


#define FOREACH_ENUM_ESOLVERTYPE_PRAS(op) \
	op(Legacy) \
	op(Advanced) 
#define FOREACH_ENUM_EFIREMODE_PRAS(op) \
	op(Semi) \
	op(Auto) \
	op(Burst) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
