// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CastleNestInstance.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class OIZO_API UCastleNestInstance : public UGameInstance
{
	GENERATED_BODY()
	public:
	UPROPERTY(BlueprintReadWrite)
	FString PlayerName;
	
	UPROPERTY(BlueprintReadWrite)
	FString Pronoun;


	public:
	UFUNCTION(BlueprintCallable)
	void AppendPlayerName(FString stringToAdd);
	
	UFUNCTION(BlueprintCallable)
    void RemoveLastLetterOfPlayerName();
};
