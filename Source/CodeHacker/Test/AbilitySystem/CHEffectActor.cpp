// Fill out your copyright notice in the Description page of Project Settings.


#include "CHEffectActor.h"

#include "GameFramework/Pawn.h"
#include "Components/SphereComponent.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/Attributes/CHHealthSet.h"

#include "Player/CHPlayerState.h"

// Sets default values
ACHEffectActor::ACHEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACHEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);
	
}

// Called every frame
void ACHEffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACHEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (const APawn* pawn = Cast<APawn>(OtherActor))
	{
		if (const APlayerController* playerController = Cast<APlayerController>(pawn->GetController()))
		{
			if (const ACHPlayerState* playerState = Cast<ACHPlayerState>(playerController->GetPlayerState<ACHPlayerState>()))
			{
				if (const IAbilitySystemInterface* ASInterface = Cast<IAbilitySystemInterface>(playerState))
				{
					const UCHHealthSet* attributeSet = Cast<UCHHealthSet>(ASInterface->GetAbilitySystemComponent()->GetAttributeSet(UCHHealthSet::StaticClass()));

					UCHHealthSet* mutableHealthSet = const_cast<UCHHealthSet*>(attributeSet);

					if (mutableHealthSet)
					{
						mutableHealthSet->SetHealth(attributeSet->GetHealth() + 100.0f);
					}

					Destroy();
				}	
			}
		}
	}
}

void ACHEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
