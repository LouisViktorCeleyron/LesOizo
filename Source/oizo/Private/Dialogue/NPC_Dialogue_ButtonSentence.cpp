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

void UNPC_Dialogue_ButtonSentence::SetTransition(UNPC_Dialogue_ButtonSentence* SentenceButtonClickedOn)
{
	EditedSentence->UpdateTransition(currentSelectedTransitionIndex,SentenceButtonClickedOn->EditedSentence);
}

void UNPC_Dialogue_ButtonSentence::ResetBinding(FSimpleSentenceNPCButtonDelegateTransition OnSentenceClickDefault,
                                                FSimpleSentenceNPCButtonDelegateTransition OnSentenceTransitionClickDefault)
{
	UnbindDefaultSentenceBehaviour();
	OnSentenceButtonClick.Add(OnSentenceClickDefault);
	OnSentenceTransitionClick.Add(OnSentenceTransitionClickDefault);
	
}
