// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CHAttributeSet.h"

#include "AbilitySystemComponent.h"

#include "CHStaminaSet.generated.h"


UCLASS()
class CODEHACKER_API UCHStaminaSet : public UCHAttributeSet
{
	GENERATED_BODY()

public:
	UCHStaminaSet();

	ATTRIBUTE_ACCESSORS(UCHStaminaSet, Stamina);
	ATTRIBUTE_ACCESSORS(UCHStaminaSet, MaxStamina);

private:

	UPROPERTY(BlueprintReadOnly, Category = "CodeHacker|Stamina", meta = (HideFromModifiers, AllowPrivateAccess = true))
	FCHGameplayAttributeData Stamina;

	UPROPERTY(BlueprintReadOnly, Category = "CodeHacker|Stamina", meta = (AllowPrivateAccess = true))
	FCHGameplayAttributeData MaxStamina;

};
