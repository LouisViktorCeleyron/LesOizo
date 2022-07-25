// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetInventaireParent.h"
#include "ItemAsset.h"
#include "GameFramework/PlayerController.h"
#include "CastlenestPlayerController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class OIZO_API ACastlenestPlayerController : public APlayerController
{
	GENERATED_BODY()

	protected:
	virtual void BeginPlay() override;
	protected:
	UFUNCTION(BlueprintCallable)
	void AddInventoryToViewPort();
	
	UFUNCTION(BlueprintCallable)
    void AddItemToInventory(UItemAsset* newItem);

	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType="itemAssetClass"))
	TArray<UItemAsset*> GetSpecificInventory(TSubclassOf<class UItemAsset> itemAssetClass);

	
	public:
	UPROPERTY(BlueprintReadOnly)
	UWidgetInventaireParent* widgetInventory;

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TSubclassOf<UWidgetInventaireParent> widgetInventoryClass;

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TSubclassOf<ACapture3DObject> captureObjectClass;

	UPROPERTY(BlueprintReadOnly)
	TArray<UItemAsset*> inventory;
};
