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

  //---State
  #pragma region State
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_Idle, "CHAbility.State.Idle", "待機");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_InSky, "CHAbility.State.InSky", "空中");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_Moving, "CHAbility.State.Moving", "移動");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_Dying, "CHAbility.State.Dying", "死亡中");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_Dead, "CHAbility.State.Dead", "死亡");
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_Respawning, "CHAbility.State.Respawning", "再生中");          
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_Damaged, "CHAbility.State.Damaged", "ダメージを受けた");              
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_CriticalDamaged, "CHAbility.State.CriticalDamaged", "クリティカルダメージを受けた");      
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_WeakDamaged, "CHAbility.State.WeakDamaged", "弱点ダメージを受けた");         
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_Immune, "CHAbility.State.Immune", "無敵");               
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_Dodge, "CHAbility.State.Immune", "回避");                
  UE_DEFINE_GAMEPLAY_TAG_COMMENT(CHAbility_State_Steady "CHAbility.State.Steady", "不動（ダメージを受ける）");              
  #pragma endregion State
  //---End of State
  
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
