// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Editor/Blutility/Classes/EditorUtilityWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UMGEditor/Public/WidgetBlueprint.h"


#include "OizoBPEditorFuncLibrary.generated.h"

/**
 * 
 */
UCLASS()
class OIZO_API UOizoBPEditorFuncLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
        static void StartWidget(UWidgetBlueprint* Blueprint);
};
