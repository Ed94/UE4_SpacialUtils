// Copyright Epic Games, Inc. All Rights Reserved.

// UHT`
using UnrealBuildTool;
// C#
using System.Collections.Generic;



public class SpacialUtilsTarget : TargetRules
{
	public SpacialUtilsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.Add("SpacialUtils");
	}
}
