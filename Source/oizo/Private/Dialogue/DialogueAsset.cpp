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

	auto ID = sentenceClass.Get()->GetName() + UOizoBPEditorFuncLibrary::GenerateID(4);
	FName name  = FName(*ID);
	auto tempSentence = NewObject<USentence>(this, sentenceClass, name, RF_Public);
	tempSentence->SentenceID = ID;
	SentencesInDialogues.Add(tempSentence);
}
void UDialogueAsset::AddClassicSentence()
{
	AddSentence(UClassicSentence::StaticClass());
	Modify();
}

void UDialogueAsset::AddChoiceSentence()
{
	AddSentence(UChoiceSentence::StaticClass());
	Modify();
}

void UDialogueAsset::AddCheckSwitchSentence()
{
	AddSentence(UCheckSwitch::StaticClass());
	Modify();
}

void UDialogueAsset::AddSetSwitchSentence()
{
	AddSentence(USetSwitchSentence::StaticClass());
	Modify();
}


USentence* UDialogueAsset::GetSentenceFromID(FString ID,  bool &found)
{
	auto tempSentenceFromID = SentencesInDialogues.FindByPredicate([&,ID](USentence* us) {return us->SentenceID == ID; });
	found = tempSentenceFromID != nullptr;
	return found ? *tempSentenceFromID : nullptr;
}

USentence* UDialogueAsset::GetNextSentenceFrom(USentence* sentence, EBranchEnum& Branches)
{
	auto _isFound = false;
	auto _ret = GetSentenceFromID(sentence->GetNextSentenceID(), _isFound);
	if (_isFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *FString("True"));
		Branches = EBranchEnum::SentenceFound;
		return _ret;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *FString("False"));
		Branches = EBranchEnum::SentenceNull;
		return nullptr;
	}

}

//USentence* UDialogueAsset::GetSentenceFromIDWithIFNull(FString sentenceID, EBranchEnum& Branches)
//{
//	auto _ret = GetSentenceFromID(sentenceID);
//	if()
//	return _ret;
//}

