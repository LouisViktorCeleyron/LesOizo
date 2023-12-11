// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "JEVEUXTESTER.h"
#include "JEVEUXTESTERStyle.h"
#include "JEVEUXTESTERCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

static const FName JEVEUXTESTERTabName("JEVEUXTESTER");

#define LOCTEXT_NAMESPACE "FJEVEUXTESTERModule"

void FJEVEUXTESTERModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FJEVEUXTESTERStyle::Initialize();
	FJEVEUXTESTERStyle::ReloadTextures();

	FJEVEUXTESTERCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FJEVEUXTESTERCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FJEVEUXTESTERModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FJEVEUXTESTERModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FJEVEUXTESTERModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(JEVEUXTESTERTabName, FOnSpawnTab::CreateRaw(this, &FJEVEUXTESTERModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FJEVEUXTESTERTabTitle", "JEVEUXTESTER"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FJEVEUXTESTERModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FJEVEUXTESTERStyle::Shutdown();

	FJEVEUXTESTERCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(JEVEUXTESTERTabName);
}

TSharedRef<SDockTab> FJEVEUXTESTERModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FJEVEUXTESTERModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("JEVEUXTESTER.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FJEVEUXTESTERModule::PluginButtonClicked()
{
	/*FGlobalTabmanager::Get()->InvokeTab(JEVEUXTESTERTabName);*/
}

void FJEVEUXTESTERModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FJEVEUXTESTERCommands::Get().OpenPluginWindow);
}

void FJEVEUXTESTERModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FJEVEUXTESTERCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FJEVEUXTESTERModule, JEVEUXTESTER)