// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CodeHackerEditor : ModuleRules
{
  public CodeHackerEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.AddRange
		(
			new string[]
			{
				"CodeHackerEditor",
        "CodeHacker",
			}
		);

		PublicDependencyModuleNames.AddRange
		(
			new string[] 
			{ 
				"Core", 
				"CoreUObject", 
				"Engine", 
				"EnhancedInput", 
				"MLibrary", 
				"Niagara",
				"GameplayTagsEditor",
				"GameplayTasksEditor",
				"GameplayAbilities",
				"GameplayAbilitiesEditor",
        "CodeHacker",
			}
		);

		PrivateDependencyModuleNames.AddRange
		(
			new string[] 
			{ 
        "InputCore", 
        "UnrealEd",
				"Slate", 
				"SlateCore", 
				"UMG" 
			}
		);
	}
}