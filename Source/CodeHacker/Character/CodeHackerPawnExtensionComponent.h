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

	UCodeHackerPawnExtensionComponent(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category = "CodeHacker|PawnExt")
	UAbilitySystemComponent* GetAbilitySystemComponent() const;

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|PawnExt")
	static UCodeHackerPawnExtensionComponent* FindPawnExtensionComponent(const AActor* Actor);

	void InitializeAbilitySystem(UAbilitySystemComponent* InASC, AActor* InOwnerActor);

	void UninitializeAbilitySystem();

	void HandleControllerChanged();

protected:

	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Code Hacker|Gameplay Ability")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
