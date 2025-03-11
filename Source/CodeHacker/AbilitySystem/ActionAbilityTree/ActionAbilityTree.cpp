// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionAbilityTree.h"

#include "AATNode.h"

#include "AbilitySystemComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(ActionAbilityTree)

UActionAbilityTree::UActionAbilityTree(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
  , AbilitySystemComponent(nullptr)
{
}

UAbilitySystemComponent* UActionAbilityTree::GetAbilitySystemComponent() const
{
  return AbilitySystemComponent;
}

