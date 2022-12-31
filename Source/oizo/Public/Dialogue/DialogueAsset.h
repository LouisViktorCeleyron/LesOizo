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
UENUM()
enum class EBranchEnum : uint8
{
	SentenceFound,
	SentenceNull
};

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
public :
		void AddSentence(TSubclassOf<USentence> sentenceClass);
	UFUNCTION(CallInEditor, BlueprintCallable)
		void AddClassicSentence();
	UFUNCTION(CallInEditor, BlueprintCallable)
		void AddChoiceSentence();
	UFUNCTION(CallInEditor, BlueprintCallable)
		void AddCheckSwitchSentence();
	UFUNCTION(CallInEditor, BlueprintCallable)
		void AddSetSwitchSentence();

	UFUNCTION(BlueprintCallable)
	USentence* GetSentenceFromID(FString ID, bool& found);

	UFUNCTION(BlueprintCallable, Meta = (ExpandEnumAsExecs = "Branches"))
	USentence* GetNextSentenceFrom(USentence* sentence, EBranchEnum & Branches);

};
