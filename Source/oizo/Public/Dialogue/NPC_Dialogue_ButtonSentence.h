#pragma once

#include "Dialogue/DialogueNPC.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Sentence.h"
#include "NPC_Dialogue_ButtonSentence.generated.h"

/**
* 
*/

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIntDelegate,int,Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTransitionNPCDDelegate,int,SentenceIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FV2DintDelegate,FVector2D,Drag,int,SentenceIndex);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSentenceDelegate,USentence*,Sentence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FV2DSentenceDelegate,FVector2D,Drag,USentence*,Sentence);

DECLARE_DYNAMIC_DELEGATE_OneParam(FSimpleSentenceDelegate, USentence*, Sentence);

UCLASS(Blueprintable)
class OIZO_API UNPC_Dialogue_ButtonSentence : public UUserWidget
{
	public:

	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSentenceNPCButtonDelegateTransition, UNPC_Dialogue_ButtonSentence*, SentenceButton);
	DECLARE_DYNAMIC_DELEGATE_OneParam(FSimpleSentenceNPCButtonDelegateTransition, UNPC_Dialogue_ButtonSentence*, SentenceButton);



	public:
	UPROPERTY(BlueprintReadOnly,meta= (ExposeOnSpawn="true"))
	UDialogueNPC* DialogueTarget;
	UPROPERTY(BlueprintReadOnly,meta= (ExposeOnSpawn="true"))
	int SentenceIndex;
	UPROPERTY(BlueprintReadOnly,meta= (ExposeOnSpawn="true"))
	USentence* EditedSentence;
	UPROPERTY(BlueprintReadOnly)
	int currentSelectedTransitionIndex;

	public:
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FV2DintDelegate Move;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FTransitionNPCDDelegate OnTransitionClick;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FIntDelegate OnSentenceClick;

	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FV2DSentenceDelegate MoveSentence;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FSentenceNPCButtonDelegateTransition OnSentenceTransitionClick;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FSentenceNPCButtonDelegateTransition OnSentenceButtonClick;
    
	public:
	UFUNCTION(BlueprintCallable)
	void SetTransitionIndex(int index);
	UFUNCTION(BlueprintCallable,BlueprintPure)
    USentence* GetSentenceContent() const;
	UFUNCTION(BlueprintCallable)
	void IWannaDie();
	UFUNCTION(BlueprintCallable)
	void UnbindDefaultSentenceBehaviour();

public: 
	UFUNCTION(BlueprintCallable)
	virtual void SetTransition(UNPC_Dialogue_ButtonSentence* SentenceButtonClickedOn);
	
	UFUNCTION(BlueprintCallable)
    void ResetBinding(FSimpleSentenceNPCButtonDelegateTransition OnSentenceClickDefault, FSimpleSentenceNPCButtonDelegateTransition OnSentenceTransitionClickDefault);
};