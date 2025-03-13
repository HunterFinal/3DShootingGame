
#pragma once

#include "Modules/ModuleInterface.h"
#include "Containers/Set.h"
#include "Logging/LogMacros.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCHEditor, Log, All);

class CODEHACKEREDITOR_API FCodeHackerEditorModule : public IModuleInterface
{
  public:

    //---Begin of IModuleInterface
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
    //---End of IModuleInterface

  private:

    void RegisterPropertyTypeCustomizations();
    void RegisterObjectCustomizations();

    void RegisterCustomClassLayout(FName ClassName, FOnGetDetailCustomizationInstance DetailLayoutDelegate);
    void RegisterCustomPropertyTypeLayout(FName PropertyTypeName, FOnGetPropertyTypeCustomizationInstance PropertyTypeLayoutDelegate);

    void UnregisterLayouts();

  private:

    TSet<FName> m_registeredClassName;
    TSet<FName> m_registeredPropertyTypes;
};
