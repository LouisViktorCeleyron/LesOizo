// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "OizoEnumEditor.h"
#include "DialogueNPC.generated.h"


USTRUCT(BlueprintType)
struct FTransition
{
	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> nextSentences;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EDialogueTransitionType> transitionType;
};

USTRUCT(BlueprintType)
struct FSentence
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText content;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString characterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isMainCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FTransition transition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D EditorPosition;

	FSentence()
	{
	}
	FSentence(FText c, FString cn, FTransition t, bool imc, FVector2D ep)
	{
		content =c;
		characterName =cn;
		transition =t;
		isMainCharacter = imc;
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
	UFUNCTION(BlueprintPure,BlueprintCallable)
	FSentence GetSentence (int sentenceIndex);
	UFUNCTION(BlueprintPure,BlueprintCallable)
	TArray<FSentence> GetSentences ();
};
