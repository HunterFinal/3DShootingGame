// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnhancedInputComponent.h"
#include "CHInputConfig.h"

#include "CHInputComponent.generated.h"

class UEnhancedInputLocalPlayerSubsystem;

/**
 * 
 */
UCLASS(Config = Input)
class CODEHACKER_API UCHInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	UCHInputComponent(const FObjectInitializer& objectInitializer);

	void AddInputMappings(const UCHInputConfig* inputConfig, UEnhancedInputLocalPlayerSubsystem* inputSubsystem) const;
	void RemoveInputMappings(const UCHInputConfig* inputConfig, UEnhancedInputLocalPlayerSubsystem* inputSubsystem) const;

	template<typename UserClass, typename FuncType>
	void BindNativeAction(const UCHInputConfig* inputConfig, const FGameplayTag& inputTag, ETriggerEvent triggerEvent, UserClass* object, FuncType func, bool bLogIfNotFound);

	void RemoveBinds(TArray<uint32>& bindHandles);
};

template<typename UserClass, typename FuncType>
void UCHInputComponent::BindNativeAction(const UCHInputConfig* inputConfig, const FGameplayTag& inputTag, ETriggerEvent triggerEvent, UserClass* object, FuncType func, bool bLogIfNotFound)
{
	check(inputConfig);

	const UInputAction* inputAction = inputConfig->FindNativeInputActionByTag(inputTag, bLogIfNotFound);

	if (inputAction != nullptr)
	{
		BindAction(inputAction, triggerEvent, object, func);
	}
}
