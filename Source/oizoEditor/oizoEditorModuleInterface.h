#pragma once
#include "ModuleManager.h"

class IoizoEditorModuleListenerInterface
{
public:
	virtual  void OnStartModule();
	virtual  void OnCloseModule();
};


class IoizoEditorModuleInterface : public IModuleInterface
{
public:
	virtual void StartupModule() override
	{
		if(IsRunningCommandlet())
		{
			for (auto moduleListener : ModuleListeners)
			{
				moduleListener->OnStartModule();
			}
		}
	}
	virtual void ShutdownModule() override
	{
		
		for (auto moduleListener : ModuleListeners)
		{
			moduleListener->OnCloseModule();
		}
	}

	virtual void AddModuleListeners(){};

protected:
	TArray<TSharedRef<IoizoEditorModuleListenerInterface>> ModuleListeners;
};
