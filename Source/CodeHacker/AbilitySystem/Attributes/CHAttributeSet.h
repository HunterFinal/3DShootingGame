// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AttributeSet.h"

#include "CHAttributeSet.generated.h"

class AActor;
class UCHAbilitySystemComponent;
struct FGameplayEffectSpec;

/**
 * Attributeの初期化やアクセサ関数を簡単に定義できるマクロ
 */
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * Attributeを更新する時に使うデリゲート
 * @param EffectInstigator		影響を与える者
 * @param EffectCauser				影響を受ける者
 * @param EffectSpec					影響説明オブジェクト
 * @param EffectMagnitude			影響の大きさ
 * @param OldValue						影響される前の値
 * @param NewValue						影響された後の値
 */

using FCHAttributeDelegate = TMulticastDelegate<void(AActor* /** EffectInstigator*/, AActor* /**EffectCauser */, const FGameplayEffectSpec* /**EffectSpec */, float /**EffectMagnitude */, float /**OldValue */, float /**NewValue */)>;

UCLASS()
class CODEHACKER_API UCHAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UCHAttributeSet();

	UWorld* GetWorld() const override final;

	UCHAbilitySystemComponent* GetCHAbilitySystemComponent() const;
};
