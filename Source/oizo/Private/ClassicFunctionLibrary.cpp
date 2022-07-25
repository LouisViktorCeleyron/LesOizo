// Fill out your copyright notice in the Description page of Project Settings.


#include "ClassicFunctionLibrary.h"

#include "SubclassOf.h"
#include "UObject/Class.h"
#include "UObjectIterator.h"

TArray<TSubclassOf<UObject>> UClassicFunctionLibrary::GetAllSubclassOf(TSubclassOf<class UObject> parentClass)
{
	auto _return = TArray<TSubclassOf<UObject>>();
	for (TObjectIterator<UClass> It; It; ++It)
	{
		if(It->IsChildOf(parentClass->StaticClass()) && !It->HasAnyClassFlags(CLASS_Abstract))
		{
			_return.Add(*It);
		}
	}
	return _return; 
}
