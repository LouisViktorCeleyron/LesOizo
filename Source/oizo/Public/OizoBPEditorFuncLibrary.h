// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPC_Dialogue_ButtonSentence.h"
#include "Editor/Blutility/Classes/EditorUtilityWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UMGEditor/Public/WidgetBlueprint.h"
#include "Editor/Blutility/Classes/EditorUtilityWidgetBlueprint.h"

#include "OizoBPEditorFuncLibrary.generated.h"

/**
 * 
 */
UCLASS()
class OIZO_API UOizoBPEditorFuncLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
        static UEditorUtilityWidget* StartWidget(UWidgetBlueprint* Blueprint);
	
	UFUNCTION(BlueprintCallable)
        static bool Modify(UObject* Object);
	
	UFUNCTION(BlueprintCallable,BlueprintPure)
        static FSentence MakeSentence(const FText content, const FString characterName, const FTransition transition,const bool isMainChara, const FVector2D EditorPosition);

	UFUNCTION(BlueprintCallable)
        static void SetSentenceElementInArray(UDialogueNPC* DialogueNPC, const FSentence newElement, const int index);

	
};


