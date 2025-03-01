// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"

#include "CHInputConfig.generated.h"

class UInputAction;

USTRUCT(BlueprintType)
struct FCHInputAction
{
	GENERATED_BODY()

	FCHInputAction()
		: InputAction(nullptr)
		, InputTag(FGameplayTag::EmptyTag)
	{
	}

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<const UInputAction> InputAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
	
};
/**
 * 
 */
UCLASS(BlueprintType, Const)
class CODEHACKER_API UCHInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UCHInputConfig(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Code Hacker|Input")
	const UInputAction* FindNativeInputActionByTag(const FGameplayTag& InputTag, bool bLogNotFound = true) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputAction"))
	TArray<FCHInputAction> NativeInputActions;
	
};
