// Fill out your copyright notice in the Description page of Project Settings.


#include "CHHealthSet.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHHealthSet)

UCHHealthSet::UCHHealthSet()
  : Health(100.0f)
  , MaxHealth(100.0f)
  , m_maxHealthBeforeAttributeChange(0.0f)
  , m_healthBeforAttributeChange(0.0f)
  , m_bOutOfHealth(false)
{
}

bool UCHHealthSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
  return true;
}
void UCHHealthSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{

}
void UCHHealthSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{

}
void UCHHealthSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{

}
void UCHHealthSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
  
}
