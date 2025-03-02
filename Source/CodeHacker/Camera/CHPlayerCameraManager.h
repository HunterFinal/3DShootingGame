// Fill out your copyright notice in the Description page of Project Settings.
/*

CHPlayerCameraManager.h

Author : MAI ZHICONG(バクチソウ)

Description : CodeHackerカメラマネージャー

Update History: 2025/02/27 作成

Version : alpha_1.0.0

Encoding : UTF-8 

*/
#pragma once

#include "Camera/PlayerCameraManager.h"

#include "CHPlayerCameraManager.generated.h"

namespace CameraDefault
{
	constexpr float CH_CAMERA_DEFAULT_POV = 90.0f;
	constexpr float CH_CAMERA_DEFAULT_PITCH_MIN = -90.0f;
	constexpr float CH_CAMERA_DEFAULT_PITCH_MAX = 90.0f;
}
/**
 * 
 */
UCLASS()
class CODEHACKER_API ACHPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
	
};
