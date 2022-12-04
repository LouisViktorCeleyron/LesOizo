#include "TabTool.h"
#include "OizoEditor/oizoEditor.h"
#include "TabToolPanel.h"
#include "OizoEditor/Tabs/BaseTab.h"


void TabTool::OnStartupModule()
{
    FBaseTab::OnStartupModule();
    FoizoEditor::Get().AddMenuExtension(FMenuExtensionDelegate::CreateRaw(this, &TabTool::MakeMenuEntry), FName("Section_1"));
}

void TabTool::OnShutdownModule()
{
    FBaseTab::OnShutdownModule();
}

void TabTool::Initialize()
{
    TabName = "CastlenestDialogueEditor";
    TabDisplayName = FText::FromString("CastlenestDialogueEditor");
    ToolTipText = FText::FromString("CastleNest DialogueEditor");
}

TSharedRef<SDockTab> TabTool::SpawnTab(const FSpawnTabArgs& TabSpawnArgs)
{
    TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)
        .TabRole(ETabRole::NomadTab)
        [
            SNew(TabToolPanel)
            .Tool(SharedThis(this))
        ];

    return SpawnedTab;
}