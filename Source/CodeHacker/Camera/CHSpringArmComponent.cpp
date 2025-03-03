// Fill out your copyright notice in the Description page of Project Settings.


#include "CHSpringArmComponent.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHSpringArmComponent)

UCHSpringArmComponent::UCHSpringArmComponent(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
  , HitInterpSpeed(0.0f)
  , HitReturnDesiredLocationTime(0.0f)
  , m_curtHitRetusnDesiredLocationTime(0.0f)
  , m_prevHitInterpLocation(ForceInitToZero)
{
}

FVector UCHSpringArmComponent::BlendLocations(const FVector& DesiredArmLocation, const FVector& TraceHitLocation, bool bHitSomething, float DeltaTime)
{
  if (FMath::IsNearlyZero(HitInterpSpeed) || FMath::IsNaN(HitInterpSpeed))
  {
    Super::BlendLocations(DesiredArmLocation, TraceHitLocation, bHitSomething, DeltaTime);
  }

  if (bHitSomething)
  {
    const FVector interp = FMath::VInterpTo(m_prevHitInterpLocation, TraceHitLocation, DeltaTime, HitInterpSpeed);
    m_prevHitInterpLocation = interp;

    // 壁に衝突したため、ReturnTimeをリセット
    m_curtHitRetusnDesiredLocationTime = HitReturnDesiredLocationTime;
    
    return interp;
  }

  if (m_curtHitRetusnDesiredLocationTime > 0.0f)
  {
    m_curtHitRetusnDesiredLocationTime -= DeltaTime;
    m_curtHitRetusnDesiredLocationTime = FMath::Clamp(m_curtHitRetusnDesiredLocationTime, 0.0f, HitReturnDesiredLocationTime);
    const FVector interp = FMath::VInterpTo(m_prevHitInterpLocation, DesiredArmLocation, DeltaTime, HitInterpSpeed);

    m_prevHitInterpLocation = interp;

    return m_prevHitInterpLocation;
  }
  
  m_prevHitInterpLocation = DesiredArmLocation;
  return m_prevHitInterpLocation;

}
