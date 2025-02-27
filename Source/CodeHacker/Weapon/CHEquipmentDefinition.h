// Fill out your copyright notice in the Description page of Project Settings.
/*

UCHEquipmentDefinition.h

Author : MAI ZHICONG(バクチソウ)

Description : 装備品のデータ定義

Update History: 2025/02/27 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/
#pragma once

#include "UObject/NoExportTypes.h"

#include "CHEquipmentDefinition.generated.h"

class UCHEquipmentInstance;

USTRUCT()
struct FCHEquipmentAppearance
{
	GENERATED_BODY()

	FCHEquipmentAppearance()
	{}

	UPROPERTY(EditAnywhere, Category = "Equipment|Appearance")
	TSubclassOf<AActor> AppearanceToSpawn;

	UPROPERTY(EditAnywhere, Category = "Equipment|Appearance")
	FName AttachSocketName;

	UPROPERTY(EditAnywhere, Category = "Equipment|Appearance")
	FTransform AttachTransform;
};
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Const, Abstract)
class CODEHACKER_API UCHEquipmentDefinition : public UObject
{
	GENERATED_BODY()

public:
	UCHEquipmentDefinition();

public:
	UPROPERTY(EditDefaultsOnly, Category = "Equipment|Definition")
	TSubclassOf<class UCHEquipmentInstance> InstanceType;

	UPROPERTY(EditDefaultsOnly, Category = "Equipment|Definition")
	TArray<FCHEquipmentAppearance> AppearancesToSpawn;

};
