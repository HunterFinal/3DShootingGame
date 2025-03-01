// Fill out your copyright notice in the Description page of Project Settings.


#include "CHInputComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHInputComponent)

UCHInputComponent::UCHInputComponent(const FObjectInitializer& objectInitializer)
  : Super(objectInitializer)
{
}

void UCHInputComponent::AddInputMappings(const UCHInputConfig* inputConfig, UEnhancedInputLocalPlayerSubsystem* inputSubsystem) const
{
  check(inputConfig);
  check(inputSubsystem);
}

void UCHInputComponent::RemoveInputMappings(const UCHInputConfig* inputConfig, UEnhancedInputLocalPlayerSubsystem* inputSubsystem) const
{
  check(inputConfig);
  check(inputSubsystem);
}

void UCHInputComponent::RemoveBinds(TArray<uint32>& bindHandles)
{
  for (uint32 handle : bindHandles)
  {
    RemoveBindingByHandle(handle);
  }
  
  bindHandles.Reset();
}