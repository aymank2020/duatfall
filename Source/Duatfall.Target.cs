using UnrealBuildTool;
public class DuatfallTarget : TargetRules {
    public DuatfallTarget(TargetInfo Target) : base(Target) {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        ExtraModuleNames.Add("Duatfall");
    }
}
