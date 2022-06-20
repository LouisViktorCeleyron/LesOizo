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
