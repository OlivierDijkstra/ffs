using UnrealBuildTool;

public class ffs : ModuleRules
{
    public ffs(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "UMG",
                "HeadMountedDisplay",
                "EnhancedInput",
                "Niagara",
                "GASCompanion",
                "GameplayAbilities",
                "GameFeatures",
                "AGRPRO",
                "RecoilAnimation",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "GameplayTasks",
                "GameplayTags",
            }
        );
    }
}