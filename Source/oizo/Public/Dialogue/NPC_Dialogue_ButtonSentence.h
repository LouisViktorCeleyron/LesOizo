// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Dialogue/DialogueNPC.h"
#include "CoreMinimal.h"

#include <activation.h>

#include "Blueprint/UserWidget.h"
#include "NPC_Dialogue_ButtonSentence.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIntDelegate,int,Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTransitionNPCDDelegate,FTransition,Transitoion);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FV2DintDelegate,FVector2D,Drag,int,SentenceIndex);

UCLASS(Blueprintable)
class OIZO_API UNPC_Dialogue_ButtonSentence : public UUserWidget
{
private:
	GENERATED_BODY()

	public:
	UPROPERTY(BlueprintReadOnly,meta= (ExposeOnSpawn="true"))
	UDialogueNPC* DialogueTarget;
	UPROPERTY(BlueprintReadOnly,meta= (ExposeOnSpawn="true"))
	int SentenceIndex;

	public:
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FV2DintDelegate Move;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FTransitionNPCDDelegate OnTransitionClick;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FIntDelegate OnSentenceClick;
	
	public:
	UFUNCTION(BlueprintCallable,BlueprintPure)
	FSentence GetSentenceContent() const;	
};