#pragma once
#include "OizoEditor/IOizoEditorModule.h"

class MenuEditor : public IExampleModuleListenerInterface, public TSharedFromThis<MenuEditor>
{
public:
    virtual ~MenuEditor() {}

    virtual void OnStartupModule() override;
    virtual void OnShutdownModule() override;

    void MakeMenuEntry(FMenuBuilder& menuBuilder);

protected:
    TSharedPtr<FUICommandList> CommandList;

    void MapCommands();

    // UI Command functions
    void MenuCommand1();
};

