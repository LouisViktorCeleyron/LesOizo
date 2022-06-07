// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueNPC.h"
#include "Object.h"
#include "StructsForLocalization.h"
#include "Sentence.generated.h"

UCLASS(BlueprintType,Blueprintable, Abstract)
class OIZO_API USentence : public UObject
{
	public: 
	GENERATED_BODY()
	USentence();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStringTableForSentence Content;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStringTableForSentence CharacterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsMainCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<int> NextSentences;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D EditorPosition;

	public:
	UFUNCTION(BlueprintCallable)
	void IWannaDie();
	UFUNCTION(BlueprintCallable)
	virtual int GetNextSentence(int i = 0);
	void UpdateSentence(TArray<int> nextSentences, bool isMainCharacter, FVector2D editorPosition);
};

UCLASS(BlueprintType,Blueprintable)
class UClassicSentence : public USentence
{
public:
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite)
	FString labandeapicsou;
	
};

UCLASS(BlueprintType,Blueprintable)
class UChoiceSentence : public USentence
{
public:
	UPROPERTY(BlueprintReadWrite)
	float banana;
	virtual int GetNextSentence(int i) override;
	GENERATED_BODY()
public:
	
};