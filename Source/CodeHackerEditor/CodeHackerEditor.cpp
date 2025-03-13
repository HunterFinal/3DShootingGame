
#include "CodeHackerEditor.h"

#include "DetailsCustomize/GATagsPropertiesDetails.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_GAME_MODULE(FCodeHackerEditorModule, CodeHackerEditor);

DEFINE_LOG_CATEGORY(LogCHEditor);


namespace CHEditorModule::Private
{
  const static FName PROPERTY_EDITOR("PropertyEditor");
}

void FCodeHackerEditorModule::StartupModule()
{
  RegisterPropertyTypeCustomizations();
  RegisterObjectCustomizations();

  using namespace CHEditorModule::Private;
  FPropertyEditorModule& propertyModel = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PROPERTY_EDITOR);

  propertyModel.NotifyCustomizationModuleChanged();
}

void FCodeHackerEditorModule::ShutdownModule()
{
  UnregisterLayouts();
}

void FCodeHackerEditorModule::RegisterPropertyTypeCustomizations()
{

}

void FCodeHackerEditorModule::RegisterObjectCustomizations()
{
  RegisterCustomClassLayout("CHGameplayAbility", FOnGetDetailCustomizationInstance::CreateStatic(&FGATagsPropertiesDetails::MakeInstance));
}

void FCodeHackerEditorModule::RegisterCustomClassLayout(FName ClassName, FOnGetDetailCustomizationInstance DetailLayoutDelegate)
{
  check(ClassName != NAME_None);

  m_registeredClassName.Add(ClassName);

  using namespace CHEditorModule::Private;
  FPropertyEditorModule& propertyModel = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PROPERTY_EDITOR);

  propertyModel.RegisterCustomClassLayout(ClassName, DetailLayoutDelegate);
}

void FCodeHackerEditorModule::RegisterCustomPropertyTypeLayout(FName PropertyTypeName, FOnGetPropertyTypeCustomizationInstance PropertyTypeLayoutDelegate)
{
  check(PropertyTypeName != NAME_None);

  m_registeredPropertyTypes.Add(PropertyTypeName);

  using namespace CHEditorModule::Private;
  FPropertyEditorModule& propertyModel = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PROPERTY_EDITOR);

  propertyModel.RegisterCustomPropertyTypeLayout(PropertyTypeName, PropertyTypeLayoutDelegate);
}

void FCodeHackerEditorModule::UnregisterLayouts()
{
  using namespace CHEditorModule::Private;
  if (FModuleManager::Get().IsModuleLoaded(PROPERTY_EDITOR))
  {
    FPropertyEditorModule& propertyModel = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PROPERTY_EDITOR);

    // Unregister all classes customized by name
    // クラスのDetailPanelなどを解読
    {
      for (auto It = m_registeredClassName.CreateConstIterator(); It; ++It)
      {
        if (It->IsValid())
        {
          propertyModel.UnregisterCustomClassLayout(*It);
        }
      }
    }

    // Unregister all structures
    // プロパティの解読
    for (auto It = m_registeredPropertyTypes.CreateConstIterator(); It; ++It)
    {
      if (It->IsValid())
      {
        propertyModel.UnregisterCustomPropertyTypeLayout(*It);
      }
    }

    propertyModel.NotifyCustomizationModuleChanged();
  }
}


#define LOCTEXT_NAMESPACE "FCodeHackerEditorModule"

#undef LOCTEXT_NAMESPACE