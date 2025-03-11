// Fill out your copyright notice in the Description page of Project Settings.


#include "AATNode.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AATNode)

UAATNode::UAATNode(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
  , m_parentNode(nullptr)
  , m_executionOrder(0)
  , m_treeDepth(0)
{
}

UWorld* UAATNode::GetWorld() const
{
  UObject* outer = GetOuter();
  if (outer == nullptr)
  {
    return nullptr;
  }

  // TODO
  // エディタ上でNodeのOuterのPackageのOuterにする（要調査）
  // 参考スクリプト: UE5/Engine/Source/Runtime/AIModule/Private/BehaviorTree/BTNode.cpp
  {
    UPackage* package = Cast<UPackage>(outer);
    if (package != nullptr)
    {
      return Cast<UWorld>(package->GetOuter());
    }
  }

  return outer->GetWorld();
}

UAATCompositeNode* UAATNode::GetParentNode() const
{
  return m_parentNode;
}

uint32 UAATNode::GetExecutionOrder() const
{
  return m_executionOrder;
}

uint8 UAATNode::GetTreeDepth() const
{
  return m_treeDepth;
}

