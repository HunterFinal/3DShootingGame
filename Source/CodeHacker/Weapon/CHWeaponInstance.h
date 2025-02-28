// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Weapon/CHEquipmentInstance.h"
#include "CHWeaponInstance.generated.h"

/**
 * 
 */
UCLASS()
class CODEHACKER_API UCHWeaponInstance : public UCHEquipmentInstance
{
	GENERATED_BODY()

public:
	UCHWeaponInstance();

public:

	//---CHEquipmentInstance Interface
	#pragma region CHEquipmentInstance Interface

	virtual void OnEquipped() override;
	virtual void OnUnequipped() override;

	#pragma endregion CHEquipmentInstance Interface	
	//---End of CHEquipmentInstance Interface

	UFUNCTION()
	void UpdateFiringTime();
	UFUNCTION()
	float GetTimeSinceLastInteractedWith() const;
	UFUNCTION()
	void OnDeathStarted(AActor* owningActor);

private:
	double m_timeLastEquipped;
	double m_timeLastFired;

};
