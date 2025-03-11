// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionAbilityTreeComponent.h"
#include "ActionAbilityTree.h"
#include "GameplayTagContainer.h"

#include "AbilitySystem/Assets/ActionAbilityTreeAsset.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(ActionAbilityTreeComponent)

UActionAbilityTreeComponent::UActionAbilityTreeComponent(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
  PrimaryComponentTick.bCanEverTick = false;
  PrimaryComponentTick.bStartWithTickEnabled = false;

  ActionAbilityTree = CreateDefaultSubobject<UActionAbilityTree>(TEXT("AAT_Instance"));
}

bool UActionAbilityTreeComponent::IsActived() const
{
  return m_bIsActived;
}

void UActionAbilityTreeComponent::ReceiveAbilityInputTag(const FGameplayTag& InputTag, /**Out */EAATInputResult& OutResult)
{
  
}

void UActionAbilityTreeComponent::OnRegister()
{
  Super::OnRegister();

  const APawn* pawn = GetPawn<APawn>();
  ensureAlwaysMsgf((pawn != nullptr), TEXT("UActionAbilityTreeComponent on [%s] can only be added to Pawn actors"), *GetNameSafe(pawn));

  TArray<UActorComponent*> registeredAATComps;
  pawn->GetComponents(ThisClass::StaticClass(), registeredAATComps);
  ensureAlwaysMsgf((registeredAATComps.Num() == 1), TEXT("Only one UActionAbilityTreeComponent should exist on [%s]"));

}

void UActionAbilityTreeComponent::InitializeComponent()
{
  Super::InitializeComponent();

  if (DefaultActionAbilityTreeAsset == nullptr)
  {
    return;
  }

  for (const auto& AATChain : DefaultActionAbilityTreeAsset->ActionChains)
  {
    for (const auto& AATChainNode : AATChain.ChainNodes)
    {

    }
  }
}

