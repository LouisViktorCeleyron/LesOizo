// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "CastlenestPlayerController.h"
#include "CastleNestInstance.h"
#include "Sentence.generated.h"


UCLASS(BlueprintType,Blueprintable, Abstract,EditInlineNew)
class OIZO_API USentence : public UObject
{
	public: 
	GENERATED_BODY()
	USentence();
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString SentenceID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Content;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText CharacterName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsMainCharacter;

	public:
	UFUNCTION(BlueprintCallable)
	void IWannaDie();
	UFUNCTION(BlueprintCallable)
	virtual FString GetNextSentenceID();
	
	UFUNCTION(BlueprintCallable)
	virtual void ActionCalledWithSentence(ACastlenestPlayerController* playerController)
	{
	}
};

UCLASS(BlueprintType,Blueprintable)
class UClassicSentence : public USentence
{

public:
	GENERATED_BODY()
		UClassicSentence();
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString NextSentence;
	
	virtual FString GetNextSentenceID() override;

};

UCLASS(BlueprintType, Blueprintable)
class USetSwitchSentence : public USentence
{

public:
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString NextSentence;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString SwitchID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FSwitch SwitchValue;
	
	virtual FString GetNextSentenceID() override;
	virtual void ActionCalledWithSentence(ACastlenestPlayerController* playerController) override;

};


UCLASS(BlueprintType, Blueprintable)
class UCheckSwitch : public USentence
{

public:
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString SwitchID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString NextSentenceIfTrue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString NextSentenceIfFalse;
	
	virtual FString GetNextSentenceID() override;

};

USTRUCT(BlueprintType)
struct FAnswerNextSentenceDuo 
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FString NextSentence;
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FText AnswerContent;
	
};

UCLASS(BlueprintType,Blueprintable)
class UChoiceSentence : public USentence
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int NextSentencesIndex;
	UPROPERTY(EditAnywhere)
		FAnswerNextSentenceDuo NextSentencesAndAnswer[3];
public: 
	virtual FString GetNextSentenceID() override;
	virtual void ActionCalledWithSentence(ACastlenestPlayerController* playerController) override;

	UFUNCTION(BlueprintCallable)
	FAnswerNextSentenceDuo GetAnswerNextSentenceDuoAtIndex(int index);
};