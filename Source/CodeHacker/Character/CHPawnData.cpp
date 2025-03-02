// Fill out your copyright notice in the Description page of Project Settings.


#include "CHPawnData.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHPawnData)

UCHPawnData::UCHPawnData(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
  PawnClass = nullptr;
  InputConfig = nullptr;
  DefaultCameraWork = nullptr;
}

