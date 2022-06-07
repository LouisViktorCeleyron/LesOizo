// Fill out your copyright notice in the Description page of Project Settings.


#include "Sentence.h"

USentence::USentence()
{
}

void USentence::UpdateSentence( TArray<int> nextSentences, bool isMainCharacter,
	FVector2D editorPosition)
{
	NextSentences = nextSentences;
	IsMainCharacter = isMainCharacter;
	EditorPosition = editorPosition;
}

void USentence::IWannaDie()
{
	this->ConditionalBeginDestroy();
}

int USentence::GetNextSentence(int i)
{
	return NextSentences[0];
}

int UChoiceSentence::GetNextSentence(int i)
{
	return NextSentences[i];
}

