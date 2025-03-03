// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerState.h"

#include "CHPawnComponent.generated.h"

class FTimerManager;
/**
 * 	CHPawnComponent
 *  ActorComponent for Code Hacker
 *  Made for APawn
 */
UCLASS()
class CODEHACKER_API UCHPawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCHPawnComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/**ゲームインスタントを取得 */
	template<typename GameInstanceType>
	GameInstanceType* GetGameInstance() const;

	template<typename GameInstanceType>
	GameInstanceType* GetGameInstanceChecked() const;

	/**このコンポーネントを所持するAPawnを取得 */
	template<typename PawnType>
	PawnType* GetPawn() const;

	template<typename PawnType>
	PawnType* GetPawnChecked() const;

	/**
	 * このコンポーネントを所持するAPawnのPlayerStateを取得
	 * AIだとnullptrを返す可能性が高い
	 */
	template<typename PlayerStateType>
	PlayerStateType* GetPlayerState() const;

	/**
	 * このコンポーネントを所持するAPawnのControllerControllerを取得
	 * PlayerだとAPlayerController及び子クラス, AIだとAAIController及び子クラス
	 */
	template<typename ControllerType>
	ControllerType* GetController() const;

	FTimerManager& GetWorldTimerManager() const;
	
};

//---Begin of UCHPawnComponent Template Interface Definition
#pragma region UCHPawnComponent Template Interface Definition
template<typename GameInstanceType>
GameInstanceType* UCHPawnComponent::GetGameInstance() const
{
	static_assert(TPointerIsConvertibleFromTo<GameInstanceType, UGameInstance>::Value, "[GameInstanceType] template parameter to GetGameInstance must be derived from UGameInstance");
	AActor* owner = GetOwner();
	return (owner != nullptr) ? (owner->GetGameInstance<GameInstanceType>()) : nullptr;
}

template<typename GameInstanceType>
GameInstanceType* UCHPawnComponent::GetGameInstanceChecked() const
{
	static_assert(TPointerIsConvertibleFromTo<GameInstanceType, UGameInstance>::Value, "[GameInstanceType] template parameter to GetGameInstanceChecked must be derived from UGameInstance");
	AActor* owner = GetOwner();
	check(owner != nullptr);
	GameInstanceType* gameInstance = owner->GetGameInstance<GameInstanceType>();
	check(gameInstance != nullptr);
	return gameInstance;
}

template<typename PawnType>
PawnType* UCHPawnComponent::GetPawn() const
{
	static_assert(TPointerIsConvertibleFromTo<PawnType, APawn>::Value, "[PawnType] template parameter to GetPawn must be derived from APawn");
	return Cast<APawn>(GetOwner());
}

template<typename PawnType>
PawnType* UCHPawnComponent::GetPawnChecked() const
{
	static_assert(TPointerIsConvertibleFromTo<PawnType, APawn>::Value, "[PawnType] template parameter to GetPawnChecked must be derived from APawn");
	return CastChecked<APawn>(GetOwner());
}

template<typename PlayerStateType>
PlayerStateType* UCHPawnComponent::GetPlayerState() const
{
	static_assert(TPointerIsConvertibleFromTo<PlayerStateType, APlayerState>::Value, "[PlayerStateType] template parameter to GetPlayerState must be derived from APlayerState");
	return GetPawnChecked<APawn>()->GetPlayerState<PlayerStateType>();
}

template<typename ControllerType>
ControllerType* UCHPawnComponent::GetController() const
{
	static_assert(TPointerIsConvertibleFromTo<ControllerType, AController>::Value, "[ControllerType] template parameter to GetController must be derived from AController");
	return GetPawnChecked<APawn>()->GetController<ControllerType>();
}

#pragma endregion UCHPawnComponent Template Interface Definition
//---End of UCHPawnComponent Template Interface Definition