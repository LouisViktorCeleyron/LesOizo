#pragma once
#include "DailogueAssetAction.h"
#include "UnrealEd.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Editor/LevelEditor/Public/LevelEditor.h"
#include "Editor/PropertyEditor/Public/PropertyEditing.h"
#include "IAssetTypeActions.h"
#include "IOizoEditorModule.h"

class FoizoEditor : public IExampleModuleInterface
{
public:
    /** IModuleInterface implementation */
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
        void AddMenuExtension(const FMenuExtensionDelegate& extensionDelegate, FName extensionHook, const TSharedPtr<FUICommandList>& CommandList = NULL, EExtensionHook::Position position = EExtensionHook::Before);
        TSharedRef<FWorkspaceItem> GetMenuRoot() { return MenuRoot; };

    protected:
        TSharedPtr<FExtensibilityManager> LevelEditorMenuExtensibilityManager;
        TSharedPtr<FExtender> MenuExtender;
        TSharedPtr<FDailogueAssetAction> DialogueAssetAction;
        static TSharedRef<FWorkspaceItem> MenuRoot;

        void MakePulldownMenu(FMenuBarBuilder& menuBuilder);
        void FillPulldownMenu(FMenuBuilder& menuBuilder);
};