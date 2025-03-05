// Fill out your copyright notice in the Description page of Project Settings.


#include "CHGameplayAbility.h"
#include "GameFramework/Character.h"

#include "AbilitySystem/CHAbilitySystemComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHGameplayAbility)

UCHGameplayAbility::UCHGameplayAbility(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
}

ACharacter* UCHGameplayAbility::GetCharacterFromActorInfo() const
{
  return (CurrentActorInfo != nullptr) ? (Cast<ACharacter>(CurrentActorInfo->AvatarActor.Get())) : nullptr;
}

UCHAbilitySystemComponent* UCHGameplayAbility::GetCHAbilitySystemComponent() const
{
  return (CurrentActorInfo != nullptr) ? (Cast<UCHAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent.Get())) : nullptr; 
}

bool UCHGameplayAbility::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
  bool result = Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
  if (result)
  {
    return true;
  }

  return false;
}