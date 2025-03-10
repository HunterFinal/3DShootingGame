// Fill out your copyright notice in the Description page of Project Settings.


#include "CHInputConfig.h"

#include "CodeHackerLogChannels.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHInputConfig)

UCHInputConfig::UCHInputConfig(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
}

const UInputAction* UCHInputConfig::FindNativeInputActionByTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
  for (const FCHInputAction& inputAction : NativeInputActions)
  {
    if (inputAction.InputAction != nullptr && (inputAction.InputTag == InputTag))
    {
      return inputAction.InputAction;
    }
  }

  if (bLogNotFound)
  {
    UE_LOG(LogCodeHackerInputAction, Error, TEXT("Can't find NativeInputAction for InputTag [%s] on InputConfig [%s]."), *InputTag.ToString(), *GetNameSafe(this));
  }

  return nullptr;
}

const UInputAction* UCHInputConfig::FindAbilityInputActionByTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
  if (!InputTag.IsValid() && bLogNotFound)
  {
    UE_LOG(LogCodeHackerInputAction, Error, TEXT("InputTag is Invalid"));
    return nullptr;
  }

  for (const FCHInputAction& inputAction : AbilityInputActions)
  {
    if ((inputAction.InputAction != nullptr) && (inputAction.InputTag == InputTag))
    {
      return inputAction.InputAction;
    }
  }

  if (bLogNotFound)
  {
    UE_LOG(LogCodeHackerInputAction, Error, TEXT("Can't find AbilityInputAction for InputTag [%s] on InputConfig [%s]."), *InputTag.ToString(), *GetNameSafe(this));
  }

  return nullptr;
}

