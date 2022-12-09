// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueAsset.h"
#include "Engine/Engine.h"
#include "OizoBPEditorFuncLibrary.h"



void UDialogueAsset::AddSentence(TSubclassOf<USentence> sentenceClass)
{
	if (SentencesInDialogues.Num() <= 0)
	{
		SentencesInDialogues = TArray<USentence*>();
	}
	auto ID = UOizoBPEditorFuncLibrary::GenerateID(8);
	FName name  = FName(*ID);
	auto tempSentence = NewObject<USentence>(this, sentenceClass, name, RF_Standalone | RF_Public);
	tempSentence->SentenceID = ID;
	SentencesInDialogues.Add(tempSentence);
}
void UDialogueAsset::AddClassicSentence()
{
	AddSentence(UClassicSentence::StaticClass());
	Modify();

	if (clicked.IsBound())
	{
		clicked.Execute();
	}
}


USentence* UDialogueAsset::GetSentenceFromID(FString ID)
{
	auto tempSentence = SentencesInDialogues.FindByPredicate([&,ID](USentence* us) {return us->SentenceID == ID; });
	return *tempSentence;
}
