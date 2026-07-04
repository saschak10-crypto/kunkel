using UnrealBuildTool;
using System.Collections.Generic;

public class HackAndSlayEditorTarget : TargetRules
{
	public HackAndSlayEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.Latest;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("HackAndSlay");
	}
}
