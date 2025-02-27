// Fill out your copyright notice in the Description page of Project Settings.
/*

CHProjectileInstance.cpp

Author : MAI ZHICONG(バクチソウ)

Description : 発射物実体

Update History: 2025/02/27 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/

#include "CHAttackInstance.h"

#include "CHAttackDefinition.h"
#include "NiagaraSystem.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHAttackInstance)

void UCHAttackInstance::OnAttack()
{
}

void UCHAttackInstance::OnHit()
{
}

FHitHandle UCHAttackInstance::GetHitHandle() const
{
  if (AttackDef == nullptr)
  {
    return FHitHandle{};
  }

  FHitHandle hitHandle{};

  hitHandle.HitEffect = AttackDef->HitEffect;
  hitHandle.HitDamage = AttackDef->HitDamage;

  return hitHandle;
}

