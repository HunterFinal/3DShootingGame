// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IDetailCustomization.h"

class FGATagsPropertiesDetails : public IDetailCustomization
{
  public:

    FGATagsPropertiesDetails();
    virtual ~FGATagsPropertiesDetails();

    // レイアウト拡張処理
    virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

    // モジュール登録時に必要
    static TSharedRef<IDetailCustomization> MakeInstance();

  private:

    // Test Function
    FReply OnClicked();

    // 親GameplayAbilityのタグを隠す
    void HideParentTagProperties(IDetailLayoutBuilder& DetailBuilder);
    
};
