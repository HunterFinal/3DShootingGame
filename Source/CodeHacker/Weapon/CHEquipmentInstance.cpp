// Fill out your copyright notice in the Description page of Project Settings.
/*

CHEquipmentInstance.h

Author : MAI ZHICONG(バクチソウ)

Description : 装備品実体（親クラス）

Update History: 2025/02/27 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/

#include "CHEquipmentInstance.h"

#include "CHEquipmentDefinition.h"
#include "GameFramework/Character.h"

#include "MLibrary.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME*(CHEquipmentInstance)

UCHEquipmentInstance::UCHEquipmentInstance()
{}

UWorld* UCHEquipmentInstance::GetWorld() const
{
  APawn* owningPawn = GetPawn();

  return GLOBAL_SCOPE::IsValid(owningPawn) ? owningPawn->GetWorld() : nullptr;
}

APawn* UCHEquipmentInstance::GetPawn() const
{
  return Cast<APawn>(GetOuter());
}

APawn* UCHEquipmentInstance::GetTypedPawn(TSubclassOf<APawn> PawnType) const
{
  if (PawnType == nullptr)
  {
    return nullptr;
  }

  return GetOuter()->IsA(*PawnType) ? GetPawn() : nullptr;
}

TArray<AActor*> UCHEquipmentInstance::GetSpawnedAppearances() const
{
  return SpawnedAppearances;
}

void UCHEquipmentInstance::SpawnAppearanceActors(const TArray<FCHEquipmentAppearance>& appearancesToSpawn)
{
  APawn* owningPawn = GetPawn();
  if (!GLOBAL_SCOPE::IsValid(owningPawn))
  {
    return;
  }
  
  USceneComponent* attachTarget = owningPawn->GetRootComponent();

  ACharacter* owningCharacter = Cast<ACharacter>(owningPawn);
  if (GLOBAL_SCOPE::IsValid(owningCharacter))
  {
    attachTarget = owningCharacter->GetMesh();
  }

  for (const FCHEquipmentAppearance& appearanceInfo : appearancesToSpawn)
  {
    // BeginPlayが呼び出される前に処理したい場合や値を渡したい場合はSpawnActorDeferred
    AActor* newAppearance = GetWorld()->SpawnActorDeferred<AActor>(appearanceInfo.AppearanceToSpawn, FTransform::Identity, owningPawn);
    newAppearance->FinishSpawning(FTransform::Identity);
    newAppearance->SetActorRelativeTransform(appearanceInfo.AttachTransform);
    newAppearance->AttachToComponent(attachTarget, FAttachmentTransformRules::KeepRelativeTransform, appearanceInfo.AttachSocketName);

    SpawnedAppearances.Emplace(newAppearance);
  }
}

void UCHEquipmentInstance::DestroyAppearanceActors()
{
  for (AActor* appearance : SpawnedAppearances)
  {
    if (GLOBAL_SCOPE::IsValid(appearance))
    {
      appearance->Destroy();
    }
  }
}

void UCHEquipmentInstance::OnEquipped()
{

}

void UCHEquipmentInstance::OnUnequipped()
{

}
