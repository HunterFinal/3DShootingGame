// Fill out your copyright notice in the Description page of Project Settings.

#include "CHAttributeSet.h"

#include "AbilitySystem/CHAbilitySystemComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHAttributeSet)

//---Begin of FCHGameplayAttributeData Definition
#pragma region FCHGameplayAttributeData Definition
void FCHGameplayAttributeData::SetCurrentValue(float NewValue)
{
  if (OnCurrentValueChanged.IsBound())
  {
    const float oldValue = CurrentValue;
    OnCurrentValueChanged.Broadcast(oldValue, NewValue);
  }

  Super::SetCurrentValue(NewValue);

}

void FCHGameplayAttributeData::SetBaseValue(float NewValue)
{
  if (OnBaseValueChanged.IsBound())
  {
    const float oldValue = BaseValue;
    OnBaseValueChanged.Broadcast(oldValue, NewValue);
  }

  Super::SetBaseValue(NewValue);
}

#pragma endregion FCHGameplayAttributeData Definition
//---End of FCHGameplayAttributeData Definition 

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


