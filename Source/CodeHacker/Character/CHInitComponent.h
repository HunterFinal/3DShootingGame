// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Extensions/CHPawnComponent.h"

#include "CHInitComponent.generated.h"

class UCHAbilitySystemComponent;
class UInputComponent;
struct FCHInputMappingContextAndPriority;
struct FGameplayTag;
/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (CodeHacker) ,meta = (BlueprintSpawnableComponent))
class CODEHACKER_API UCHInitComponent : public UCHPawnComponent
{
	GENERATED_BODY()
	
public:
	UCHInitComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintPure, Category = "CodeHacker|PawnInitialization")
	static UCHInitComponent* FindInitComponent(const APawn* pawn);

protected:

	virtual void OnRegister() override;
	virtual void BeginPlay() override;

private:

	/**AbilitySystemComponentを初期化する */
	void InitializeASC();
	/**インプットを初期化する */
	void InitializeInput();

	void InitializePlayerInput_Implementation(UInputComponent* PlayerInputComponent);

	/**
	 * プロパティのAbilitySystemComponentClassの有効性チェック
	 * ///---敵AIなど(プレイヤー以外)しかチェックしない---///
	 * ///---プレイヤーのASCはPlayerStateで作成済み---///
	 */
	void ValidationASC() const;

	void Input_AbilityInputPressed(FGameplayTag InputTag);
	void Input_AbilityInputReleased(FGameplayTag InputTag);

private:

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|Init", meta = (DisplayName = "AI Use Ability System Component"))
	bool bAIUseASC;

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|Init", meta = (EditCondition = "bAIUseASC == true", EditConditionHides))
	TSubclassOf<UCHAbilitySystemComponent> AbilitySystemComponentClass;

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|Init|Input", meta = (EditCondition = "bAIUseASC == false", EditConditionHides, DisplayName = "Player Default Input Mappings"))
	TArray<FCHInputMappingContextAndPriority> DefaultInputMappings;
};
