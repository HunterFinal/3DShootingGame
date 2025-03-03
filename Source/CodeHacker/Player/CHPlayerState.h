// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"

#include "CHPlayerState.generated.h"

class AController;
class ACHPlayerController;
class UCHPawnData;

class UCHAbilitySystemComponent;
class UCHHealthSet;
/**
 * 
 */
UCLASS(Config = Game, meta = (ShortTooltip = "Code Hacker Player State for Ability System"))
class CODEHACKER_API ACHPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	ACHPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//---Begin of AActor Interface
	virtual void PreInitializeComponents() override;
	virtual void PostInitializeComponents() override;
	//---End of AActor Interface

	//---Begin of APlayerState Interface
	virtual void Reset() override;
	virtual void ClientInitialize(AController* Controller) override;
	virtual void CopyProperties(APlayerState* PlayerState) override;
	virtual void OnDeactivated() override;
	virtual void OnReactivated() override;
	//---End of APlayerState Interface

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|PlayerState")
	ACHPlayerController* GetCHPlayerController() const;

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|PlayerState")
	UCHAbilitySystemComponent* GetCHAbilitySystemComponent() const;

	//---Begin of IAbilitySystemInterface Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//---End of IAbilitySystemInterface Interface

	template<typename PawnDataType>
	PawnDataType* GetPawnData() const;
	void SetPawnData(const UCHPawnData* InPawnData);

protected:
	UPROPERTY()
	TObjectPtr<const UCHPawnData> PawnData;

private:
	UPROPERTY(VisibleAnywhere, Category = "CodeHacker|PlayerState")
	TObjectPtr<UCHAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<const UCHHealthSet> HealthSet;

};

template<typename PawnDataType>
PawnDataType* ACHPlayerState::GetPawnData() const
{
	return Cast<PawnDataType>(PawnData);
}
