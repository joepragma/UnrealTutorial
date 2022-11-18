// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UnrealTutorialEditorTarget : TargetRules
{
	public UnrealTutorialEditorTarget(TargetInfo target) : base(target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new[] { "UnrealTutorial" });

		// *** Copied from Pragma ***
		if (target.Platform == UnrealTargetPlatform.Mac)
		{
			bOverrideBuildEnvironment = true;
			// DO NOT COMMENT THIS OUT, INSTEAD UPDATE YOUR XCODE
			AdditionalCompilerArguments = "-Wno-unused-but-set-variable";
		}
	}
}