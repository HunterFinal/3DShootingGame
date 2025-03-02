// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"

#include "CHPawnData.generated.h"

class APawn;
class UCHInputConfig;
class UCHCameraWork;
/**
 * 
 */
UCLASS(BlueprintType, Const, meta = (DisplayName = "Code Hacker Pawn Data", ShortTooltip = "Pawnを初期化するデータアセット"))
class CODEHACKER_API UCHPawnData : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UCHPawnData(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CodeHacker|Pawn")
	TSubclassOf<APawn> PawnClass;

	// プレイヤーコントローラーインプット設定
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CodeHacker|Pawn")
	TObjectPtr<UCHInputConfig> InputConfig;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CodeHacker|Pawn")
	TSubclassOf<UCHCameraWork> DefaultCameraWork;
};
