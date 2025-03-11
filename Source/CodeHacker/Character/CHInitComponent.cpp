// Fill out your copyright notice in the Description page of Project Settings.


#include "CHInitComponent.h"

#include "Engine/LocalPlayer.h"
#include "GameFramework/Pawn.h"
#include "Player/CHPlayerState.h"
#include "AbilitySystem/CHAbilitySystemComponent.h"
#include "Character/CodeHackerPawnExtensionComponent.h"
#include "Character/CHPawnData.h"

#include "Input/CHInputComponent.h"
#include "Input/CHInputMappingContextAndPriority.h"

#include "EnhancedInputSubsystems.h"
#include "UserSettings/EnhancedInputUserSettings.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHInitComponent)

UCHInitComponent::UCHInitComponent(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
  , bAIUseASC(false)
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
  ensureAlwaysMsgf((initComponents.Num() == 1), TEXT("Only one CHInitComponent should exist on [%s]"), *GetNameSafe(pawn));

}

void UCHInitComponent::BeginPlay()
{
  Super::BeginPlay();

  // ASCを初期化
  InitializeASC();
  // インプットを初期化
  InitializeInput();
}

void UCHInitComponent::InitializeASC()
{
  APawn* ownerPawn = GetPawnChecked<APawn>();
  ACHPlayerState* playerState = ownerPawn->GetPlayerState<ACHPlayerState>();

  UCHAbilitySystemComponent* ASC = nullptr;
  // プレイヤーじゃなかったら設定されているAbilitySystemComponentで初期化
  if (playerState == nullptr)
  {
    ValidationASC();

    ASC = NewObject<UCHAbilitySystemComponent>(/**Component Outer */ownerPawn, AbilitySystemComponentClass);
    ASC->RegisterComponent();

  }
  else
  {
    ASC = playerState->GetCHAbilitySystemComponent();
  }

  check(ASC != nullptr);

  UCodeHackerPawnExtensionComponent* pawnExtComp = ownerPawn->GetComponentByClass<UCodeHackerPawnExtensionComponent>();
  check(pawnExtComp != nullptr);

  const bool bIsLocallyControlled = ownerPawn->IsLocallyControlled();
  const bool bIsBot = ownerPawn->IsBotControlled();

  // PlayerのASC所有者はPlayerState
  if (bIsLocallyControlled && !bIsBot)
  {
    pawnExtComp->InitializeAbilitySystem(ASC, playerState);
  }
  // 敵AIのASC所有者は敵Pawn自身
  else
  {
    pawnExtComp->InitializeAbilitySystem(ASC, ownerPawn);
  }
}

void UCHInitComponent::InitializeInput()
{
  const APawn* ownerPawn = GetPawnChecked<APawn>();
  const bool bIsLocallyControlled = ownerPawn->IsLocallyControlled();
  const bool bIsBot = ownerPawn->IsBotControlled();

  if (bIsLocallyControlled && !bIsBot)
  {
    UInputComponent* inputComponent = ownerPawn->InputComponent;
    if (inputComponent != nullptr)
    {
      InitializePlayerInput_Implementation(inputComponent);
    }
  }
}

void UCHInitComponent::InitializePlayerInput_Implementation(UInputComponent* PlayerInputComponent)
{
  check(PlayerInputComponent != nullptr);

  const APawn* playerPawn = GetPawnChecked<APawn>();

  const APlayerController* playerController = playerPawn->GetController<APlayerController>();
  check(playerController != nullptr);

  const ULocalPlayer* localPlayer = playerController->GetLocalPlayer();
  check(localPlayer != nullptr);
  
  UEnhancedInputLocalPlayerSubsystem* inputSubsystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
  check(inputSubsystem != nullptr);

  inputSubsystem->ClearAllMappings();

  UCodeHackerPawnExtensionComponent* pawnExtComp = playerPawn->GetComponentByClass<UCodeHackerPawnExtensionComponent>();
  if(pawnExtComp != nullptr)
  {
    const UCHPawnData* pawnData = pawnExtComp->GetPawnData<UCHPawnData>();
    if (pawnData != nullptr)
    {
      const UCHInputConfig* inputConfig = pawnData->InputConfig;
      if (inputConfig != nullptr)
      {
        for (const FCHInputMappingContextAndPriority& mapping : DefaultInputMappings)
        {
          UInputMappingContext* imc = mapping.InputMapping.Get();
          if (imc != nullptr)
          {
            UEnhancedInputUserSettings* settings = inputSubsystem->GetUserSettings();
            if (settings != nullptr)
            {
              settings->RegisterInputMappingContext(imc);
            }

            FModifyContextOptions options{};
            options.bIgnoreAllPressedKeysUntilRelease = false;

            // ローカルプレイヤーにIMCを追加する
            inputSubsystem->AddMappingContext(imc, mapping.Priority, options);
          }
        }

        UCHInputComponent* chInputComp = Cast<UCHInputComponent>(PlayerInputComponent);
        if (ensureMsgf(chInputComp, TEXT("Unexpect Input Component class, Gameplay Abilities will not be bound to input.Change input component to UCHInputComponent or a subclass of it")))
        {
          chInputComp->AddInputMappings(inputConfig, inputSubsystem);

          chInputComp->BindAbilityActions(inputConfig, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);


        }
      }
    }
  }
}

void UCHInitComponent::Input_AbilityInputPressed(FGameplayTag InputTag)
{
  const APawn* ownerPawn = GetPawn<APawn>();
  if (ownerPawn != nullptr)
  {
    UCodeHackerPawnExtensionComponent* pawnExt = UCodeHackerPawnExtensionComponent::FindPawnExtensionComponent(ownerPawn);
    if (pawnExt != nullptr)
    {
      UCHAbilitySystemComponent* asc = pawnExt->GetCHAbilitySystemComponent();
      if (asc != nullptr)
      {
        asc->AbilityInputTagPressed(InputTag);
      }
    }
  }
}

void UCHInitComponent::Input_AbilityInputReleased(FGameplayTag InputTag)
{
  const APawn* ownerPawn = GetPawn<APawn>();
  if (ownerPawn != nullptr)
  {
    UCodeHackerPawnExtensionComponent* pawnExt = UCodeHackerPawnExtensionComponent::FindPawnExtensionComponent(ownerPawn);
    if (pawnExt != nullptr)
    {
      UCHAbilitySystemComponent* asc = pawnExt->GetCHAbilitySystemComponent();
      if (asc != nullptr)
      {
        asc->AbilityInputTagReleased(InputTag);
      }
    }
  }
}
void UCHInitComponent::ValidationASC() const
{
  if (!bAIUseASC)
  {
    return;
  }

  ensureAlwaysMsgf((AbilitySystemComponentClass != nullptr), TEXT("CHInitComponent on [%s] needs to set Parameter of AbilitySystemComponentClass"), *GetNameSafe(GetOwner()));

  const APawn* owner = GetPawnChecked<APawn>();
  TArray<UActorComponent*> registeredASCComponents;
  owner->GetComponents(UCHAbilitySystemComponent::StaticClass(), registeredASCComponents);
  ensureAlwaysMsgf((registeredASCComponents.Num() == 1), TEXT("AbilitySystemComponent is already exists on [%s]"), *GetNameSafe(owner));
}
