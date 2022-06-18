// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_Dialogue_ButtonSentence.h"


void UNPC_Dialogue_ButtonSentence::SetTransitionIndex(int index)
{
	currentSelectedTransitionIndex = index;
}

USentence* UNPC_Dialogue_ButtonSentence::GetSentenceContent() const
{
	return DialogueTarget->sentences[SentenceIndex];
}

void UNPC_Dialogue_ButtonSentence::IWannaDie()
{
	Destruct();
}

void UNPC_Dialogue_ButtonSentence::UnbindDefaultSentenceBehaviour()
{
	OnSentenceButtonClick.Clear();
	OnSentenceTransitionClick.Clear();
}

void UNPC_Dialogue_ButtonSentence::SetTransition(USentence* ClickedSentence)
{
	EditedSentence->UpdateTransition(currentSelectedTransitionIndex,ClickedSentence);
}

void UNPC_Dialogue_ButtonSentence::UpdateMove(FVector2D Drag, FVector2D Min, FVector2D Max)
{

	// const auto _newPos =EditedSentence->EditorPosition + Drag; 
	// EditedSentence->EditorPosition =
	// 	FVector2D(
	// 		FMath::Clamp(_newPos.X,Min.X,Max.X),
	// 		FMath::Clamp(_newPos.Y,Min.Y,Max.Y));
	EditedSentence->EditorPosition += Drag;	
}

void UNPC_Dialogue_ButtonSentence::ResetBinding(FSimpleSentenceDelegate OnSentenceClickDefault,
                                                FSimpleSentenceDelegate OnSentenceTransitionClickDefault)
{
	UnbindDefaultSentenceBehaviour();
	OnSentenceButtonClick.Add(OnSentenceClickDefault);
	OnSentenceTransitionClick.Add(OnSentenceTransitionClickDefault);
	
}
