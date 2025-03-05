// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeHackerPawnExtensionComponent.h"
#include "AbilitySystemComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CodeHackerPawnExtensionComponent)

// Sets default values for this component's properties
UCodeHackerPawnExtensionComponent::UCodeHackerPawnExtensionComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, AbilitySystemComponent(nullptr)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;

	
}


// Called when the game starts
void UCodeHackerPawnExtensionComponent::BeginPlay()
{
	Super::BeginPlay();

	const APawn* pawn = GetPawn<APawn>();
	
}

UAbilitySystemComponent* UCodeHackerPawnExtensionComponent::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UCodeHackerPawnExtensionComponent* UCodeHackerPawnExtensionComponent::FindPawnExtensionComponent(const AActor* Actor)
{
	return (Actor != nullptr) ? (Actor->FindComponentByClass<UCodeHackerPawnExtensionComponent>()) : nullptr;
}

void UCodeHackerPawnExtensionComponent::InitializeAbilitySystem(UAbilitySystemComponent* InASC, AActor* InOwnerActor)
{
	check(InASC != nullptr);
	check(InOwnerActor != nullptr);

	if (AbilitySystemComponent == InASC)
	{
		return;
	}

	if (AbilitySystemComponent != nullptr)
	{
		UninitializeAbilitySystem();
	}

	APawn* newAvatarPawn = GetPawnChecked<APawn>();
	AActor* prevAvatar = InASC->GetAvatarActor();

	// 前に入ってたアバターがこのコンポーネントを持っていると終了処理する
	if ((prevAvatar != nullptr) && (prevAvatar != newAvatarPawn))
	{
		UCodeHackerPawnExtensionComponent* prevAvatarPawnExtComp = FindPawnExtensionComponent(prevAvatar);
		if (prevAvatarPawnExtComp != nullptr)
		{
			prevAvatarPawnExtComp->UninitializeAbilitySystem();
		}
	}

	AbilitySystemComponent = InASC;
	AbilitySystemComponent->InitAbilityActorInfo(InOwnerActor, newAvatarPawn);

}

void UCodeHackerPawnExtensionComponent::UninitializeAbilitySystem()
{
	
}

void UCodeHackerPawnExtensionComponent::HandleControllerChanged()
{
	if (AbilitySystemComponent != nullptr)
	{
		AbilitySystemComponent->RefreshAbilityActorInfo();
	}
}

