#pragma once
#include "CoreMinimal.h"
#include "OizoEnumEditor.generated.h"

UENUM(Blueprintable)
enum EDialogueTransitionType
{
	SimpleTransition,
	WithAnswer,
	EndOfDialogue
};
