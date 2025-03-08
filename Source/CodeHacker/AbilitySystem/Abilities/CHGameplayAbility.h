// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Abilities/GameplayAbility.h"

#include "CHGameplayAbility.generated.h"

//---Begin of Engine Define Forward Declaration
class APawn;
class ACharacter;
class AController;
//---End of Engine Define Forward Declaration

//---Begin of CHAbilitySystem Forward Declaration
class UCHAbilitySystemComponent;
class UCHAbilityCost;
//---End of CHAbilitySystem Forward Declaration

//---Begin of CHCamera Forward Declaration
class UCHCameraWork;
//---End of CHCamera Forward Declaration

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories = Input, meta = (ShortTooltip = "Code Hacker に使うGameplay Ability親クラス"))
class CODEHACKER_API UCHGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UCHGameplayAbility(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Ability")
	APawn* GetPawnFromActorInfo() const;

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Ability")
	ACharacter*	GetCharacterFromActorInfo() const;

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Ability")
	AController* GetControllerFromActorInfo() const;

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Ability")
	UCHAbilitySystemComponent* GetCHAbilitySystemComponent() const;

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Ability")
	void SetCameraWork(TSubclassOf<UCHCameraWork> CameraWorkClass);

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Ability")
	void ClearCameraWork();

protected:
	///---Begin of UGameplayAbility
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const override;
	///---End of UGameplayAbility

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Ability|Advanced")
	TArray<TObjectPtr<UCHAbilityCost>> AdditionalCosts;

	UPROPERTY()
	TSubclassOf<UCHCameraWork> AbilityCameraWorkClass;
};
