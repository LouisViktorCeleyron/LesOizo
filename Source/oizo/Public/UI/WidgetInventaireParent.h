// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capture3DObject.h"
#include "CastlenestBaseUserWidget.h"
#include "UserWidget.h"

#include "WidgetInventaireParent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class OIZO_API UWidgetInventaireParent : public UCastlenestBaseUserWidget
{

private:
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
	ACapture3DObject* StudioBP;

public :
	UFUNCTION(BlueprintCallable)
	void DestroyStudioBP();
	virtual void RemoveFromParent() override;

	
};
