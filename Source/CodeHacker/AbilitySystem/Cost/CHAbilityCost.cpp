// Fill out your copyright notice in the Description page of Project Settings.


#include "CHAbilityCost.h"

#include "GameplayAbilitySpec.h"
#include "Abilities/GameplayAbility.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHAbilityCost)

UCHAbilityCost::UCHAbilityCost(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
}

bool UCHAbilityCost::CanAffordCost(const UCHGameplayAbility* Ability, const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, FGameplayTagContainer* OptionalRelevantTags) const
{
  return true;
}

void UCHAbilityCost::PayCost(const UCHGameplayAbility* Ability, const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo)
{
}
	