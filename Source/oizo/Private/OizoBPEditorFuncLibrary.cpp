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

FString UOizoBPEditorFuncLibrary::GenerateID(const int idLenght)
{
	const FString _value = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	FString _retValue = "";
	for (int i =0; i<= idLenght; i++)
	{
		_retValue.Append(_value.Mid(FMath::RandRange(0,_value.Len()+1),1));
	}

	return _retValue;
}

