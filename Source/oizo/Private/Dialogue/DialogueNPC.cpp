// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueNPC.h"

void UDialogueNPC::SetSentenceTransition(int sentenceIndex, FTransition transition)
{
	sentences[sentenceIndex].transition =transition;
}

FSentence UDialogueNPC::GetSentence(int sentenceIndex)
{
	return sentences[sentenceIndex];
}

TArray<FSentence> UDialogueNPC::GetSentences()
{
	return sentences;
}

