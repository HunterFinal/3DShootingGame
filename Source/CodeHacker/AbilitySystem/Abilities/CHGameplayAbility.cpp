// Fill out your copyright notice in the Description page of Project Settings.


#include "CHGameplayAbility.h"

#include "GameFramework/Character.h"
#include "Camera/CHCameraWork.h"

#include "AbilitySystem/CHAbilitySystemComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHGameplayAbility)

#define ENSURE_ABILITY_IS_INSTANTIATED_OR_RETURN(FunctionName, ReturnValue)																				\
{																																						\
	if (!ensure(IsInstantiated()))																														\
	{																																					\
		ABILITY_LOG(Error, TEXT("%s: " #FunctionName " cannot be called on a non-instanced ability. Check the instancing policy."), *GetPathName());	\
		return ReturnValue;																																\
	}																																					\
}

UCHGameplayAbility::UCHGameplayAbility(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
}

APawn* UCHGameplayAbility::GetPawnFromActorInfo() const
{
  return (CurrentActorInfo != nullptr) ? (Cast<APawn>(CurrentActorInfo->AvatarActor.Get())) : nullptr;
}

ACharacter* UCHGameplayAbility::GetCharacterFromActorInfo() const
{
  return (CurrentActorInfo != nullptr) ? (Cast<ACharacter>(CurrentActorInfo->AvatarActor.Get())) : nullptr;
}

AController* UCHGameplayAbility::GetControllerFromActorInfo() const
{
  const APawn* avatarPawn = GetPawnFromActorInfo();
  return (avatarPawn != nullptr) ? (avatarPawn->GetController()) : nullptr;
}

UCHAbilitySystemComponent* UCHGameplayAbility::GetCHAbilitySystemComponent() const
{
  return (CurrentActorInfo != nullptr) ? (Cast<UCHAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent.Get())) : nullptr; 
}

bool UCHGameplayAbility::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
  bool result = Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags);
  if (result)
  {
    return true;
  }

  return false;
}

void UCHGameplayAbility::SetCameraWork(TSubclassOf<UCHCameraWork> CameraWorkClass)
{
  //ENSURE_ABILITY_IS_INSTANTIATED_OR_RETURN(SetCameraWork, );
}

void UCHGameplayAbility::ClearCameraWork()
{
  
}