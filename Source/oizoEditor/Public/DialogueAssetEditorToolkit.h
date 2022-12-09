// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DialogueAssetEditorToolkit.h"
#include "DialogueAsset.h"
#include "Widgets/Input/SButton.h"
#include "Toolkits/AssetEditorToolkit.h"

typedef TSharedPtr<FString> FComboItem;
typedef TSharedPtr<int> FComboItemInt;

class FDialogueAssetEditorToolkit : public FAssetEditorToolkit
{
public:
	void InitEditor(const TArray<UObject*>& InObjects);

	void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
	void UnregisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;

	FName GetToolkitFName() const override { return "DialogueAssetEditor"; }
	FText GetBaseToolkitName() const override { return INVTEXT("Dialogue Asset Editor"); }
	FString GetWorldCentricTabPrefix() const override { return "Content"; }
	FLinearColor GetWorldCentricTabColorScale() const override { return {}; }
	FString GetName() const;
	FStringTableForSentence GetContent() const;
	void SetName(FString Name);
	void SetContent(FStringTableForSentence Content);
	TArray<FComboItem> options;
	TArray<FComboItemInt> optionsInt;
	FComboItem currentItem;
	FComboItemInt currentItemint;

private:
	UDialogueAsset* Asset;
	UObject* detailTarget;

	FOnClicked sentenceDetailButton;

private:
	void DisplayDialogueDetail(const TSharedRef<class FTabManager>& InTabManager);
	void DisplaySentenceDetail(const TSharedRef<class FTabManager>& InTabManager);
	TSharedRef<SWidget> MakeWidgetForOption(FComboItemInt i);
	FText GetComboBoxLabel() const;
	void ResetOption();
};
