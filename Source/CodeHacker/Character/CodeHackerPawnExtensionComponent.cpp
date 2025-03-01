// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeHackerPawnExtensionComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CodeHackerPawnExtensionComponent)

// Sets default values for this component's properties
UCodeHackerPawnExtensionComponent::UCodeHackerPawnExtensionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCodeHackerPawnExtensionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCodeHackerPawnExtensionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

