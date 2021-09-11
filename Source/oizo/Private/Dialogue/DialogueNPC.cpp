// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueNPC.h"

void UDialogueNPC::SetSentenceTransition(int sentenceIndex, FTransition transition)
{
	sentences[sentenceIndex].transition =transition;
}
