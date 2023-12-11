// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UserWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CastleNestInstance.h"
#include "ClassicFunctionLibrary.generated.h"
/**
 * 
 */
UCLASS()
class OIZO_API UClassicFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	
public: 

	UFUNCTION(BlueprintCallable)
		static UCastleNestInstance* GetCastleNestInstance();
};