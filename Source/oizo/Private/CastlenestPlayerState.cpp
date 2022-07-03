// Fill out your copyright notice in the Description page of Project Settings.


#include "CastlenestPlayerState.h"

void ACastlenestPlayerState::ChangeChapo(UItemChapoAsset* newChapo)
{
	CurrentChapo = newChapo;
	CalledWhenHatIsChanged.Broadcast(newChapo);
}

TArray<UItemChapoAsset*> ACastlenestPlayerState::GetAllChapoInInventory()
{
	TArray<UItemChapoAsset*> _return;
	for (UItemAsset* _item : Inventory)
	{
		UItemChapoAsset* _castedItem = Cast<UItemChapoAsset>(_item);
		if(IsValid(_castedItem))
		{
			_return.Add(_castedItem);
		}
	}
	return _return;
}
