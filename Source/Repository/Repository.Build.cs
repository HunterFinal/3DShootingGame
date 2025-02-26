// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Repository: ModuleRules
{
  public Repository(ReadOnlyTargetRules Target) : base(Target)
  {
    PublicDependencyModuleNames.AddRange(new string[] {"Core" , "CoreUObject" , "Engine", "Model", "MLibrary"});
  }

}