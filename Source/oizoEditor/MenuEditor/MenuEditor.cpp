#include "MenuEditor.h"
#include "OizoEditor/IOizoEditorModule.h"
#include "oizoEditor.h"
#define LOCTEXT_NAMESPACE "MenuTool"

class MenuEditorComands : public TCommands<MenuEditorComands>
{
public:

    MenuEditorComands()
        : TCommands<MenuEditorComands>(
            TEXT("MenuTool"), // Context name for fast lookup
            FText::FromString("Example Menu tool"), // Context name for displaying
            NAME_None,   // No parent context
            FEditorStyle::GetStyleSetName() // Icon Style Set
            )
    {
    }

    virtual void RegisterCommands() override
    {
        UI_COMMAND(MenuCommand1, "Open Editor", "Open the Dialogue Editor.", EUserInterfaceActionType::Button, FInputGesture());

    }

public:
    TSharedPtr<FUICommandInfo> MenuCommand1;
};

void MenuEditor::MapCommands()
{
    const auto& Commands = MenuEditorComands::Get();

    CommandList->MapAction(
        Commands.MenuCommand1,
        FExecuteAction::CreateSP(this, &MenuEditor::MenuCommand1),
        FCanExecuteAction());
}

void MenuEditor::OnStartupModule()
{
    CommandList = MakeShareable(new FUICommandList);
    MenuEditorComands::Register();
    MapCommands();
    FoizoEditor::Get().AddMenuExtension(
        FMenuExtensionDelegate::CreateRaw(this, &MenuEditor::MakeMenuEntry),
        FName("Section_1"),
        CommandList);
}

void MenuEditor::OnShutdownModule()
{
    MenuEditorComands::Unregister();
}

void MenuEditor::MakeMenuEntry(FMenuBuilder& menuBuilder)
{
    menuBuilder.AddMenuEntry(MenuEditorComands::Get().MenuCommand1);
}

void MenuEditor::MenuCommand1()
{
    UE_LOG(LogClass, Log, TEXT("clicked MenuCommand1"));
}

#undef LOCTEXT_NAMESPACE