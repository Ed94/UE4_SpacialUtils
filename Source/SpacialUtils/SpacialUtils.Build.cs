// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SpacialUtils : ModuleRules
{
	public SpacialUtils(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange
		(
			new string[] 
			{ 
				"Core", 
				"CoreUObject", 
				"Engine", 
				"InputCore", 
				"HeadMountedDisplay" 
		});

		PublicIncludePaths.AddRange
		(
			new string[]
			{
				 "SpacialUtils"              ,
				 "SpacialUtils/Actors"       ,
				 "SpacialUtils/Components"   ,
				 "SpacialUtils/UserInterface",
				 "SpacialUtils/UE_Template"  ,
				 "SpacialUtils/Utility"      ,

				// ... add public include paths required here ...
			}
		);
	}
}
