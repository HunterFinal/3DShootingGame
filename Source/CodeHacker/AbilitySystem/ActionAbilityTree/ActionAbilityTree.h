// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "AbilitySystemInterface.h"

#include "ActionAbilityTree.generated.h"

class UAbilitySystemComponent;
class UAATNode;


UCLASS(BlueprintType, MinimalAPI)
class UActionAbilityTree : public UObject, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	UActionAbilityTree(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//---Begin of IAbilitySystemInterface Interface
	CODEHACKER_API UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//---End of IAbilitySystemInterface Interface

private:

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAATNode> RootNode;

	
};
