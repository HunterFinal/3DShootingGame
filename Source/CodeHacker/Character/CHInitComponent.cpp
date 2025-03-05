// Fill out your copyright notice in the Description page of Project Settings.


#include "CHInitComponent.h"

#include "GameFramework/Pawn.h"
#include "Player/CHPlayerState.h"
#include "AbilitySystem/CHAbilitySystemComponent.h"
#include "Character/CodeHackerPawnExtensionComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHInitComponent)

UCHInitComponent::UCHInitComponent(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
  , AbilitySystemComponentClass(nullptr)
{
}

UCHInitComponent* UCHInitComponent::FindInitComponent(const APawn* pawn)
{
  return (pawn != nullptr) ? pawn->FindComponentByClass<UCHInitComponent>() : nullptr;
}

void UCHInitComponent::OnRegister()
{
  Super::OnRegister();

  const APawn* pawn = GetPawn<APawn>();
  ensureAlwaysMsgf((pawn != nullptr), TEXT("CHInitComponent on [%s] can only be added to Pawn actors"), *GetNameSafe(pawn));

  TArray<UActorComponent*> initComponents;
  pawn->GetComponents(UCHInitComponent::StaticClass(), initComponents);
  ensureAlwaysMsgf((initComponents.Num() == 1), TEXT("Only one InitComponent should exist on [%s]"), *GetNameSafe(pawn));

}

void UCHInitComponent::BeginPlay()
{
  Super::BeginPlay();

  APawn* ownerPawn = GetPawnChecked<APawn>();
  ACHPlayerState* playerState = ownerPawn->GetPlayerState<ACHPlayerState>();

  UCHAbilitySystemComponent* ASC = nullptr;
  // プレイヤーじゃなかったら設定されているAbilitySystemComponentで初期化
  if (playerState == nullptr)
  {
    ValidationASC();

    ASC = NewObject<UCHAbilitySystemComponent>(ownerPawn, AbilitySystemComponentClass);
    ASC->RegisterComponent();

  }
  else
  {
    ASC = playerState->GetCHAbilitySystemComponent();
  }

  check(ASC != nullptr);

  UCodeHackerPawnExtensionComponent* pawnExtComp = ownerPawn->GetComponentByClass<UCodeHackerPawnExtensionComponent>();
  check(pawnExtComp != nullptr);

  pawnExtComp->InitializeAbilitySystem(ASC, ownerPawn);
}

void UCHInitComponent::ValidationASC() const
{
  ensureAlwaysMsgf((AbilitySystemComponentClass != nullptr), TEXT("CHInitComponent on [%s] needs to set Parameter of AbilitySystemComponentClass"), *GetNameSafe(GetOwner()));

  const APawn* owner = GetPawnChecked<APawn>();
  TArray<UActorComponent*> registeredASCComponents;
  owner->GetComponents(UCHAbilitySystemComponent::StaticClass(), registeredASCComponents);
  ensureAlwaysMsgf((registeredASCComponents.Num() == 1), TEXT("AbilitySystemComponent is already exists on [%s]"), *GetNameSafe(owner));
}
