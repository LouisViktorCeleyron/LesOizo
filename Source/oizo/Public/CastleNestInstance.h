// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Materials/MaterialInstance.h"

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


	UPROPERTY(BlueprintReadWrite)
	bool MEGATEMPORAIRE_IsNameValidated;
	UPROPERTY(BlueprintReadWrite)
	FTransform MEGATEMPORAIRE_KiwiTransform;
	UPROPERTY(BlueprintReadWrite)
	TArray<FLinearColor> UTLRATEMPORAIRE_CharaColor;
	UPROPERTY(BlueprintReadWrite)
	UTexture* UTLRATEMPORAIRE_CharaBase;

	public:
	UFUNCTION(BlueprintCallable)
	void AppendPlayerName(FString stringToAdd);
	
	UFUNCTION(BlueprintCallable)
    void RemoveLastLetterOfPlayerName();
};
