// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CastlenestBaseUserWidget.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRemove);

UCLASS(BlueprintType,Blueprintable)
class OIZO_API UCastlenestBaseUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FOnRemove CalledOnRemove;
	
public:
	virtual void RemoveFromParent() override;
};
