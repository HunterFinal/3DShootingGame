// Copyright Epic Games, Inc. All Rights Reserved.

#include "CodeHackerGameMode.h"
#include "CodeHackerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACodeHackerGameMode::ACodeHackerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
