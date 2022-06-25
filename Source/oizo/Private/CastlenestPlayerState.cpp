// Fill out your copyright notice in the Description page of Project Settings.


#include "CastlenestPlayerState.h"

void ACastlenestPlayerState::ChangeChapo(UItemChapoAsset* newChapo)
{
	CurrentChapo = newChapo;
	CalledWhenHatIsChanged.Broadcast(newChapo);
}
