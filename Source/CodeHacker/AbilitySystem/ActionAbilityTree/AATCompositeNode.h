// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AATNode.h"

#include "AATCompositeNode.generated.h"

USTRUCT()
struct FAATCompositeNodeChild
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<UAATCompositeNode> ChildCompositeNode;

	FAATCompositeNodeChild()
		: ChildCompositeNode(nullptr)
	{
	}

};



UCLASS(Abstract, MinimalAPI)
class UAATCompositeNode : public UAATNode
{
	GENERATED_BODY()

public:

	UAATCompositeNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	CODEHACKER_API int32 GetChildrenNum() const;

	CODEHACKER_API void OnNodeActivation() const;

	CODEHACKER_API void OnNodeDeactivation() const;

private:

	UPROPERTY()
	TArray<FAATCompositeNodeChild> ChildrenNode;

};
