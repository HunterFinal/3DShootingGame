// Fill out your copyright notice in the Description page of Project Settings.
/*

CHCrosshair.h

Author : MAI ZHICONG(バクチソウ)

Description : ガンシューティングクロスヘア

Update History: 2025/02/27 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/
#pragma once

#include "Blueprint/UserWidget.h"
#include "CHCrosshair.generated.h"

class UWidgetAnimation;

/**
 * 
 */
UCLASS(Abstract)
class CODEHACKER_API UCHCrosshair : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	UPROPERTY(Transient, Interp, meta = (BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> CrosshairAnimation;
	UPROPERTY(Transient, Interp, meta = (ClampMin = 0f, ClampMax = 1f))
	float Precision;



};
