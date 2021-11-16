// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_Dialogue_ButtonSentence.h"

FSentence UNPC_Dialogue_ButtonSentence::GetSentenceContent() const
{
	return DialogueTarget->sentences[SentenceIndex];
}

void UNPC_Dialogue_ButtonSentence::IWannaDie()
{
	Destruct();
}

void UNPC_Dialogue_ButtonSentence::UnbindDefaultSentenceBehaviour(int test)
{
	OnSentenceClick.Clear();
	OnTransitionClick.Clear();
}
