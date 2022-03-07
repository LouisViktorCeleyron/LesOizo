// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalizationEditorUtilities.h"

#include "Engine.h"
#include "StringTable.h"
#include "Engine/Blueprint.h"
#include "Kismet/KismetStringTableLibrary.h"


TArray<FString> ULocalizationEditorUtilities::ReturnAllStringTableKeys()
{
	//var for the function
	TArray<FString> _returnValue;

	//Get Asset from folders
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetData;
	FARFilter Filter;
	Filter.PackagePaths.Add("/Game/Data/StringTables");
	Filter.ClassNames.Add(UStringTable::StaticClass()->GetFName());
	AssetRegistryModule.Get().GetAssets(Filter,AssetData);

	//Get Key From StringTable asset
	for (FAssetData data : AssetData)
	{
		auto _temp = UKismetStringTableLibrary::GetKeysFromStringTable(FName(*data.GetAsset()->GetPathName()));
		_returnValue.Append(_temp);
	}

	return  _returnValue;
}
