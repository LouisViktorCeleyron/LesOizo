#pragma once
#include "UnrealEd.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Editor/LevelEditor/Public/LevelEditor.h"
#include "Editor/PropertyEditor/Public/PropertyEditing.h"
#include "IAssetTypeActions.h"
#include "oizoEditorModuleInterface.h"

class FoizoEditor : public IoizoEditorModuleInterface
{
	
public: 
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual void AddModuleListeners() override;

	static inline FoizoEditor& Get()
	{
		return FModuleManager::LoadModuleChecked< FoizoEditor >("oizoEditor");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("oizoEditor");
	}


public:
	void AddMenuExtension(const FMenuExtensionDelegate &extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList> &CommandList = NULL, EExtensionHook::Position position = EExtensionHook::Before);
	TSharedRef<FWorkspaceItem> GetMenuRoot() { return MenuRoot; };
	TArray<TSharedRef<IAssetTypeActions>> CreatedAssetTypeActions;

protected:
	TSharedPtr<FExtensibilityManager> LevelEditorMenuExtensibilityManager;
	TSharedPtr<FExtender> MenuExtender;

	static TSharedRef<FWorkspaceItem> MenuRoot;

	void MakePulldownMenu(FMenuBarBuilder &menuBuilder);
	void FillPulldownMenu(FMenuBuilder &menuBuilder);

	

	

};
