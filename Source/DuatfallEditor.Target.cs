using UnrealBuildTool;
public class DuatfallEditorTarget : TargetRules {
    public DuatfallEditorTarget(TargetInfo Target) : base(Target) {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        ExtraModuleNames.Add("Duatfall");
    }
}
