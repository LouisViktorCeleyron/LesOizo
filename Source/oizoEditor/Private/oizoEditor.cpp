#include "oizoEditor.h"
#include "oizoEditorModuleInterface.h"

IMPLEMENT_GAME_MODULE(FoizoEditor,oizoEditor)
TSharedRef<FWorkspaceItem> FoizoEditor::MenuRoot = FWorkspaceItem::NewGroup(FText::FromString("Menu Root"));


void FoizoEditor::StartupModule()
{
	if (!IsRunningCommandlet())
	{
		FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		LevelEditorMenuExtensibilityManager = LevelEditorModule.GetMenuExtensibilityManager();
		MenuExtender = MakeShareable(new FExtender);
		MenuExtender->AddMenuBarExtension("Window", EExtensionHook::After, NULL, FMenuBarExtensionDelegate::CreateRaw(this, &FoizoEditor::MakePulldownMenu));
		LevelEditorMenuExtensibilityManager->AddExtender(MenuExtender);
	}
	IoizoEditorModuleInterface::StartupModule();
}

void FoizoEditor::ShutdownModule()
{
	IoizoEditorModuleInterface::ShutdownModule();	
}

void FoizoEditor::AddModuleListeners()
{
	
}

void FoizoEditor::AddMenuExtension(const FMenuExtensionDelegate &extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList> &CommandList, EExtensionHook::Position position)
{
	MenuExtender->AddMenuExtension(extensionHook, position, CommandList, extensionDelegate);
}

void FoizoEditor::MakePulldownMenu(FMenuBarBuilder &menuBuilder)
{
	menuBuilder.AddPullDownMenu(
        FText::FromString("Example"),
        FText::FromString("Open the Example menu"),
        FNewMenuDelegate::CreateRaw(this, &FoizoEditor::FillPulldownMenu),
        "Example",
        FName(TEXT("ExampleMenu"))
    );
}

void FoizoEditor::FillPulldownMenu(FMenuBuilder &menuBuilder)
{
	// just a frame for tools to fill in
	menuBuilder.BeginSection("ExampleSection", FText::FromString("Section 1"));
	menuBuilder.AddMenuSeparator(FName("Section_1"));
	menuBuilder.EndSection();

	menuBuilder.BeginSection("ExampleSection", FText::FromString("Section 2"));
	menuBuilder.AddMenuSeparator(FName("Section_2"));
	menuBuilder.EndSection();
}
