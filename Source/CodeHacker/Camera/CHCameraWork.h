// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"

#include "CHCameraWork.generated.h"

class UCHCameraComponent;

UENUM(BlueprintType)
enum class ECHCameraWorkBlendFunction : uint8
{
	// リニア
	Linear,

	// イーズイン
	EaseIn,

	// イーズアウト
	EaseOut,

	// イーズインアウト
	EaseInOut,

	Count UMETA(Hidden),
};

//---Begin of FCHCameraWorkView Declaration
#pragma region FCHCameraWorkView Declaration
struct FCHCameraWorkView
{

	FCHCameraWorkView();
	void Blend(const FCHCameraWorkView& OtherView, float OtherWeight);

	FVector Location;
	FRotator Rotation;
	float FieldOfView;

};
#pragma endregion FCHCameraWorkView Declaration
//---End of FCHCameraWorkView Declaration

UCLASS(Abstract, NotBlueprintable)
class CODEHACKER_API UCHCameraWork : public UObject
{
	GENERATED_BODY()

public:
	UCHCameraWork(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	//---Begin of UObject Interface
	virtual UWorld* GetWorld() const override;
	//---End of UObject Interface

	virtual void OnActivated();
	virtual void OnDeactivated();

	void TickCameraWork(float DeltaTime);
	void SetBlendWeight(float Weight);

	AActor* GetTargetActor() const;
	UCHCameraComponent* GetCHCameraComponent() const;
	const FCHCameraWorkView& GetCameraWorkView() const;
	float GetBlendTime() const;
	float GetBlendWeight() const;
	FGameplayTag GetCameraWorkTypeTag() const;

#if WITH_EDITOR
	virtual void DrawDebug(UCanvas* Canvas) const;
#endif

protected:
	virtual FVector GetPivotLocation() const;
	virtual FRotator GetPivotRotation() const;

	virtual void TickView(float DeltaTime);
	virtual void TickBlending(float DeltaTime);

protected:

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|CameraWork|Blending")
	FGameplayTag CameraWorkTypeTag;

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|CameraWork|Blending")
	float BlendTime;

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|CameraWork|Blending")
	float BlendExponent;

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|CameraWork|Blending")
	ECHCameraWorkBlendFunction BlendFunc;

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|CameraWork|View", meta = (UIMin = "5.0", UIMax = "170.0", ClampMin = "5.0", ClampMax = "170.0"))
	float FieldOfView;

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|CameraWork|View", meta = (UIMin = "-90.0", UIMax = "90.0", ClampMin = "-90.0", ClampMax = "90.0"))
	float ViewPitchMin;

	UPROPERTY(EditDefaultsOnly, Category = "CodeHacker|CameraWork|View", meta = (UIMin = "-90.0", UIMax = "90.0", ClampMin = "-90.0", ClampMax = "90.0"))
	float ViewPitchMax;

protected:
	FCHCameraWorkView m_view;
	float m_blendAlpha;
	float m_blendWeight;

protected:
	UPROPERTY(Transient)
	uint8 m_bResetInterpolation : 1;

};








UCLASS()
class UCHCameraWorkStack : public UObject
{
	GENERATED_BODY()

public:
	UCHCameraWorkStack(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	void ActivateStack();
	void DeactivateStack();

	void PushCameraWork(TSubclassOf<UCHCameraWork> CameraWorkClass);
	bool EValuateStack(float DeltaTime, FCHCameraWorkView& OutView);

	void GetBlendInfo(float& OutWeightOfTopLayer, FGameplayTag& OutTagOfTopLayer) const;

#if WITH_EDITOR
	void DrawDebug(UCanvas* canvas) const;
#endif

protected:
	void TickStack(float DeltaTime);
	void BlendStack(FCHCameraWorkView& OutView) const;
	UCHCameraWork* GetCameraWorkInstance(TSubclassOf<UCHCameraWork> CameraWorkClass) const;

protected:
	UPROPERTY()
	TArray<TObjectPtr<UCHCameraWork>> CameraWorkInstances;

	UPROPERTY()
	TArray<TObjectPtr<UCHCameraWork>> CameraWorkStack;

protected:
	uint8 m_bIsActive : 1;
};
