// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "JEVEUXTESTERCommands.h"

#define LOCTEXT_NAMESPACE "FJEVEUXTESTERModule"

void FJEVEUXTESTERCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "JEVEUXTESTER", "Bring up JEVEUXTESTER window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
