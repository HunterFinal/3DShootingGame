// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"

#include "AATNode.generated.h"

class UAATCompositeNode;

/**
 * 
 */
UCLASS(Config = Game, Abstract, MinimalAPI)
class UAATNode : public UObject
{
	GENERATED_BODY()

public:

	UAATNode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	//---Begin of UObject Interface
	CODEHACKER_API virtual UWorld* GetWorld() const override;
	//---End of UObject Interface

	CODEHACKER_API void InitializeNode(UAATCompositeNode* InParentNode, uint32 InExecutionOrder, uint8 InTreeDepth);

	CODEHACKER_API UAATCompositeNode* GetParentNode() const;
	
	CODEHACKER_API uint32 GetExecutionOrder() const;

	CODEHACKER_API uint8 GetTreeDepth() const;

private:

	UPROPERTY()
	TObjectPtr<UAATCompositeNode> m_parentNode;

	uint32 m_executionOrder;

	uint8 m_treeDepth;

};
