// Fill out your copyright notice in the Description page of Project Settings.


#include "OizoBPEditorFuncLibrary.h"

#include "Blutility/Public/EditorUtilitySubsystem.h"
#include "Editor/UMGEditor/Public/WidgetBlueprint.h"
#include "Editor/LevelEditor/Public/LevelEditor.h"

#include "Editor/Blutility/Classes/EditorUtilityWidgetBlueprint.h"

UEditorUtilityWidget* UOizoBPEditorFuncLibrary::StartWidget(UWidgetBlueprint* Blueprint)
{
	if (Blueprint->GeneratedClass->IsChildOf(UEditorUtilityWidget::StaticClass()))
	{
		UEditorUtilityWidgetBlueprint* EditorWidget = static_cast<UEditorUtilityWidgetBlueprint*>(Blueprint);
		if (EditorWidget)
		{
			UEditorUtilitySubsystem* EditorUtilitySubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
			EditorUtilitySubsystem->SpawnAndRegisterTab(EditorWidget);
			return   EditorWidget->GetCreatedWidget();
		}
	}
	return nullptr;
}

bool UOizoBPEditorFuncLibrary::Modify(UObject* Object)
{
	return Object->Modify(true);
}

FSentence UOizoBPEditorFuncLibrary::MakeSentence(const FText content, const FString characterName,
                                                 const FTransition transition, const bool isMainChara, const FVector2D EditorPosition)
{
	return FSentence(content,characterName,transition,isMainChara,EditorPosition);
}

void UOizoBPEditorFuncLibrary::SetSentenceElementInArray(UDialogueNPC* DialogueNPC, const FSentence newElement,
	const int index)
{
	DialogueNPC->sentences[index] = newElement;
}

int UOizoBPEditorFuncLibrary::GetNextSentence(FSentence sentence,int answer)
{
	switch (sentence.transition.transitionType)
	{
		case SimpleTransition:
			return 0;		
		case WithAnswer:
			return answer;						
		case EndOfDialogue:
			return 99;
	}
	
	return 0;
}
