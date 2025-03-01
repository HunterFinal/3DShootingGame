// Fill out your copyright notice in the Description page of Project Settings.
/*

CodeHackerGameplayTags.cpp

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
#include "CodeHackerGameplayTags.h"

#include "GameplayTagsManager.h"

namespace CodeHackerGameplayTags
{
//---Code Hacker Gameplay Tags Definition
#pragma region Code Hacker Gameplay Tags Definition

  //---Action
  #pragma region Action
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_Idle, "CHAbility.Action.Idle", "待機");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_Walk, "CHAbility.Action.Walk", "歩く");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_Run, "CHAbility.Action.Run", "走る");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_Dash, "CHAbility.Action.Dash", "ダッシュ");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_BackDash, "CHAbility.Action.BackDash", "バックダッシュ");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_Crouch, "CHAbility.Action.Crouch", "しゃがむ");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_Slide, "CHAbility.Action.Slide", "滑走");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_Jump, "CHAbility.Action.Jump", "ジャンプ");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_Melee, "CHAbility.Action.Melee", "近接攻撃");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_SpecialMove, "CHAbility.Action.SpecialMove", "必殺技");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_Dead, "CHAbility.Action.Dead", "死亡");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Action_Look, "CHAbility.Action.Look", "カメラ");
  #pragma endregion Action
  //---End of Action

  //---Shooting
  #pragma region Shooting
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Shooting_HipFire, "CHAbility.Shooting.Hipfire", "撃つ");            
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Shooting_Aim, "CHAbility.Shooting.Aim", "照準");                 
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Shooting_AimedFire, "CHAbility.Shooting.AimedFire", "照準して撃つ");       
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_Shooting_SecialMoveFire, "CHAbility.Shooting.SpecialMoveFire", "必殺技撃つ");
  #pragma endregion Shooting
  //---End of Shooting
#pragma endregion Code Hacker Gameplay Tags Definition
//---End of Code Hacker Gameplay Tags Definition

  FGameplayTag FindTagByString(const FString& tagString, bool bMatchPartialString)
  {
    const UGameplayTagsManager& manager = UGameplayTagsManager::Get();
    FGameplayTag resultTag = manager.RequestGameplayTag(FName(*tagString), /*ErrorIfNotFound*/ false);

    if (!resultTag.IsValid() && bMatchPartialString)
    {
      FGameplayTagContainer allTags;
      manager.RequestAllGameplayTags(allTags, true);

      for (const FGameplayTag& tag : allTags)
      {
        if (tag.ToString().Contains(tagString))
        {
          resultTag = tag;
          break;
        }
      }
    }
    
    return resultTag;
  }
}
