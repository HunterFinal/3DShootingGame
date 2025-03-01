// Fill out your copyright notice in the Description page of Project Settings.


#include "CHInputConfig.h"

#include "CodeHackerLogChannels.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHInputConfig)

UCHInputConfig::UCHInputConfig(const FObjectInitializer& objectInitializer)
{
}

const UInputAction* UCHInputConfig::FindNativeInputActionByTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
  for (const FCHInputAction& action : NativeInputActions)
  {
    if (action.InputAction != nullptr && (action.InputTag == InputTag))
    {
      return action.InputAction;
    }
  }

  if (bLogNotFound)
  {
    UE_LOG(LogCodeHackerInputAction, Error, TEXT("Can't find NativeInputAction for InputTag [%s] on InputConfig [%s]."), *InputTag.ToString(), *GetNameSafe(this));
  }

  return nullptr;
}

