// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetInventaireParent.h"
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
	
	public:
	UPROPERTY(BlueprintReadOnly)
	UWidgetInventaireParent* widgetInventory;
};
