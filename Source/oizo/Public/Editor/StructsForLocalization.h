// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StructsForLocalization.generated.h"

USTRUCT(BlueprintType)
struct FStringTableContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FName StringTableID;
	UPROPERTY(BlueprintReadOnly)
	TArray<FString> Keys;
};

USTRUCT(BlueprintType)
struct FStringTableForSentence
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	FName StringTableID;
	UPROPERTY(BlueprintReadOnly)
	int index;
};
