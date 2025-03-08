// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/GameModeBase.h"

#include "CodeHackerGameMode.generated.h"

class AController;
class UCHPawnData;

UCLASS(Config = Game, meta = (ShortTooltip = "Code Hacker専用GameMode"))
class ACodeHackerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ACodeHackerGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// @TODO
	// Remove const for temp test
	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Pawn")
	const UCHPawnData* GetPawnDataForController(const AController* InController);

private:

	// @TODO Temp Solution
	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|Pawn|InitData")
	TSubclassOf<UCHPawnData> PawnDataClass;

	UPROPERTY(Transient)
	TObjectPtr<const UCHPawnData> PawnData;
};



