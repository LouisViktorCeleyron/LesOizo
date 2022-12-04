// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "StructsForLocalization.h"
#include "Sentence.generated.h"


UCLASS(BlueprintType,Blueprintable, Abstract,EditInlineNew)
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
	TArray<USentence*> NextSentences;

	public:
	UFUNCTION(BlueprintCallable)
	void IWannaDie();
	UFUNCTION(BlueprintCallable)
	virtual USentence* GetNextSentence(int i = 0);
};

UCLASS(BlueprintType,Blueprintable)
class UClassicSentence : public USentence
{
public:
	GENERATED_BODY()
		UClassicSentence();
	
};

UCLASS(BlueprintType,Blueprintable)
class UChoiceSentence : public USentence
{
public:
	GENERATED_BODY()
public: 
	virtual USentence* GetNextSentence(int i) override;

	
};