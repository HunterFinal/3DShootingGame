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

}

void UCHAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
  
}