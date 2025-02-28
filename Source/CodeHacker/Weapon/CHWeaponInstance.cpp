// Fill out your copyright notice in the Description page of Project Settings.


#include "CHWeaponInstance.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHWeaponInstance)

UCHWeaponInstance::UCHWeaponInstance()
  : m_timeLastEquipped(0.0)
  , m_timeLastFired(0.0)
{
}

void UCHWeaponInstance::OnEquipped()
{
  Super::OnEquipped();

  UWorld* world = GetWorld();
  check(world);

  m_timeLastEquipped = world->GetTimeSeconds();
}

void UCHWeaponInstance::OnUnequipped()
{
  Super::OnUnequipped();

}

void UCHWeaponInstance::UpdateFiringTime()
{
  UWorld* world = GetWorld();
  check(world);

  m_timeLastFired = world->GetTimeSeconds();
}

float UCHWeaponInstance::GetTimeSinceLastInteractedWith() const
{
  UWorld* world = GetWorld();
  check(world);

  double resultTime = world->TimeSince(m_timeLastEquipped);

  if (m_timeLastFired > 0.0)
  {
    const double timeSinceFired = world->TimeSince(m_timeLastFired);
    resultTime = FMath::Min(resultTime, timeSinceFired);
  }

  return resultTime;
}

void UCHWeaponInstance::OnDeathStarted(AActor* OwningActor)
{

}


