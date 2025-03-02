// Fill out your copyright notice in the Description page of Project Settings.


#include "CHCameraWork.h"

#include "CHCameraComponent.h"
#include "CHPlayerCameraManager.h"
#include "GameFramework/Character.h"
#include "Engine/Canvas.h"
#include "Components/CapsuleComponent.h"

#if WITH_EDITOR
#include "Engine/Canvas.h"
#endif

#include UE_INLINE_GENERATED_CPP_BY_NAME(CHCameraWork)

//---Begin of FCHCameraWorkView Definition
#pragma region FCHCameraWorkView Definition

FCHCameraWorkView::FCHCameraWorkView()
  : Location(ForceInitToZero)
  , Rotation(ForceInitToZero)
  , FieldOfView(CameraDefault::CH_CAMERA_DEFAULT_POV)
{
}

void FCHCameraWorkView::Blend(const FCHCameraWorkView& OtherView, float OtherWeight)
{
  if (OtherWeight <= 0.0f)
  {
    return;
  }
  else if (OtherWeight >= 1.0f)
  {
    *this = OtherView;
    return;
  }

  Location = FMath::Lerp(Location, OtherView.Location, OtherWeight);

  const FRotator deltaRotation = (OtherView.Rotation - Rotation).GetNormalized();
  Rotation += OtherWeight *deltaRotation;

  FieldOfView = FMath::Lerp(FieldOfView, OtherView.FieldOfView, OtherWeight);
}

#pragma endregion FCHCameraWorkView Definition
//---End of FCHCameraWorkView Definition

//---Begin of UCHCameraWork Definition
#pragma region UCHCameraWork Definition

UCHCameraWork::UCHCameraWork(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
{
  FieldOfView = CameraDefault::CH_CAMERA_DEFAULT_POV;
  ViewPitchMin = CameraDefault::CH_CAMERA_DEFAULT_PITCH_MIN;
  ViewPitchMax = CameraDefault::CH_CAMERA_DEFAULT_PITCH_MAX;

  BlendTime = 0.5f;
  BlendFunc = ECHCameraWorkBlendFunction::Linear;
  BlendExponent = 4.0f;

  m_blendAlpha = 1.0f;
  m_blendWeight = 1.0f;
}

UWorld* UCHCameraWork::GetWorld() const
{
  return HasAnyFlags(RF_ClassDefaultObject) ? nullptr : GetOuter()->GetWorld();
}

void UCHCameraWork::OnActivated()
{
}

void UCHCameraWork::OnDeactivated()
{
}

void UCHCameraWork::TickCameraWork(float DeltaTime)
{
  TickView(DeltaTime);
  TickBlending(DeltaTime);
}

// TODO
// Need more research
void UCHCameraWork::SetBlendWeight(float Weight)
{
  m_blendWeight = FMath::Clamp(Weight, 0.0f, 1.0f);

  // ウェイトを直接設定したため、アルファブレンドをブレンドタイプに基づいて計算し直す
  const float InverseExponent = (BlendExponent > 0.0f) ? (1.0 / BlendExponent) : 1.0f;

  switch(BlendFunc)
  {
    case ECHCameraWorkBlendFunction::Linear:
    {
      m_blendAlpha = m_blendWeight;
    }
    break;

    case ECHCameraWorkBlendFunction::EaseIn:
    {
      m_blendAlpha = FMath::InterpEaseIn(0.0f, 1.0f, m_blendWeight, InverseExponent);
    }
    break;

    case ECHCameraWorkBlendFunction::EaseOut:
    {
      m_blendAlpha = FMath::InterpEaseOut(0.0f, 1.0f, m_blendWeight, InverseExponent);
    }
    break;

    case ECHCameraWorkBlendFunction::EaseInOut:
    {
      m_blendAlpha = FMath::InterpEaseInOut(0.0f, 1.0f, m_blendWeight, InverseExponent);
    }
    break;

    default:
    {
      checkf(false, TEXT("[%s]::SetBlendWeight(): Invalid BlendFunction [%d]\n "), *GetNameSafe(this), StaticCast<uint8>(BlendFunc)); 
    }
    break;
  }
}

AActor* UCHCameraWork::GetTargetActor() const
{
  const UCHCameraComponent* chCameraComponent = GetCHCameraComponent();

  return chCameraComponent->GetTargetActor();
}

// WARNING
// Must set Outer TO UCHCameraComponent;
UCHCameraComponent* UCHCameraWork::GetCHCameraComponent() const
{
  return CastChecked<UCHCameraComponent>(GetOuter());
}

const FCHCameraWorkView& UCHCameraWork::GetCameraWorkView() const
{
  return m_view;
}

float UCHCameraWork::GetBlendTime() const
{
  return BlendTime;
}

float UCHCameraWork::GetBlendWeight() const
{
  return m_blendWeight;
}

FGameplayTag UCHCameraWork::GetCameraWorkTypeTag() const
{
  return CameraWorkTypeTag;
}

FVector UCHCameraWork::GetPivotLocation() const
{
  const AActor* targetActor = GetTargetActor();
  check(targetActor != nullptr);

  const APawn* targetPawn = Cast<APawn>(targetActor);

  if (targetPawn == nullptr)
  {
    return targetActor->GetActorLocation();
  }

  const ACharacter* targetCharacter = Cast<ACharacter>(targetPawn);

  if (targetCharacter == nullptr)
  {
    return targetPawn->GetPawnViewLocation();
  }

  // ACharacterだったらBaseEyeHeightとカプセルコンポネントの縮み具合（ダック状態）で位置を計算して返す
  const ACharacter* targetCharacterCDO = targetCharacter->GetClass()->GetDefaultObject<ACharacter>();
  check(targetCharacterCDO != nullptr);

  const UCapsuleComponent* targetCapsuleComp = targetCharacter->GetCapsuleComponent();
  check(targetCapsuleComp != nullptr);

  const UCapsuleComponent* targetCapsuleCompCDO = targetCharacterCDO->GetCapsuleComponent();
  check(targetCapsuleCompCDO != nullptr);

  const float defaultHalfHeight = targetCapsuleCompCDO->GetUnscaledCapsuleHalfHeight();
  const float actualHalfHeight = targetCapsuleComp->GetUnscaledCapsuleHalfHeight();
  const float heightAdjustment = (defaultHalfHeight - actualHalfHeight) + targetCharacterCDO->BaseEyeHeight;

  return targetCharacter->GetActorLocation() + (FVector::UpVector * heightAdjustment);

}

FRotator UCHCameraWork::GetPivotRotation() const
{
  const AActor* targetActor = GetTargetActor();
  check(targetActor != nullptr);

  const APawn* targetPawn = Cast<APawn>(targetActor);
  if (targetPawn == nullptr)
  {
    return targetActor->GetActorRotation();
  }

  return targetPawn->GetViewRotation();
}

void UCHCameraWork::TickView(float DeltaTime)
{
  FVector pivotLocation = GetPivotLocation();
  FRotator pivotRotation = GetPivotRotation();

  pivotRotation.Pitch = FMath::ClampAngle(pivotRotation.Pitch, ViewPitchMin, ViewPitchMax);

  m_view.Location = pivotLocation;
  m_view.Rotation = pivotRotation;
  m_view.FieldOfView = FieldOfView;

}

void UCHCameraWork::TickBlending(float DeltaTime)
{
  if (BlendTime > 0.0f)
  {
    m_blendAlpha += (DeltaTime / BlendTime);
    m_blendAlpha = FMath::Clamp(m_blendAlpha, 0.0f, 1.0f);
  }
  else
  {
    m_blendAlpha = 1.0f;
  }

  const float exponent = (BlendExponent > 0.0f) ? BlendExponent : 1.0f;

  switch (BlendFunc)
  {
    case ECHCameraWorkBlendFunction::Linear:
    {
      m_blendWeight = m_blendAlpha;
    }
    break;

    case ECHCameraWorkBlendFunction::EaseIn:
    {
      m_blendWeight = FMath::InterpEaseIn(0.0f, 1.0f, m_blendAlpha, exponent);
    } 
    break;

    case ECHCameraWorkBlendFunction::EaseOut:
    {
      m_blendWeight = FMath::InterpEaseOut(0.0f, 1.0f, m_blendAlpha, exponent);
    } 
    break;

    case ECHCameraWorkBlendFunction::EaseInOut:
    {
      m_blendWeight = FMath::InterpEaseInOut(0.0f, 1.0f, m_blendAlpha, exponent);
    } 
    break;

    default:
    {
      checkf(false, TEXT("[%s]::TickBlending(): Invalid BlendFunction [%d]\n "), *GetNameSafe(this), StaticCast<uint8>(BlendFunc));
    }
    break;
  }
}

#if WITH_EDITOR
void UCHCameraWork::DrawDebug(UCanvas* Canvas) const
{
  check(Canvas != nullptr);

  FDisplayDebugManager& displayDebugMgr = Canvas->DisplayDebugManager;

  displayDebugMgr.SetDrawColor(FColor::White);
  displayDebugMgr.DrawString(FString::Printf(TEXT("     CHCameraWork: %s (%f)"), *GetNameSafe(this), m_blendWeight));
}
#endif

#pragma endregion UCHCameraWork Definition
//---End of UCHCameraWork Definition


//---Begin of UCHCameraWorkStack Definition
#pragma region UCHCameraWorkStack Definition

UCHCameraWorkStack::UCHCameraWorkStack(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer)
  , CameraWorkInstances{}
  , CameraWorkStack{}
  , m_bIsActive(true)
{
}

void UCHCameraWorkStack::ActivateStack()
{
  if (!m_bIsActive)
  {
    m_bIsActive = true;

    // カメラワークオブジェクトに有効化通知を送る
    for (UCHCameraWork* cameraWork : CameraWorkStack)
    {
      check(cameraWork);
      cameraWork->OnActivated();
    }
  }
}

void UCHCameraWorkStack::DeactivateStack()
{
  if (m_bIsActive)
  {
    m_bIsActive = false;

    // カメラワークオブジェクトに無効化通知を送る
    for (UCHCameraWork* cameraWork : CameraWorkStack)
    {
      check(cameraWork);
      cameraWork->OnDeactivated();
    }
  }
}

void UCHCameraWorkStack::PushCameraWork(TSubclassOf<UCHCameraWork> CameraWorkClass)
{
  if (CameraWorkClass == nullptr)
  {
    return;
  }

  UCHCameraWork* cameraWork = GetCameraWorkInstance(CameraWorkClass);
  check(cameraWork);


}

bool UCHCameraWorkStack::EValuateStack(float DeltaTime, FCHCameraWorkView& OutView)
{
  return false;
}

void UCHCameraWorkStack::GetBlendInfo(float& OutWeightOfTopLayer, FGameplayTag& OutTagOfTopLayer) const
{

}

#if WITH_EDITOR
void UCHCameraWorkStack::DrawDebug(UCanvas* canvas) const
{

}
#endif

void UCHCameraWorkStack::TickStack(float DeltaTime)
{

}
void UCHCameraWorkStack::BlendStack(FCHCameraWorkView& OutView) const
{

}
UCHCameraWork* UCHCameraWorkStack::GetCameraWorkInstance(TSubclassOf<UCHCameraWork> CameraWorkClass) const
{
  return nullptr;
}


#pragma endregion UCHCameraWorkStack Definition
//---End of UCHCameraWorkStack Definition