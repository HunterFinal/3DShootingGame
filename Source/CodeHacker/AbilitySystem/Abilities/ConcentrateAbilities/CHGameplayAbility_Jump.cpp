// Fill out your copyright notice in the Description page of Project Settings.


#include "CHGameplayAbility_Jump.h"

#include "GameFramework/Character.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHGameplayAbility_Jump)

UCHGameplayAbility_Jump::UCHGameplayAbility_Jump(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
}

bool UCHGameplayAbility_Jump::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, FGameplayTagContainer* OptionalRelevantTags) const
{
  if (ActorInfo == nullptr || !ActorInfo->AvatarActor.IsValid())
  {
    return false;
  }

  return Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
}

void UCHGameplayAbility_Jump::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
  JumpStop();

  Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UCHGameplayAbility_Jump::JumpStart()
{
  ACharacter* avatarCharacter = GetCharacterFromActorInfo();
  if (avatarCharacter != nullptr)
  {
    if (!avatarCharacter->bPressedJump)
    {
      avatarCharacter->UnCrouch();
      avatarCharacter->Jump();
    }
  }

  K2_OnJumpStart();
}

void UCHGameplayAbility_Jump::JumpStop()
{
  ACharacter* avatarCharacter = GetCharacterFromActorInfo();
  if (avatarCharacter != nullptr)
  {
    if (avatarCharacter->bPressedJump)
    {
      avatarCharacter->StopJumping();
    }
  }

  K2_OnJumpStop();
}





