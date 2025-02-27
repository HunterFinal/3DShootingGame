// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CodeHacker : ModuleRules
{
	public CodeHacker(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.AddRange
		(
			new string[]
			{
				"CodeHacker"
			}
		);

		PublicDependencyModuleNames.AddRange
		(
			new string[] 
			{ 
				"Core", 
				"CoreUObject", 
				"Engine", 
				"InputCore", 
				"EnhancedInput", 
				"MLibrary", 
				"Niagara"
			}
		);

		PrivateDependencyModuleNames.AddRange
		(
			new string[] 
			{ 
				"Slate", 
				"SlateCore", 
				"UMG" 
			}
		);
	}
}
