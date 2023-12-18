// Fill out your copyright notice in the Description page of Project Settings.


#include "Sentence.h"
#include "ClassicFunctionLibrary.h"


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

FString USentence::GetNextSentenceID()
{
	return FString("STOP");
}

FString UClassicSentence::GetNextSentenceID()
{
	return NextSentence;
}


FString UChoiceSentence::GetNextSentenceID()
{
	return NextSentencesAndAnswer[NextSentencesIndex].NextSentence;
}

void UChoiceSentence::ActionCalledWithSentence(ACastlenestPlayerController* playerController)
{
	playerController->callToCreateDialogueChoice.Broadcast();
}

FAnswerNextSentenceDuo UChoiceSentence::GetAnswerNextSentenceDuoAtIndex(int index)
{
	auto _index = FMath::Max(0,index);
	_index = FMath::Min(2,_index);

	return NextSentencesAndAnswer[_index];
}

FString UCheckSwitch::GetNextSentenceID()
{
	auto _instanceSwitchRef = UClassicFunctionLibrary::GetCastleNestInstance()->Switchs;
	if (_instanceSwitchRef.Contains(SwitchID))
	{
		return _instanceSwitchRef[SwitchID].isTrue?NextSentenceIfTrue:NextSentenceIfFalse;

	}

	return USentence::GetNextSentenceID();
}

FString USetSwitchSentence::GetNextSentenceID()
{

	return NextSentence;
}

void USetSwitchSentence::ActionCalledWithSentence(ACastlenestPlayerController* playerController)
{
	auto const _instanceSwitchRef = UClassicFunctionLibrary::GetCastleNestInstance()->Switchs;
	if (_instanceSwitchRef.Contains(SwitchID))
	{
		UClassicFunctionLibrary::GetCastleNestInstance()->Switchs.Add(SwitchID, SwitchValue);
	}
}
