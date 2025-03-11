// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Extensions/CHPawnComponent.h"

#include "ActionAbilityTreeComponent.generated.h"

class UActionAbilityTreeAsset;
class UActionAbilityTree;
class UGameplayAbility;
struct FGameplayTag;

struct FActionAbilityNodeInstance
{

};

UENUM(BlueprintType)
enum class EAATInputResult : uint8
{
  // Input Accepted
  Succeeded,

  // Input Denied
  Failed,
}
/**
 * 
 */
UCLASS(Config = Game, HideCategories = (Sockets, Collision), meta = (ShortTooltip = "アクションアビリティコンポーネント", BlueprintSpawnableComponent))
class CODEHACKER_API UActionAbilityTreeComponent : public UCHPawnComponent
{
	GENERATED_BODY()

public:

	UActionAbilityTreeComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	UFUNCTION(BlueprintPure, Category = "ActionAbilityTree")
	bool IsActived() const;

	virtual void ReceiveAbilityInputTag(const FGameplayTag& InputTag, /**Out */EAATInputResult& OutResult);

protected:

	//---Begin of UActorComponent Interface
	virtual void OnRegister() override;
	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;
	//---End of UActorComponent Interface

private:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ActionAbilityTree", meta = (AllowPrivateAccess = "true", DisplayName = "Action Ability Tree Asset"))
	TObjectPtr<UActionAbilityTreeAsset> DefaultActionAbilityTreeAsset;

	UPROPERTY()
	TObjectPtr<UActionAbilityTree> ActionAbilityTree;

	TArray<FActionAbilityNodeInstance> m_instanceStack;

	uint8 m_bIsActived : 1;
};
