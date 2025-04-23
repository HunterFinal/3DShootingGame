// Copyright Epic Games, Inc. All Rights Reserved.

#include "CodeHackerGameMode.h"

#include "UObject/ConstructorHelpers.h"
#include "Character/CHPawnData.h"
#include "Player/CHPlayerState.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CodeHackerGameMode)

ACodeHackerGameMode::ACodeHackerGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, PawnDataClass(nullptr)
	, PawnData(nullptr)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ACodeHackerGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}

void ACodeHackerGameMode::InitGameState()
{
	Super::InitGameState();
}

const UCHPawnData* ACodeHackerGameMode::GetPawnDataForController(const AController* InController)
{
	if (InController == nullptr)
	{
		return nullptr;
	}
	
	// プレイヤーだったらPlayerStateから取得してみる
	const ACHPlayerState* playerState = InController->GetPlayerState<ACHPlayerState>();
	if (playerState != nullptr)
	{
		const UCHPawnData* playerPawnData = playerState->GetPawnData<UCHPawnData>();
		if (playerPawnData != nullptr)
		{
			return playerPawnData;
		}
	}

	// @TODO
	// なかったら今のゲームモードからデフォルト値を使う
	if (PawnData == nullptr)
	{
		if (PawnDataClass != nullptr)
		{
			PawnData = NewObject<UCHPawnData>(this, PawnDataClass);
		}
	}

	return PawnData;

}




