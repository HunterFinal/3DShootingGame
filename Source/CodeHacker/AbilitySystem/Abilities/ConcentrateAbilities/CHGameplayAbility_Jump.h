// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystem/Abilities/CHGameplayAbility.h"

#include "CHGameplayAbility_Jump.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CODEHACKER_API UCHGameplayAbility_Jump : public UCHGameplayAbility
{
	GENERATED_BODY()

public:
	
	UCHGameplayAbility_Jump(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	

protected:
	
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	
	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Ability_Jump")
	void JumpStart();

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Ability_Jump")
	void JumpStop();

	UFUNCTION(BlueprintImplementableEvent, Category = "CodeHacker|Ability_Jump", DisplayName = "OnJumpStart")
	void K2_OnJumpStart();

	UFUNCTION(BlueprintImplementableEvent, Category = "CodeHacker|Ability_Jump", DisplayName = "OnJumpStop")
	void K2_OnJumpStop();
};
