// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Model: ModuleRules
{
  public Model(ReadOnlyTargetRules Target) : base(Target)
  {
    PublicDependencyModuleNames.AddRange(new string[] {"Core" , "CoreUObject" , "Engine", "MLibrary"});
  }

}