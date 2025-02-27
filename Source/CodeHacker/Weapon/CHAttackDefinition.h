// Fill out your copyright notice in the Description page of Project Settings.
/*

CHProjectileDefinition.h

Author : MAI ZHICONG(バクチソウ)

Description : 発射物のデータ定義（UDataAsset）

Update History: 2025/02/27 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/
#pragma once

#include "Engine/DataAsset.h"

#include "CHAttackDefinition.generated.h"

class UNiagaraSystem;
class USoundBase;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Const, meta = (DisplayName = "Code Hacker Attack Data", ShortTooltip = "Data asset used to configure an attack."))
class CODEHACKER_API UCHAttackDefinition : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CodeHacker|Weapon|Attack")
	TObjectPtr<USoundBase> AttackedSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CodeHacker|Weapon|Attack")
	TObjectPtr<UNiagaraSystem> AttackedEffect;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CodeHacker|Weapon|Attack")
	TObjectPtr<UNiagaraSystem> HitEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CodeHacker|Weapon|Attack")
	double HitDamage;
	
};
