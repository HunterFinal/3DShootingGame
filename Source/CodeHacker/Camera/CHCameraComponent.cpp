// Fill out your copyright notice in the Description page of Project Settings.
/*

CHCameraComponent.cpp

Author : MAI ZHICONG(バクチソウ)

Description : CodeHackerカメラコンポネント

Update History: 2025/02/27 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/
#include "CHCameraComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHCameraComponent)

UCHCameraComponent::UCHCameraComponent(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
}

UCHCameraComponent* UCHCameraComponent::TryGetCHCameraComponent(const AActor* Actor)
{
  return (Actor != nullptr) ? (Actor->FindComponentByClass<UCHCameraComponent>()) : nullptr;
}

