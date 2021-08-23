// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DialogueNPC.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FTransition
{
	GENERATED_BODY()
	public :
        UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int nextSentence;
};

USTRUCT(BlueprintType)
struct FSentence
{
	GENERATED_BODY()
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString content;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString characterName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FTransition transition;
};


UCLASS()
class OIZO_API UDialogueNPC : public UPrimaryDataAsset
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FSentence> sentences;	
	
};
