// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CHAttributeSet.h"

#include "AbilitySystemComponent.h"

#include "CHHealthSet.generated.h"

/**
 * 
 */
UCLASS()
class CODEHACKER_API UCHHealthSet : public UCHAttributeSet
{
	GENERATED_BODY()

public:
	UCHHealthSet();

	ATTRIBUTE_ACCESSORS(UCHHealthSet, Health);
	ATTRIBUTE_ACCESSORS(UCHHealthSet, MaxHealth);
	ATTRIBUTE_ACCESSORS(UCHHealthSet, Healing);
	ATTRIBUTE_ACCESSORS(UCHHealthSet, Damage);

	FCHAttributeDelegate OnHealthChanged;
	FCHAttributeDelegate OnMaxHealthChanged;
	FCHAttributeDelegate OnOutOfHealth;

protected:

	//---Begin of Attribute Set Interface
	#pragma region Attribute Set Interface
	virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;
	#pragma endregion Attribute Set Interface
	//---End of Attribute Set Interface

	void ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const;
 
private:
	UPROPERTY(BlueprintReadOnly, Category = "CodeHacker|Health", meta = (HideFromModifiers, AllowPrivateAccess = true))
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, Category = "CodeHacker|Health", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
	
	UPROPERTY(BlueprintReadOnly, Category = "CodeHacker|Health", meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Healing;

	UPROPERTY(BlueprintReadOnly, Category = "CodeHacker|Health", meta = (HideFromModifiers, AllowPrivateAccess = true))
	FGameplayAttributeData Damage;
	
private:
	float m_maxHealthBeforeAttributeChange;
	float m_healthBeforAttributeChange;

	uint8 m_bOutOfHealth : 1;
};
