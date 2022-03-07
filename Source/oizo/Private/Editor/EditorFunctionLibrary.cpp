// Fill out your copyright notice in the Description page of Project Settings.


#include "EditorFunctionLibrary.h"
#include "Modules/ModuleManager.h"
//#include "AssetRegistry/AssetRegistryModule.h"


TArray<FString> UEditorFunctionLibrary::ReturnAllStringTableKeys()
{
	//FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	//TArray<FAssetData> AssetData;

	auto r = UKismetStringTableLibrary::GetKeysFromStringTable("Blala");

	return  r;
}

