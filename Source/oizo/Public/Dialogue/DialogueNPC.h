// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "OizoEnumEditor.h"
#include "Sentence.h"
#include "DialogueNPC.generated.h"

UCLASS()
class OIZO_API UDialogueNPC : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<USentence*> sentences;
	

public:
	UFUNCTION(BlueprintPure,BlueprintCallable)
	USentence* GetSentence (int sentenceIndex);
	
	UFUNCTION(BlueprintPure,BlueprintCallable)
	TArray<USentence*> GetSentences ();

	UFUNCTION(BlueprintCallable)
    void ClearSentences ();


	UFUNCTION(BlueprintCallable, meta = (DeterminesOutputType="SentenceClass"))
    USentence* CreateSentence(TSubclassOf<class USentence> SentenceClass);

	
	
};

