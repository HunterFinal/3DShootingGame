// Fill out your copyright notice in the Description page of Project Settings.


#include "CHHealthComponent.h"

#include "CodeHackerLogChannels.h"
#include "AbilitySystem/CHAbilitySystemComponent.h"
#include "AbilitySystem/Attributes/CHHealthSet.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHHealthComponent)

// Sets default values for this component's properties
UCHHealthComponent::UCHHealthComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, AbilitySystemComponent(nullptr)
	, HealthSet(nullptr)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;

	// ...
}


// Called when the game starts
void UCHHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

UCHHealthComponent* UCHHealthComponent::FindHealthComponent(const AActor* Actor)
{
	return (Actor != nullptr) ? (Actor->FindComponentByClass<UCHHealthComponent>()) : nullptr;
}

void UCHHealthComponent::InitializeWithAbilitySystem(UCHAbilitySystemComponent* InASC)
{
	AActor* owner = GetOwner();
	check(owner != nullptr);

	if (AbilitySystemComponent != nullptr)
	{
		UE_LOG(LogCodeHacker, Error, TEXT("[%s] : Health component for owner [%s] has already been initialized with an ability system component"), *GetNameSafe(this), *GetNameSafe(owner));
		return;
	}

	if (InASC == nullptr)
	{
		UE_LOG(LogCodeHacker, Error, TEXT("[%s] : Cannot initialize health component for owner [%s] with NULL ability system component"), *GetNameSafe(this), *GetNameSafe(owner));
		return;
	}

	AbilitySystemComponent = InASC;

	HealthSet = AbilitySystemComponent->GetSet<UCHHealthSet>();
	if (HealthSet == nullptr)
	{	
		UE_LOG(LogCodeHacker, Error, TEXT("[%s] : Cannot initialize health component for owner [%s] with NULL health set"), *GetNameSafe(this), *GetNameSafe(owner));
		return;
	}

	// UCHHealthSetの変化を監視するデリゲートを登録
	UCHHealthSet* mutableHealthSet = const_cast<UCHHealthSet*>(HealthSet.Get());

	mutableHealthSet->OnHealthChanged.AddUObject(this, &ThisClass::HandleHealthChanged);
	mutableHealthSet->OnMaxHealthChanged.AddUObject(this, &ThisClass::HandleMaxHealthChanged);
	mutableHealthSet->OnOutOfHealth.AddUObject(this, &ThisClass::HandleOutOfHealth);

	// Reset Attributes to default values;
	AbilitySystemComponent->SetNumericAttributeBase(UCHHealthSet::GetHealthAttribute(), HealthSet->GetMaxHealth());
	const float health = HealthSet->GetHealth();

	OnHealthChanged.Broadcast(this, health, health, nullptr);
	OnMaxHealthChanged.Broadcast(this, health, health, nullptr);
}

void UCHHealthComponent::UninitializeFromAbilitySystem()
{
	if (HealthSet != nullptr)
	{
		UCHHealthSet* mutableHealthSet = const_cast<UCHHealthSet*>(HealthSet.Get());

		mutableHealthSet->OnHealthChanged.RemoveAll(this);
		mutableHealthSet->OnMaxHealthChanged.RemoveAll(this);
		mutableHealthSet->OnOutOfHealth.RemoveAll(this);
	}

	HealthSet = nullptr;
	AbilitySystemComponent = nullptr;
}

float UCHHealthComponent::GetHealth() const
{
	return (HealthSet != nullptr) ? (HealthSet->GetHealth()) : 0.0f;
}

float UCHHealthComponent::GetMaxHealth() const
{
	return (HealthSet != nullptr) ? (HealthSet->GetMaxHealth()) : 0.0f;
}

float UCHHealthComponent::GetHealthNormalized() const
{
	if (HealthSet == nullptr)
	{
		return 0.0f;
	}

	const float health = HealthSet->GetHealth();
	const float maxHealth = HealthSet->GetMaxHealth();

	return (maxHealth > 0.0f) ? (health / maxHealth) : 0.0f;

}

void UCHHealthComponent::OnUnregister()
{
	UninitializeFromAbilitySystem();

	Super::OnUnregister();
}

void UCHHealthComponent::HandleHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue)
{
	OnHealthChanged.Broadcast(this, OldValue, NewValue, DamageInstigator);
}
void UCHHealthComponent::HandleMaxHealthChanged(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue)
{
	OnMaxHealthChanged.Broadcast(this, OldValue, NewValue, DamageInstigator);
}
void UCHHealthComponent::HandleOutOfHealth(AActor* DamageInstigator, AActor* DamageCauser, const FGameplayEffectSpec* DamageEffectSpec, float DamageMagnitude, float OldValue, float NewValue)
{
	
}
