// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AssetRegistry/Public/AssetRegistryModule.h"
#include "LocalizationEditorUtilities.generated.h"
/**
 * 
 */
UCLASS()
class OIZO_API ULocalizationEditorUtilities : public UBlueprintFunctionLibrary
{
	
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static TArray<FString> ReturnAllStringTableKeys();  
};
