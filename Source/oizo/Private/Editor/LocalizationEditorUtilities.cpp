// Fill out your copyright notice in the Description page of Project Settings.


#include "LocalizationEditorUtilities.h"

#include "Engine.h"
#include "StringTable.h"
#include "Engine/Blueprint.h"
#include "Kismet/KismetStringTableLibrary.h"


TArray<FStringTableContainer> ULocalizationEditorUtilities::ReturnAllStringTableKeys()
{
	//var for the function
	TArray<FStringTableContainer> _returnValue;

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
		auto _temp = FStringTableContainer();
		_temp.StringTableID = FName(*data.GetAsset()->GetPathName());
		_temp.Keys =  UKismetStringTableLibrary::GetKeysFromStringTable(_temp.StringTableID);
		_returnValue.Add(_temp);		
	}

	return  _returnValue;
}

const FString ULocalizationEditorUtilities::GetStringTablePath()
{
	return "/Game/Data/StringTables";
}

FStringTableForSentence ULocalizationEditorUtilities::SetStringTableForSentence(FStringTableContainer container,
	FString key)
{
	auto _return = FStringTableForSentence();
	_return.StringTableID = container.StringTableID;
	_return.index = container.Keys.Find(key);

	return _return;
}
