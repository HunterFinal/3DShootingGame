// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/SoftObjectPtr.h"
#include "InputMappingContext.h"

#include "CHInputMappingContextAndPriority.generated.h"


USTRUCT(BlueprintType)
struct FCHInputMappingContextAndPriority
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "InputMappings")
	TSoftObjectPtr<UInputMappingContext> InputMapping;

	UPROPERTY(EditAnywhere, Category = "InputMappings")
	int32 Priority;

};

