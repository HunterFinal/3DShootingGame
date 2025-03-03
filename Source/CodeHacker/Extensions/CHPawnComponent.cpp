// Fill out your copyright notice in the Description page of Project Settings.

#include "CHPawnComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHPawnComponent)

// Sets default values for this component's properties
UCHPawnComponent::UCHPawnComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FTimerManager& UCHPawnComponent::GetWorldTimerManager() const
{
	AActor* owner = GetOwner();
	check(owner != nullptr);
	return owner->GetWorldTimerManager();
}


