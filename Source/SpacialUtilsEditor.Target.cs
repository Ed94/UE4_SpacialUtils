// Copyright Epic Games, Inc. All Rights Reserved.

// UHT
using UnrealBuildTool;
// C#
using System.Collections.Generic;



public class SpacialUtilsEditorTarget : TargetRules
{
	public SpacialUtilsEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.Add("SpacialUtils");
	}
}
