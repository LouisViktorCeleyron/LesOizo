// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueAssetFactory.h"

#include "DialogueAsset.h"

UDialogueAssetFactory::UDialogueAssetFactory()
{
	SupportedClass = UDialogueAsset::StaticClass();
	bCreateNew = true;
}

UObject* UDialogueAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
                                                 UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UDialogueAsset>(InParent, Class, Name, Flags, Context);
}


