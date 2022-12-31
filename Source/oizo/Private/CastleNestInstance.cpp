// Fill out your copyright notice in the Description page of Project Settings.


#include "CastleNestInstance.h"

void UCastleNestInstance::AppendPlayerName(FString stringToAdd)
{
	PlayerName.Append(stringToAdd);
}

void UCastleNestInstance::RemoveLastLetterOfPlayerName()
{
	if(PlayerName.Len()>=1)
	{
		PlayerName.RemoveAt(PlayerName.Len()-1);
	}
}

bool UCastleNestInstance::GetSwitchValue(FString ID)
{
	return Switchs.Contains(ID)? Switchs.Find(ID)->isTrue:false;
}

void UCastleNestInstance::SetSwitchValue(FString ID, FSwitch newValue)
{
	if (Switchs.Contains(ID))
	{
		Switchs.Add(ID, newValue);
	}
}
