// Fill out your copyright notice in the Description page of Project Settings.


#include "CHInitComponent.h"
#include "GameFramework/Pawn.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHInitComponent)

UCHInitComponent::UCHInitComponent(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
}

UCHInitComponent* UCHInitComponent::FindInitComponent(const APawn* pawn)
{
  return (pawn != nullptr) ? pawn->FindComponentByClass<UCHInitComponent>() : nullptr;
}