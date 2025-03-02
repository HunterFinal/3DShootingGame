// Fill out your copyright notice in the Description page of Project Settings.

#include "CHPlayerState.h"

#include "AbilitySystemComponent.h"
#include "Character/CHPawnData.h"
#include "CHPlayerController.h"
#include "CodeHackerLogChannels.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHPlayerState)

ACHPlayerState::ACHPlayerState(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
  , PawnData(nullptr)
  , AbilitySystemComponent(nullptr)
{
  AbilitySystemComponent = ObjectInitializer.CreateDefaultSubobject<UAbilitySystemComponent>(this, TEXT("AbilitySystemComponent"));
}

void ACHPlayerState::PreInitializeComponents()
{
  Super::PreInitializeComponents();
}

void ACHPlayerState::PostInitializeComponents()
{
  Super::PostInitializeComponents();

  check(AbilitySystemComponent != nullptr);
  AbilitySystemComponent->InitAbilityActorInfo(this, GetPawn());
}

void ACHPlayerState::Reset()
{
  Super::Reset();
}

void ACHPlayerState::ClientInitialize(AController* Controller)
{
  Super::ClientInitialize(Controller);
}

void ACHPlayerState::CopyProperties(APlayerState* PlayerState)
{
  Super::CopyProperties(PlayerState);
}

void ACHPlayerState::OnDeactivated()
{
  Super::OnDeactivated();
}

void ACHPlayerState::OnReactivated()
{
  Super::OnReactivated();
}

ACHPlayerController* ACHPlayerState::GetCHPlayerController() const
{
  return Cast<ACHPlayerController>(GetOwner());
}

UAbilitySystemComponent* ACHPlayerState::GetCHAbilitySystemComponent() const
{
  return AbilitySystemComponent;
}

UAbilitySystemComponent* ACHPlayerState::GetAbilitySystemComponent() const
{
  return GetCHAbilitySystemComponent();
}

void ACHPlayerState::SetPawnData(const UCHPawnData* InPawnData)
{
  check(InPawnData);

  if (PawnData != nullptr)
  {
    UE_LOG(LogCodeHacker, Error, TEXT("Trying to set PawnData [%s] on player state [%s] that already has valid PawnData [%s]."), *GetNameSafe(InPawnData), *GetNameSafe(this), *GetNameSafe(PawnData));
    return;
  }

  PawnData = InPawnData;

  // TODO
  // Setup AbilitySystemComponent

}

