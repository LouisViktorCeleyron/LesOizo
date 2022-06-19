// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueNPC.h"

#include <string>



#include "OizoBPEditorFuncLibrary.h"
#include "StructsForLocalization.h"
#include "Engine/World.h"

USentence* UDialogueNPC::GetSentence(int sentenceIndex)
{
	return sentences[sentenceIndex];
}

TArray<USentence*> UDialogueNPC::GetSentences()
{
	return sentences;
}

void UDialogueNPC::ClearSentences()
{
	for (USentence* Element : sentences)
	{
		Element->IWannaDie();
	}
	sentences.Empty();
}

USentence* UDialogueNPC::CreateSentence(TSubclassOf<USentence> SentenceClass)
{
	auto ID =UOizoBPEditorFuncLibrary::GenerateID(8);
	FName name  = FName(*ID);
	auto tempSentence = NewObject<USentence>(this,SentenceClass, name,RF_Standalone | RF_Public);
	sentences.Add(tempSentence);
	return tempSentence;
}


