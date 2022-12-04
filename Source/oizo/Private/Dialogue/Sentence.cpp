// Fill out your copyright notice in the Description page of Project Settings.


#include "Sentence.h"

USentence::USentence()
{
}

void USentence::IWannaDie()
{
	this->ConditionalBeginDestroy();
}

UClassicSentence::UClassicSentence()
{

}

USentence* USentence::GetNextSentence(int i)
{
	return NextSentences[0];
}

USentence* UChoiceSentence::GetNextSentence(int i)
{
	return NextSentences[i];
}


