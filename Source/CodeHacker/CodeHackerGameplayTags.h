// Fill out your copyright notice in the Description page of Project Settings.
/*

CodeHackerGameplayTags.h

Author : MAI ZHICONG(バクチソウ)

Description : CodeHackerに使うGameplay Tags定義

Update History: 2025/03/01 作成

Version : alpha_1.0.0

Encoding : UTF-8 

References : https://dev.epicgames.com/documentation/ja-jp/unreal-engine/using-gameplay-tags-in-unreal-engine
             
             Lyra sample project(Unreal engine):
             {
              LyraStarterGame/Source/LyraGame/LyraGameplayTags.h
              LyraStarterGame/Source/LyraGame/LyraGameplayTags.cpp
             }
*/
#pragma once

#include "NativeGameplayTags.h"

namespace CodeHackerGameplayTags
{
  CODEHACKER_API FGameplayTag FindTagByString(const FString& tagString, bool bMatchPartialString = false);

  // Code Hacker に使うカスタムタグ

  //---Code Hacker Gameplay Tags Declaration
  #pragma region Code Hacker Gameplay Tags Declaration

    //---Action
    #pragma region Action
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_Idle);             // 待機
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_Walk);             // 歩く
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_Run);              // 走る
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_Dash);             // ダッシュ
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_BackDash);         // バックダッシュ
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_Crouch);           // しゃがむ
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_Slide);            // 滑走
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_Jump);             // ジャンプ
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_Melee);            // 近接攻撃
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_SpecialMove);      // 必殺技
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_Dead);             // 死亡
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Action_Look);             // カメラ
    #pragma endregion Action
    //---End of Action

    //---Shooting
    #pragma region Shooting
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Shooting_HipFire);         // 撃つ    
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Shooting_Aim);             // 照準    
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Shooting_AimedFire);       // 照準して撃つ 
    CODEHACKER_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CHAbility_Shooting_SecialMoveFire);  // 必殺技撃つ 
    #pragma endregion Shooting
    //---End of Shooting

  #pragma endregion Code Hacker Gameplay Tags Declaration
  //---End of Code Hacker Gameplay Tags Declaration
}