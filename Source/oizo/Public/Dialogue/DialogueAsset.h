// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructsForLocalization.h"
#include "UObject/NoExportTypes.h"
#include "Sentence.h"
#include "DialogueAsset.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_DELEGATE(FOnButtonDelegate);

UCLASS(BlueprintType)
class OIZO_API UDialogueAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FString dialogueName;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FStringTableForSentence content;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		TArray<USentence*> SentencesInDialogues;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		int sentenceIndex;
	FOnButtonDelegate clicked;
public :
	void AddSentence(TSubclassOf<USentence> sentenceClass);
	UFUNCTION(CallInEditor, BlueprintCallable)
	void AddClassicSentence();
	
	UFUNCTION(CallInEditor)
	void ChangeSentence();
};
