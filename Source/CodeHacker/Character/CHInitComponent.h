// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Extensions/CHPawnComponent.h"

#include "CHInitComponent.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CODEHACKER_API UCHInitComponent : public UCHPawnComponent
{
	GENERATED_BODY()
	
public:
	UCHInitComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintPure, Category = "CodeHacker|PawnInitialization")
	static UCHInitComponent* FindInitComponent(const APawn* pawn);

};
