// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ItemAsset.h"
#include "GameFramework/PlayerState.h"
#include "CastlenestPlayerState.generated.h"

/**
 * 
 */



UCLASS(Blueprintable)
class OIZO_API ACastlenestPlayerState : public APlayerState
{
	GENERATED_BODY()
	public :

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UItemAsset*> Inventory;

	UPROPERTY(BlueprintReadOnly)
	UItemChapoAsset* CurrentChapo;

	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FChapoDelegate CalledWhenHatIsChanged;

	public:
	UFUNCTION(BlueprintCallable)
	void AddItemToInventory(UItemAsset* newItem);
	
	UFUNCTION(BlueprintCallable)
	void ChangeChapo(UItemChapoAsset* newChapo);
	
	UFUNCTION(BlueprintCallable)
    TArray<UItemChapoAsset*> GetAllChapoInInventory();
	
	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType="itemAssetClass"))
    TArray<UItemAsset*> GetSpecificInventory(TSubclassOf<class UItemAsset> itemAssetClass);

    
};
