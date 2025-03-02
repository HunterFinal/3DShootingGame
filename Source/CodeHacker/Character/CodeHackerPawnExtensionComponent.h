// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CodeHackerPawnExtensionComponent.generated.h"

class UAbilitySystemComponent;

/**
 * Code Hacker Pawnにあるコンポネントを初期化するコンポネント 
 * 
 * PawnやCharacter専用コンポネント
 */ 
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODEHACKER_API UCodeHackerPawnExtensionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCodeHackerPawnExtensionComponent(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	//---HINT---Get pawn and controller that owns the component. Make sure this only use on pawn or character
	// PawnやCharacter専用
	template<typename PawnType>
	PawnType* GetPawn() const;

	template<typename PawnType>
	PawnType* GetPawnChecked() const;

	template<typename ControllerType>
	ControllerType* GetController() const;
	//---End of HINT

	UFUNCTION(BlueprintPure, Category = "CodeHacker|Pawn")
	UAbilitySystemComponent* GetAbilitySystemComponent() const;

	void InitializeAbilitySystem(UAbilitySystemComponent* InASC, AActor* InOwnerActor);

	void UninitializeAbilitySystem();

	void HandleControllerChanged();

private:
	UPROPERTY(VisibleAnywhere, Category = "Code Hacker|Gameplay Ability")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};

template<typename PawnType>
PawnType* UCodeHackerPawnExtensionComponent::GetPawn() const
{
	static_assert(TPointerIsConvertibleFromTo<PawnType, APawn>::Value, "[PawnType] template parameter to GetPawn must be derived from APawn");
	return Cast<PawnType>(GetOwner());
}

template<typename PawnType>
PawnType* UCodeHackerPawnExtensionComponent::GetPawnChecked() const
{
	static_assert(TPointerIsConvertibleFromTo<PawnType, APawn>::Value, "[PawnType] template parameter to GetPawnChecked must be derived from APawn");
	return CastChecked<PawnType>(GetOwner());
}

template<typename ControllerType>
ControllerType* UCodeHackerPawnExtensionComponent::GetController() const
{
	static_assert(TPointerIsConvertibleFromTo<ControllerType, AController>::Value, "[ControllerType] template parameter to GetController must be derived from AController");
	return GetPawnChecked<APawn>()->GetController<ControllerType>();
}
