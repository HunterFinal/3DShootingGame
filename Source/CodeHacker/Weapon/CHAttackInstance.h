// Fill out your copyright notice in the Description page of Project Settings.
/*

CHProjectileInstance.h

Author : MAI ZHICONG(バクチソウ)

Description : 発射物実体

Update History: 2025/02/27 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/
#pragma once

#include "UObject/NoExportTypes.h"

#include "CHAttackInstance.generated.h"

class UCHAttackDefinition;
class UNiagaraSystem;

USTRUCT()
struct FHitHandle
{
	GENERATED_BODY()

	FHitHandle()
		: HitEffect(nullptr)
		, HitDamage(0.0)
	{}

	UPROPERTY()
	TObjectPtr<UNiagaraSystem> HitEffect;

	double HitDamage;

};

/**
 * 
 */
UCLASS(BlueprintType, Const, Abstract)
class CODEHACKER_API UCHAttackInstance : public UObject
{
	GENERATED_BODY()

public:
	virtual void OnAttack();
	virtual void OnHit();
	FHitHandle GetHitHandle() const;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCHAttackDefinition> AttackDef;
};
