// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AboutScreen.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ClassicFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class OIZO_API UClassicFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType="parentClass"))
	static TArray<TSubclassOf<UObject>> GetAllSubclassOf(TSubclassOf<class UObject> parentClass);
	
};
