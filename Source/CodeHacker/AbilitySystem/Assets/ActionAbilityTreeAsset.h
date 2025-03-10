// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"

#include "ActionAbilityTreeAsset.generated.h"

class UGameplayAbility;
class UActionAbilityNode;

USTRUCT(BlueprintType)
struct FActionAbilityNodeBranchDefinition
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "AbilityNode|Definition")
	TSubclassOf<UActionAbilityNode> NodeClass;

	UPROPERTY(EditDefaultsOnly, Category = "AbilityNode|Definition")
	int32 Priority;
};

USTRUCT(BlueprintType)
struct FActionAbilityNodeInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "AbilityNode")
	TSubclassOf<UGameplayAbility> AbilityClass;

};

UCLASS(BlueprintType, BlueprintAble, Const, Abstract)
class UActionAbilityNode : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "AbilityNode")
	FActionAbilityNodeInfo CurrentAbilityInfo;

	UPROPERTY(EditDefaultsOnly, Category = "AbilityNode")
	TArray<FActionAbilityNodeBranchDefinition> BranchDefinitions;
};


UCLASS(meta = (DisplayName = "Action Ability Tree"))
class CODEHACKER_API UActionAbilityTreeAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

UActionAbilityTreeAsset();

	UPROPERTY(EditDefaultsOnly, Category = "AbilityTree|RootNode")
	TSet<TSubclassOf<UActionAbilityNode>> ActionRootNodes;
};
