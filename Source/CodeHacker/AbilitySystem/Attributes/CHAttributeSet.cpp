// Fill out your copyright notice in the Description page of Project Settings.

#include "CHAttributeSet.h"

#include "AbilitySystem/CHAbilitySystemComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHAttributeSet)

UCHAttributeSet::UCHAttributeSet()
{
}

UWorld* UCHAttributeSet::GetWorld() const
{
  const UObject* outer = GetOuter();
  check(outer != nullptr);

  return outer->GetWorld();
}

UCHAbilitySystemComponent* UCHAttributeSet::GetCHAbilitySystemComponent() const
{
  return Cast<UCHAbilitySystemComponent>(GetOwningAbilitySystemComponent());
}


