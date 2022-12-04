#include "oizoEditor.h"
#include "oizoEditor/MenuEditor/MenuEditor.h"
#include "oizoEditor/Tabs/TabTool.h"
#include "IOizoEditorModule.h"

IMPLEMENT_GAME_MODULE(FoizoEditor, oizoEditor)

void FoizoEditor::AddModuleListeners()
{
    // add tools later
    ModuleListeners.Add(MakeShareable(new MenuEditor));
    ModuleListeners.Add(MakeShareable(new TabTool));
}

void FoizoEditor::StartupModule()
{
    if (!IsRunningCommandlet())
    {
        FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
        LevelEditorMenuExtensibilityManager = LevelEditorModule.GetMenuExtensibilityManager();
        MenuExtender = MakeShareable(new FExtender);
        MenuExtender->AddMenuBarExtension("Window", EExtensionHook::Before, NULL, FMenuBarExtensionDelegate::CreateRaw(this, &FoizoEditor::MakePulldownMenu));
        LevelEditorMenuExtensibilityManager->AddExtender(MenuExtender);
        DialogueAssetAction = MakeShared<FDailogueAssetAction>();
        FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(DialogueAssetAction.ToSharedRef());
    }
    IExampleModuleInterface::StartupModule();
}


void FoizoEditor::ShutdownModule()
{
    if (!FModuleManager::Get().IsModuleLoaded("oizoEditor")) return;
    FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(DialogueAssetAction.ToSharedRef());
    IExampleModuleInterface::ShutdownModule();
}

TSharedRef<FWorkspaceItem> FoizoEditor::MenuRoot = FWorkspaceItem::NewGroup(FText::FromString("Menu Root"));


void FoizoEditor::AddMenuExtension(const FMenuExtensionDelegate& extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList>& CommandList, EExtensionHook::Position position)
{
    MenuExtender->AddMenuExtension(extensionHook, position, CommandList, extensionDelegate);
}

void FoizoEditor::MakePulldownMenu(FMenuBarBuilder& menuBuilder)
{
    menuBuilder.AddPullDownMenu(
        FText::FromString("CastleNest"),
        FText::FromString("Open the CastleNest menu"),
        FNewMenuDelegate::CreateRaw(this, &FoizoEditor::FillPulldownMenu),
        "CastleNest",
        FName(TEXT("CastleNest"))
    );
}

void FoizoEditor::FillPulldownMenu(FMenuBuilder& menuBuilder)
{
    // just a frame for tools to fill in
    menuBuilder.BeginSection("ExampleSection", FText::FromString("Dialogue Editor"));
    menuBuilder.AddMenuSeparator(FName("Section_1"));
    menuBuilder.EndSection();
}