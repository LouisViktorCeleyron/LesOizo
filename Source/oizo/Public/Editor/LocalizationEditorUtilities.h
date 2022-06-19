// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StructsForLocalization.h"
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

	UFUNCTION(BlueprintCallable,BlueprintPure)
	static TArray<FStringTableContainer> ReturnAllStringTableKeys();
	UFUNCTION(BlueprintCallable,BlueprintPure)
	static const FString GetStringTablePath();
	UFUNCTION(BlueprintCallable)
    static FStringTableForSentence SetStringTableForSentence(FStringTableContainer container, FString key);
};
