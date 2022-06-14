// Fill out your copyright notice in the Description page of Project Settings.


#include "Sentence.h"

USentence::USentence()
{
}

void USentence::UpdateSentence( TArray<USentence*> nextSentences, bool isMainCharacter,
	FVector2D editorPosition)
{
	NextSentences = nextSentences;
	IsMainCharacter = isMainCharacter;
	EditorPosition = editorPosition;
}

void USentence::UpdateTransition(int transitionIndex, USentence* newTransition)
{
	NextSentences[transitionIndex] = newTransition;
}

void USentence::IWannaDie()
{
	this->ConditionalBeginDestroy();
}

USentence* USentence::GetNextSentence(int i)
{
	return NextSentences[0];
}

USentence* UChoiceSentence::GetNextSentence(int i)
{
	return NextSentences[i];
}


