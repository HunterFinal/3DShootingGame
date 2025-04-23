// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"

#include "CHPlayerController.generated.h"

class ACHPlayerState;
class UCHAbilitySystemComponent;

UCLASS(Config = Game, meta = (ShortTooltip = "Code Hackerプレイヤーコントローラークラス"))
class CODEHACKER_API ACHPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	ACHPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//---Begin of APlayerController Interface
	virtual void PreProcessInput(const float DeltaTime, const bool bGamePause) override;
	virtual void PostProcessInput(const float DeltaTime, const bool bGamePause) override;
	//---End of APlayerController Interface

	UFUNCTION(BlueprintPure, Category = "CodeHacker|PlayerController")
	UCHAbilitySystemComponent* GetCHAbilitySystemComponent() const;

	UFUNCTION(BlueprintPure, Category = "CodeHacker|PlayerController")
	ACHPlayerState* GetCHPlayerStateChecked() const;
};
