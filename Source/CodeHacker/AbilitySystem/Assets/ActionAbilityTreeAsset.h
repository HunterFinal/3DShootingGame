// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"

#include "ActionAbilityTreeAsset.generated.h"

class UGameplayAbility;

USTRUCT()
struct FActionAbilityChainNodeOverrideTags
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "ActionAbiliyChain|Tags")
	FGameplayTagContainer CancelAbilitiesWithTag;
	UPROPERTY(EditDefaultsOnly, Category = "ActionAbiliyChain|Tags")
	FGameplayTagContainer BlockAbilitiesWithTag;
};

USTRUCT(BlueprintType)
struct FActionAbilityNode
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "ActionAbilityNode")
	TSubclassOf<UGameplayAbility> AbilityClass;

	UPROPERTY(EditDefaultsOnly, Category = "ActionAbilityNode")
	bool bUseAbilityTagSettings = true;

	UPROPERTY(EditDefaultsOnly, Category = "ActionAbilityNode", meta = (EditCondition = "bUseAbilityTagSettings == false", EditConditionHides))
	FActionAbilityChainNodeOverrideTags OverrideTags;

};

USTRUCT(BlueprintType)
struct FActionAbilityNode_Chain
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "ActionAbilityChain|Node")
	FActionAbilityNode ChainNode;

	UPROPERTY(EditDefaultsOnly, Category = "ActionAbilityChain|Node", meta = (ShortTooltip = "値が大きければ大きいほどチェーンの後ろに回される"))
	uint32 ChainPriority;
};

USTRUCT(BlueprintType)
struct FActionAbilityChain
{

	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "ActionAbilityChain")
	TArray<FActionAbilityNode_Chain> ChainNodes;
};



UCLASS(NotBlueprintable, meta = (DisplayName = "Action Ability Tree"))
class CODEHACKER_API UActionAbilityTreeAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UActionAbilityTreeAsset();

	UPROPERTY(EditDefaultsOnly, Category = "ActionAbilityTree")
	TArray<FActionAbilityChain> ActionChains;

	UPROPERTY(EditDefaultsOnly, Category = "ActionAbilityTree")
	TArray<FActionAbilityNode> IndependentNodes;

};
