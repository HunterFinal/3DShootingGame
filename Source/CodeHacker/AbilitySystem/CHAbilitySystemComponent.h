// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystemComponent.h"
#include "GameplayAbilitySpecHandle.h"

#include "CHAbilitySystemComponent.generated.h"

struct FGameplayTag;

struct FCHAbilityInputHandleGroup
{
	TArray<FGameplayAbilitySpecHandle> InputPressedSpecHandles;
	TArray<FGameplayAbilitySpecHandle> InputHeldSpecHandles;
	TArray<FGameplayAbilitySpecHandle> InputReleasedSpecHandles;
};
/**
 * 
 */
UCLASS()
class CODEHACKER_API UCHAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	UCHAbilitySystemComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	void AbilityInputTagPressed(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);
	
private:

	FCHAbilityInputHandleGroup m_inputHandleGroup;
};
