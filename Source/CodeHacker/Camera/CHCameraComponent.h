// Fill out your copyright notice in the Description page of Project Settings.
/*

CHCameraComponent.h

Author : MAI ZHICONG(バクチソウ)

Description : CodeHackerカメラコンポネント

Update History: 2025/02/27 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/
#pragma once

#include "Camera/CameraComponent.h"

#include "CHCameraComponent.generated.h"

/**
 * 
 */
UCLASS(Config = Game)
class CODEHACKER_API UCHCameraComponent : public UCameraComponent
{
	GENERATED_BODY()

public:
	UCHCameraComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
public:
	virtual AActor* GetTargetActor() const
	{
		return GetOwner();
	}
};
