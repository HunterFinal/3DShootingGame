// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"

#include "CHPlayerController.generated.h"

/**
 * 
 */
UCLASS(Config = Game, meta = (ShortTooltip = "Code Hackerプレイヤーコントローラークラス"))
class CODEHACKER_API ACHPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACHPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
