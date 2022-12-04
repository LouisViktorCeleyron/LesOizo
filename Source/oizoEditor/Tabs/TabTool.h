#pragma once

#include "OizoEditor/Tabs/BaseTab.h"

class TabTool : public FBaseTab
{
public:
    virtual ~TabTool() {}
    virtual void OnStartupModule() override;
    virtual void OnShutdownModule() override;
    virtual void Initialize() override;
    virtual TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& TabSpawnArgs) override;
};