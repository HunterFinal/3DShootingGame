// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SpringArmComponent.h"

#include "CHSpringArmComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = Camera, meta = (BlueprintSpawnableComponent), hideCategories = (Mobility))
class CODEHACKER_API UCHSpringArmComponent : public USpringArmComponent
{
	GENERATED_BODY()

public:
	UCHSpringArmComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual FVector BlendLocations(const FVector& DesiredArmLocation, const FVector& TraceHitLocation, bool bHitSomething, float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|SpringArm", meta = (UIMin = "0.0", UIMax = "1000.0", ClampMin = "0.0", ClampMax = "1000.0", EditCondition = EnableCollision))
	float HitInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|SpringArm", meta = (UIMin = "0.0", ClampMin = "0.0", EditCondition = EnableCollision))
	float HitReturnDesiredLocationTime;

private:
	float m_curtHitRetusnDesiredLocationTime;
	FVector m_prevHitInterpLocation;
};
