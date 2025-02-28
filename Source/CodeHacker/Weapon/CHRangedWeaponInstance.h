// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/CHWeaponInstance.h"
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
