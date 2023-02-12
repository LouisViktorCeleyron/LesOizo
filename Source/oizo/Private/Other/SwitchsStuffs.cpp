// Fill out your copyright notice in the Description page of Project Settings.

#include "SwitchsStuffs.h"
#include "ClassicFunctionLibrary.h"

void USwitchsStuffs::ReadSwitch(FString switchID, ETrueFalseEnum& Branches)
{
	if(	UClassicFunctionLibrary::GetCastleNestInstance()->GetSwitchValue(switchID))
	{
		Branches =ETrueFalseEnum::TrueSwitch;
		return;
	}
	else
	{
		Branches =ETrueFalseEnum::FalseSwitch;
		return;
		
	};
}
