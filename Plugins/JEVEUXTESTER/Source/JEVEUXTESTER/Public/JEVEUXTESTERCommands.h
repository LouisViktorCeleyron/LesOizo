// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "JEVEUXTESTERStyle.h"

class FJEVEUXTESTERCommands : public TCommands<FJEVEUXTESTERCommands>
{
public:

	FJEVEUXTESTERCommands()
		: TCommands<FJEVEUXTESTERCommands>(TEXT("JEVEUXTESTER"), NSLOCTEXT("Contexts", "JEVEUXTESTER", "JEVEUXTESTER Plugin"), NAME_None, FJEVEUXTESTERStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};