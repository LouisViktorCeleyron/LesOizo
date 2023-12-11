// Fill out your copyright notice in the Description page of Project Settings.


#include "DailogueAssetAction.h"
#include "Public/DialogueAssetEditorToolkit.h"
#include "DialogueAsset.h"

FDailogueAssetAction::FDailogueAssetAction()
{
}

FDailogueAssetAction::~FDailogueAssetAction()
{
}

FText FDailogueAssetAction::GetName() const
{
	return INVTEXT("Dialogue Asset");
}

UClass* FDailogueAssetAction::GetSupportedClass() const
{
	return UDialogueAsset::StaticClass();
}

FColor FDailogueAssetAction::GetTypeColor() const
{
	return FColor::Purple;
}

uint32 FDailogueAssetAction::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

void FDailogueAssetAction::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	//MakeShared<FDialogueAssetEditorToolkit>()->InitEditor(InObjects);
}
