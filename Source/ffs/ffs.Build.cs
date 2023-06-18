// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ffs : ModuleRules
{
    public ffs(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"UMG",
			"HeadMountedDisplay",
			"EnhancedInput",
			"GASCompanion",
			"GameplayAbilities",
			"GameFeatures",
			"AGRPRO",
			// "RecoilAnimations",
        });

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "GameplayTasks",
                "GameplayTags",
            }
        );
    }
}