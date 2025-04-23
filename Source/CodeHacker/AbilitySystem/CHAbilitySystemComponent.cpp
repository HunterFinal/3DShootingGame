// Fill out your copyright notice in the Description page of Project Settings.


#include "CHAbilitySystemComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHAbilitySystemComponent)

UCHAbilitySystemComponent::UCHAbilitySystemComponent(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
  m_inputHandleGroup.InputPressedSpecHandles.Reset();
  m_inputHandleGroup.InputHeldSpecHandles.Reset();
  m_inputHandleGroup.InputReleasedSpecHandles.Reset();
}

void UCHAbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag& InputTag)
{
  if (!InputTag.IsValid())
  {
    return;
  }

  for (const FGameplayAbilitySpec& abilitySpec : ActivatableAbilities.Items)
  {
    if ((abilitySpec.Ability != nullptr) && abilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
    {
      m_inputHandleGroup.InputPressedSpecHandles.AddUnique(abilitySpec.Handle);
      m_inputHandleGroup.InputHeldSpecHandles.AddUnique(abilitySpec.Handle);
    }
  }
}

void UCHAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
  if (!InputTag.IsValid())
  {
    return;
  }

  for (const FGameplayAbilitySpec& abilitySpec : ActivatableAbilities.Items)
  {
    if ((abilitySpec.Ability != nullptr) && abilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
    {
      m_inputHandleGroup.InputReleasedSpecHandles.AddUnique(abilitySpec.Handle);
      m_inputHandleGroup.InputHeldSpecHandles.Remove(abilitySpec.Handle);
    }
  }
}

void UCHAbilitySystemComponent::ProcessAbilityInput(float DeltaTime, bool bGamePaused)
{
  
}