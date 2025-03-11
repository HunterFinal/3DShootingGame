// Fill out your copyright notice in the Description page of Project Settings.


#include "AATCompositeNode.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AATCompositeNode)

UAATCompositeNode::UAATCompositeNode(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
}

int32 UAATCompositeNode::GetChildrenNum() const
{
  return ChildrenNode.Num();
}

void UAATCompositeNode::OnNodeActivation() const
{
}

void UAATCompositeNode::OnNodeDeactivation() const
{
}


