// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueNPC.h"

#include <string>



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
	FName name = SentenceClass->GetFName();
	const auto tempSentence = NewObject<USentence>(this,SentenceClass, name,RF_Standalone);
	
	sentences.Add(tempSentence);
	return tempSentence;
}


