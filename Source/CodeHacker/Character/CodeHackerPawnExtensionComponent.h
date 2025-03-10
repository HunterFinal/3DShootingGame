// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Extensions/CHPawnComponent.h"

#include "CodeHackerPawnExtensionComponent.generated.h"

class UCHAbilitySystemComponent;
class UCHPawnData;

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
	UCHAbilitySystemComponent* GetCHAbilitySystemComponent() const;
	
	UFUNCTION(BlueprintCallable, Category = "CodeHacker|PawnExt")
	static UCodeHackerPawnExtensionComponent* FindPawnExtensionComponent(const AActor* Actor);

	template<typename PawnDataType>
	const PawnDataType* GetPawnData() const;

	void InitializeAbilitySystem(UCHAbilitySystemComponent* InASC, AActor* InOwnerActor);

	void UninitializeAbilitySystem();

	void HandleControllerChanged();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, Category = "CodeHacker|GameplayAbility")
	TObjectPtr<UCHAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<const UCHPawnData> PawnData;
};

template<typename PawnDataType>
const PawnDataType* UCodeHackerPawnExtensionComponent::GetPawnData() const
{
	return Cast<PawnDataType>(PawnData);
}
