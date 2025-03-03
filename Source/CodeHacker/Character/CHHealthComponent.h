// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"

#include "CHHealthComponent.generated.h"

class UCHHealthComponent;

class UCHAbilitySystemComponent;
class UCHHealthSet;

struct FGameplayEffectSpec;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCHHealth_DeathDelegate, AActor*, OwningActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FCHHealth_AttributeChangedDelegate, UCHHealthComponent*, HealthComponent, float, OldValue, float, NewValue, AActor*, Instigator);

UCLASS(Blueprintable, ClassGroup=(CodeHacker), meta=(BlueprintSpawnableComponent) )
class CODEHACKER_API UCHHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UCHHealthComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

	virtual void BeginPlay() override;

public:

	UFUNCTION(BlueprintPure, Category = "CodeHacker|Health")
	static UCHHealthComponent* FindHealthComponent(const AActor* Actor);

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Health")
	void InitializeWithAbilitySystem(UCHAbilitySystemComponent* InASC);

	UFUNCTION(BlueprintCallable, Category = "CodeHacker|Health")
	void UninitializeFromAbilitySystem();

	UFUNCTION(BlueprintPure, Category = "CodeHacker|Health")
	float GetHealth() const;

	UFUNCTION(BlueprintPure, Category = "CodeHacker|Health")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintPure, Category = "CodeHacker|Health")
	float GetHealthNormalized() const;

public:

	UPROPERTY(BlueprintAssignable)
	FCHHealth_AttributeChangedDelegate OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FCHHealth_AttributeChangedDelegate OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FCHHealth_DeathDelegate OnDeathStarted;

	UPROPERTY(BlueprintAssignable)
	FCHHealth_DeathDelegate OnDeathFinished;

protected:

	//---Begin of UActorComponent Interface
	virtual void OnUnregister() override;
	//---End of UACtorComponent Interface

	virtual void HandleHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue);
	virtual void HandleMaxHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue);
	virtual void HandleOutOfHealth(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue);

private:

	UPROPERTY()
	TObjectPtr<UCHAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<const UCHHealthSet> HealthSet;
		
};

