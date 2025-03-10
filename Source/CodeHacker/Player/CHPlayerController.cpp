// Fill out your copyright notice in the Description page of Project Settings.


#include "CHPlayerController.h"

#include "Camera/CHPlayerCameraManager.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHPlayerController)

ACHPlayerController::ACHPlayerController(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
  PlayerCameraManagerClass = ACHPlayerCameraManager::StaticClass();
}

void ACHPlayerController::PreProcessInput(const float DeltaTime, const bool bGamePaused)
{
  Super::PreProcessInput(DeltaTime, bGamePaused);
}

void ACHPlayerController::PostProcessInput(const float DeltaTime, const bool bGamePaused)
{
  Super::PostProcessInput(DeltaTime, bGamePaused);
}

