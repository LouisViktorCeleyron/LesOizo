#pragma once

#include "Dialogue/DialogueNPC.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Sentence.h"
#include "NPC_Dialogue_ButtonSentence.generated.h"

/**
* 
*/

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSentenceDelegate,USentence*,Sentence);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FV2DSentenceDelegate,FVector2D,Drag,USentence*,Sentence);

DECLARE_DYNAMIC_DELEGATE_OneParam(FSimpleSentenceDelegate, USentence*, Sentence);


UCLASS(Blueprintable)
class OIZO_API UNPC_Dialogue_ButtonSentence : public UUserWidget
{
	GENERATED_BODY()


	public:
	UPROPERTY(BlueprintReadOnly,meta= (ExposeOnSpawn="true"))
	UDialogueNPC* DialogueTarget;
	UPROPERTY(BlueprintReadOnly,meta= (ExposeOnSpawn="true"))
	int SentenceIndex;
	UPROPERTY(BlueprintReadOnly,meta= (ExposeOnSpawn="true"))
	USentence* EditedSentence;
	UPROPERTY(BlueprintReadOnly)
	int currentSelectedTransitionIndex;

	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FV2DSentenceDelegate MoveSentence;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FSentenceDelegate OnSentenceTransitionClick;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FSentenceDelegate OnSentenceButtonClick;
    
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
	virtual void SetTransition(USentence* ClickedSentence);

	UFUNCTION(BlueprintCallable)
	void UpdateMove(FVector2D Drag,FVector2D Min, FVector2D Max);
	
	UFUNCTION(BlueprintCallable)
    void ResetBinding(FSimpleSentenceDelegate OnSentenceClickDefault, FSimpleSentenceDelegate OnSentenceTransitionClickDefault);
};
