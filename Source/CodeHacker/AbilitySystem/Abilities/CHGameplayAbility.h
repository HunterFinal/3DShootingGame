// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Abilities/GameplayAbility.h"

#include "CHGameplayAbility.generated.h"

class ACharacter;
class UCHAbilitySystemComponent;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories = Input, meta = (ShortTooltip = "Code Hacker に使うGameplay Ability親クラス"))
class CODEHACKER_API UCHGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UCHGameplayAbility(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Ability")
	ACharacter*	GetCharacterFromActorInfo() const;

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Ability")
	UCHAbilitySystemComponent* GetCHAbilitySystemComponent() const;

protected:
	///---Begin of UGameplayAbility
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const override;
	///---End of UGameplayAbility
};
