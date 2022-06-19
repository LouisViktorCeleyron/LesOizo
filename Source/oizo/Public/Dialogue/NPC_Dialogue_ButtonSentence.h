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


UCLASS(Blueprintable)
class OIZO_API UNPC_Dialogue_ButtonSentence : public UUserWidget
{
	public:
	GENERATED_BODY()

	public:
	UPROPERTY(BlueprintReadOnly,meta= (ExposeOnSpawn="true"))
	UDialogueNPC* DialogueTarget;
	UPROPERTY(BlueprintReadOnly,meta= (ExposeOnSpawn="true"))
	int SentenceIndex;
	UPROPERTY(BlueprintReadOnly,meta= (ExposeOnSpawn="true"))
	USentence* EditedSentence;
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
	FSentenceDelegate OnSentenceTransitionClick;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FSentenceDelegate OnSentenceButtonClick;
    
	public:
	UFUNCTION(BlueprintCallable,BlueprintPure)
    USentence* GetSentenceContent() const;
	UFUNCTION(BlueprintCallable)
	void IWannaDie();
	UFUNCTION(BlueprintCallable)
	void UnbindDefaultSentenceBehaviour(int test);
	
};