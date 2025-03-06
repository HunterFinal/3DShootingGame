// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"

#include "CHAbilityCost.generated.h"

class UCHGameplayAbility;

struct FGameplayAbilitySpecHandle;
struct FGameplayAbilityActorInfo;
struct FGameplayTagContainer;
struct FGameplayAbilityActivationInfo;

/**
 * 
 */
UCLASS(DefaultToinstanced, EditInlineNew, Abstract)
class CODEHACKER_API UCHAbilityCost : public UObject
{
	GENERATED_BODY()

public:

	UCHAbilityCost(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual bool CanAffordCost(const UCHGameplayAbility* Ability, const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, FGameplayTagContainer* OptionalRelevantTags) const;
	virtual void PayCost(const UCHGameplayAbility* Ability, const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo);
	
};
