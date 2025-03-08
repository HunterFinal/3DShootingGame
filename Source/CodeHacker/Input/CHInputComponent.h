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

	void AddInputMappings(const UCHInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const;
	void RemoveInputMappings(const UCHInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const;

	template<typename UserClass, typename FuncType>
	void BindNativeAction(const UCHInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* UserObject, FuncType TriggerFunc, bool bLogIfNotFound);

	template<typename UserClass, typename PressedFuncType, typename ReleasedFuncType>
	void BindAbilityAction(const UCHInputConfig* InputConfig, UserClass* UserObject, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc);

	void RemoveBinds(TArray<uint32>& bindHandles);
};

template<typename UserClass, typename FuncType>
void UCHInputComponent::BindNativeAction(const UCHInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* UserObject, FuncType TriggerFunc, bool bLogIfNotFound)
{
	check(InputConfig != nullptr);

	const UInputAction* inputAction = InputConfig->FindNativeInputActionByTag(InputTag, bLogIfNotFound);

	if (inputAction != nullptr)
	{
		BindAction(inputAction, TriggerEvent, UserObject, TriggerFunc);
	}
}

template<typename UserClass, typename PressedFuncType, typename ReleasedFuncType>
void UCHInputComponent::BindAbilityAction(const UCHInputConfig* InputConfig, UserClass* UserObject, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc)
{
	check(InputConfig != nullptr);

	for (const FCHInputAction& inputAction : InputConfig->AbilityInputActions)
	{
		if (PressedFunc != nullptr)
		{
			BindAction(inputAction.InputAction, ETriggerEvent::Triggered, UserObject, PressedFunc, /**Delegate Payload(デリゲートに使う仮引数の実体) */inputAction.InputTag);
		}

		if (ReleasedFunc != nullptr)
		{
			BindAction(inputAction.InputAction, ETriggerEvent::Completed, UserObject, ReleasedFunc, inputAction.InputTag);
		}
	}
}
