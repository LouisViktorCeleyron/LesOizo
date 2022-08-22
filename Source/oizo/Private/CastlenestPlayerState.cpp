// Fill out your copyright notice in the Description page of Project Settings.


#include "CastlenestPlayerState.h"
#include "Engine/Engine.h"

void ACastlenestPlayerState::AddItemToInventory(UItemAsset* newItem)
{
	Inventory.Add(newItem);
}

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

TArray<UItemAsset*> ACastlenestPlayerState::GetSpecificInventory(TSubclassOf<class UItemAsset> itemAssetClass)
{
	auto _return = TArray<UItemAsset*>();

	for(auto _item : Inventory)
	{
		// FString t = _item->GetClass()->GetDescription(); //Message
		// GEngine->AddOnScreenDebugMessage(FMath::Rand(),10,FColor::Red,t); //Print to Screen
		// UE_LOG(LogTemp,Warning,TEXT("%s"), *t); //PrintToLog
		if(_item->GetClass() == itemAssetClass)
		{
			
			_return.Add(_item);
		}
	}

	return _return;
}