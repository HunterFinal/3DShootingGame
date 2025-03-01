// Fill out your copyright notice in the Description page of Project Settings.
/*

CHRangedWeaponInstance.h

Author : MAI ZHICONG(バクチソウ)

Description : 遠距離武器実体

Update History: 2025/02/28 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/
#pragma once

#include "CHWeaponInstance.h"

#include "CHRangedWeaponInstance.generated.h"

/**
 * 
 */
UCLASS()
class CODEHACKER_API UCHRangedWeaponInstance : public UCHWeaponInstance
{
	GENERATED_BODY()

public:
	UCHRangedWeaponInstance();

	int32 GetBulletsPerCartridge() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipment|Ranged Weapon|Config")
	int32 BulletsPerCartridge;
	
};
