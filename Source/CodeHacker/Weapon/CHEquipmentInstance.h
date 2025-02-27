// Fill out your copyright notice in the Description page of Project Settings.
/*

CHEquipmentInstance.h

Author : MAI ZHICONG(バクチソウ)

Description : 装備品実体（親クラス）

Update History: 2025/02/27 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/
#pragma once

#include "UObject/NoExportTypes.h"

#include "CHEquipmentInstance.generated.h"

struct FCHEquipmentAppearance;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Abstract)
class CODEHACKER_API UCHEquipmentInstance : public UObject
{
	GENERATED_BODY()

public:
	UCHEquipmentInstance();

	UWorld* GetWorld() const override final;

	UFUNCTION(BlueprintPure, Category = "Equipment|Instance")
	APawn* GetPawn() const;

	UFUNCTION(BlueprintPure, Category = "Equipment|Instance", meta = (DeterminesOutputType = PawnType))
	APawn* GetTypedPawn(TSubclassOf<APawn> PawnType) const;

	UFUNCTION(BlueprintPure, Category = "Equipment|Instance")
	TArray<AActor*> GetSpawnedAppearances() const;

	virtual void SpawnAppearanceActors(const TArray<FCHEquipmentAppearance>&);
	virtual void DestroyAppearanceActors();

	virtual void OnEquipped();
	virtual void OnUnequipped();

private:
	UPROPERTY()
	TArray<TObjectPtr<AActor>> SpawnedAppearances;
	
};
