// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFactory.h"
#include "MyObject.h"

UMyFactory::UMyFactory()
{
	SupportedClass = UMyObject::StaticClass();
	bCreateNew = true;
}

UObject* UMyFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
                                                 UObject* Context, FFeedbackContext* Warn)
{
	return nullptr;
	//return NewObject<UDialogueAsset>(InParent, Class, Name, Flags, Context); 
}


