// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Extensions/CHPawnComponent.h"

#include "CodeHackerPawnExtensionComponent.generated.h"

class UAbilitySystemComponent;

/**
 * Code Hacker Pawnにあるコンポネントを初期化するコンポネント 
 * 
 * PawnやCharacter専用コンポネント
 */ 
UCLASS()
class CODEHACKER_API UCodeHackerPawnExtensionComponent : public UCHPawnComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCodeHackerPawnExtensionComponent(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "CodeHacker|Pawn")
	UAbilitySystemComponent* GetAbilitySystemComponent() const;

	void InitializeAbilitySystem(UAbilitySystemComponent* InASC, AActor* InOwnerActor);

	void UninitializeAbilitySystem();

	void HandleControllerChanged();

private:
	UPROPERTY(VisibleAnywhere, Category = "Code Hacker|Gameplay Ability")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
