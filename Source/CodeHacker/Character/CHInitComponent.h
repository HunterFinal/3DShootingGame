// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Extensions/CHPawnComponent.h"

#include "CHInitComponent.generated.h"

class UCHAbilitySystemComponent;
/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (CodeHacker) ,meta = (BlueprintSpawnableComponent))
class CODEHACKER_API UCHInitComponent : public UCHPawnComponent
{
	GENERATED_BODY()
	
public:
	UCHInitComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintPure, Category = "CodeHacker|PawnInitialization")
	static UCHInitComponent* FindInitComponent(const APawn* pawn);

protected:

	virtual void OnRegister() override;
	virtual void BeginPlay() override;

private:

	void ValidationASC() const;

private:

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|Init")
	TSubclassOf<UCHAbilitySystemComponent> AbilitySystemComponentClass;
};
