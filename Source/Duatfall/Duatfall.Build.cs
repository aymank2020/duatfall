using UnrealBuildTool;
using System.IO;
public class Duatfall : ModuleRules {
    public Duatfall(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PrivateDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });
        PrivateIncludePaths.Add(Path.GetFullPath(Path.Combine(ModuleDirectory, "../../Core")));
        bEnableExceptions = true;
    }
}
