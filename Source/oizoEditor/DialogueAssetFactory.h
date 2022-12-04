// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "DialogueAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class OIZOEDITOR_API UDialogueAssetFactory : public UFactory
{
	GENERATED_BODY()
	
	
	public:
		UDialogueAssetFactory();
		UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn);
};
