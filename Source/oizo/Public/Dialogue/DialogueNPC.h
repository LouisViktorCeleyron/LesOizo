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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int nextSentence;

	FTransition()
	{
		nextSentence = -1;
	}

	FORCEINLINE FTransition(int NextSentence)
	{
		nextSentence = NextSentence;
	}
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D EditorPosition;

	FSentence()
	{
	}
	FSentence(FString c, FString cn, FTransition t, FVector2D ep)
	{
		content =c;
		characterName =cn;
		transition =t;
		EditorPosition = ep;
	}
};


UCLASS()
class OIZO_API UDialogueNPC : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FSentence> sentences;

public:
	UFUNCTION(BlueprintCallable)
	void SetSentenceTransition(int sentenceIndex, FTransition transition);
};
