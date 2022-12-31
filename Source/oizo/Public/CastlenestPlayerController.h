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
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCalledToCreateDialogueChoice);

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
    void RemoveInventoryFromViewPort();
	
	public:
	UPROPERTY(BlueprintReadOnly)
	UWidgetInventaireParent* widgetInventory;

	UPROPERTY(BlueprintReadOnly)
	TArray<UWidgetInventaireParent*> AllChildren;

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TSubclassOf<UWidgetInventaireParent> widgetInventoryClass;

	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	TSubclassOf<ACapture3DObject> captureObjectClass;
	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FCalledToCreateDialogueChoice callToCreateDialogueChoice;
};
