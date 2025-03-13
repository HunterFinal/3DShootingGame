// Fill out your copyright notice in the Description page of Project Settings.


#include "GATagsPropertiesDetails.h"

#include "AbilitySystem/Abilities/CHGameplayAbility.h"
#include "CodeHackerEditor.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "Widgets/Layout/SWrapBox.h"
#include "Widgets/Input/SButton.h"

namespace DetailCustomizationPrivate
{
  static const FName TAG_DETAIL_CUSTOM{"Custom Tags"};
}

#define LOCTEXT_NAMESPACE "GATagsPropertiesDetails"

TSharedRef<IDetailCustomization> FGATagsPropertiesDetails::MakeInstance()
{
  return ::MakeShared<FGATagsPropertiesDetails>();
}

FGATagsPropertiesDetails::FGATagsPropertiesDetails()
{
}

FGATagsPropertiesDetails::~FGATagsPropertiesDetails()
{
}

void FGATagsPropertiesDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
  HideParentTagProperties(DetailBuilder);

  // Test Code
  TSharedPtr<SWrapBox> wrapBox = SNew(SWrapBox);
  const FText boxText = FText::FromString(TEXT("○そう！！！"));

  // ボタンを追加
  wrapBox->AddSlot().Padding(0.0f, 0.0f, 10.0f, 6.0f)
  [
    SNew(SButton)
    .Text(boxText)
    .OnClicked(FOnClicked::CreateSP(this, &FGATagsPropertiesDetails::OnClicked))
  ];

  const FText empty = FText::GetEmpty();

  // 新規でボタンを追加するためのカテゴリを編集する
  //（指定したカテゴリがなければ新規追加になり、クラス名を入れると別カテゴリにならず同じカテゴリに追加される）
  using namespace DetailCustomizationPrivate;
  IDetailCategoryBuilder& categoryBuilder = DetailBuilder.EditCategory(TAG_DETAIL_CUSTOM);

  // SearchText必要ないので空
  categoryBuilder.AddCustomRow(empty)
  .RowTag("Empty")
  [
    wrapBox.ToSharedRef()             // 描画インスタンスを渡して
  ];

}

FReply FGATagsPropertiesDetails::OnClicked()
{
  UE_LOG(LogCHEditor, Warning, TEXT("Details On Clicked"));

  return FReply::Handled();
}

void FGATagsPropertiesDetails::HideParentTagProperties(IDetailLayoutBuilder& DetailBuilder)
{
  // Editor上、親クラス(UGameplayAbility)のTagPropertyを隠す
  // FGameplayTagContainer AbilityTags
  {
    TSharedRef<IPropertyHandle> abilityTagsProperty = DetailBuilder.GetProperty(GET_MEMBER_NAME_CHECKED(UGameplayAbility, AbilityTags), UGameplayAbility::StaticClass());
    DetailBuilder.HideProperty(abilityTagsProperty);
  }
  // FGameplayTagContainer CancelAbilitiesWithTag
  {
    TSharedRef<IPropertyHandle> cancelAbilitiesWithTagProperty = DetailBuilder.GetProperty("CancelAbilitiesWithTag", UGameplayAbility::StaticClass());
    DetailBuilder.HideProperty(cancelAbilitiesWithTagProperty);
  }
  // FGameplayTagContainer BlockAbilitiesWithTag
  {
    TSharedRef<IPropertyHandle> blockAbilitiesWithTagProperty = DetailBuilder.GetProperty("BlockAbilitiesWithTag", UGameplayAbility::StaticClass());
    DetailBuilder.HideProperty(blockAbilitiesWithTagProperty);
  }
  // FGameplayTagContainer ActivationOwnedTags
  {
    TSharedRef<IPropertyHandle> activationOwnedTagsProperty = DetailBuilder.GetProperty("ActivationOwnedTags", UGameplayAbility::StaticClass());
    DetailBuilder.HideProperty(activationOwnedTagsProperty);
  }
  // FGameplayTagContainer ActivationRequiredTags
  {
    TSharedRef<IPropertyHandle> activationRequiredTagsProperty = DetailBuilder.GetProperty("ActivationRequiredTags", UGameplayAbility::StaticClass());
    DetailBuilder.HideProperty(activationRequiredTagsProperty);
  }
  // FGameplayTagContainer ActivationBlockedTags
  {
    TSharedRef<IPropertyHandle> activationBlockedTagsProperty = DetailBuilder.GetProperty("ActivationBlockedTags", UGameplayAbility::StaticClass());
    DetailBuilder.HideProperty(activationBlockedTagsProperty);
  }
  // FGameplayTagContainer SourceRequiredTags
  {
    TSharedRef<IPropertyHandle> sourceRequiredTagsProperty = DetailBuilder.GetProperty("SourceRequiredTags", UGameplayAbility::StaticClass());
    DetailBuilder.HideProperty(sourceRequiredTagsProperty);
  }
  // FGameplayTagContainer SourceBlockedTags
  {
    TSharedRef<IPropertyHandle> sourceBlockedTagsProperty = DetailBuilder.GetProperty("SourceBlockedTags", UGameplayAbility::StaticClass());
    DetailBuilder.HideProperty(sourceBlockedTagsProperty);
  }
  // FGameplayTagContainer TargetRequiredTags
  {
    TSharedRef<IPropertyHandle> targetRequiredTagsProperty = DetailBuilder.GetProperty("TargetRequiredTags", UGameplayAbility::StaticClass());
    DetailBuilder.HideProperty(targetRequiredTagsProperty);
  }
  // FGameplayTagContainer TargetBlockedTags
  {
    TSharedRef<IPropertyHandle> targetBlockedTagsProperty = DetailBuilder.GetProperty("TargetBlockedTags", UGameplayAbility::StaticClass());
    DetailBuilder.HideProperty(targetBlockedTagsProperty);
  }

}

#undef LOCKTEXT_NAMESPACE