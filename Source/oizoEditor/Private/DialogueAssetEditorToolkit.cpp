#include "DialogueAssetEditorToolkit.h"
#include "DiaogueAssetWidget.h"
#include "Sentence.h"

#include "Misc/DefaultValueHelper.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Input/STextComboBox.h"
#include "PropertyEditorModule.h"
#include "Modules/ModuleManager.h"


void FDialogueAssetEditorToolkit::InitEditor(const TArray<UObject*>& InObjects)
{

	 Asset = Cast<UDialogueAsset>(InObjects[0]);

	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("NormalDistributionEditorLayout")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewSplitter()
				->SetSizeCoefficient(0.6f)
				->SetOrientation(Orient_Horizontal)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.8f)
					->AddTab("NormalDistributionPDFTab", ETabState::OpenedTab)
				)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.2f)
					->AddTab("NormalDistributionDetailsTab", ETabState::OpenedTab)
				)
			)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.4f)
				->AddTab("OutputLog", ETabState::OpenedTab)
			)
		);
	FAssetEditorToolkit::InitAssetEditor(EToolkitMode::Standalone, {}, "NormalDistributionEditor", Layout, true, true, InObjects);
}

void FDialogueAssetEditorToolkit::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(INVTEXT("Normal Distribution Editor"));

	DisplayDialogueDetail(InTabManager);
	if (Asset->SentencesInDialogues.Num() > 0)
	{
		DisplaySentenceDetail(InTabManager);
	}
		/*
	InTabManager->RegisterTabSpawner("NormalDistributionPDFTab", FOnSpawnTab::CreateLambda([=](const FSpawnTabArgs&)
		{
			return SNew(SDockTab)
				[
					SNew(SDialogueAssetWidget)
					.DialogueName(this, &FDialogueAssetEditorToolkit::GetName)
				.DialogueContent(this, &FDialogueAssetEditorToolkit::GetContent)
				];
		}))
		.SetDisplayName(INVTEXT("DialogueContent"))
			.SetGroup(WorkspaceMenuCategory.ToSharedRef());*/

		
}

void FDialogueAssetEditorToolkit::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
	InTabManager->UnregisterTabSpawner("SentenceDetailTab");

	InTabManager->UnregisterTabSpawner("DialogueAssetDetailTab");
}

FString FDialogueAssetEditorToolkit::GetName() const
{
	return Asset->dialogueName;
}

FStringTableForSentence FDialogueAssetEditorToolkit::GetContent() const
{
	return Asset->content;
}

void FDialogueAssetEditorToolkit::SetName(FString Name)
{
	Asset->Modify();
	Asset->dialogueName= Name;
}

void FDialogueAssetEditorToolkit::SetContent(FStringTableForSentence content)
{
	Asset->Modify();
	Asset->content= content;
}

void FDialogueAssetEditorToolkit::DisplayDialogueDetail(const TSharedRef<class FTabManager>& InTabManager)
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	TSharedRef<IDetailsView> DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	//Asset->clicked.BindDynamic(this, &FDialogueAssetEditorToolkit::ResetOption);

	DetailsView->SetObjects(TArray<UObject*>{ Asset });
	//DetailsView->SetObjects(TArray<UObject*>{ Asset->SentencesInDialogues[0] });
	InTabManager->RegisterTabSpawner("DialogueAssetDetailTab", FOnSpawnTab::CreateLambda([=](const FSpawnTabArgs&)
		{
			return SNew(SDockTab)
				[
					DetailsView
				];
		}))
		.SetDisplayName(INVTEXT("Details"))
			.SetGroup(WorkspaceMenuCategory.ToSharedRef());

}

void FDialogueAssetEditorToolkit::DisplaySentenceDetail(const TSharedRef<class FTabManager>& InTabManager)
{
	FPropertyEditorModule& PropertyEditorModuleForSentence = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgsForSentence;
	DetailsViewArgsForSentence.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	TSharedRef<IDetailsView> DetailsViewForSentence = PropertyEditorModuleForSentence.CreateDetailView(DetailsViewArgsForSentence);

	detailTarget = Asset->SentencesInDialogues[0];
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString("Banana")); //PrintToLog 

	auto comboBoxLambda = [this, DetailsViewForSentence](FComboItemInt newValue, ESelectInfo::Type)
	{
		//currentItemint = newValue;
		////UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::FromInt(index)); //PrintToLog 
		////UE_LOG(LogTemp, Warning, TEXT("%s"), newValue); //PrintToLog 
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *FString::FromInt(*newValue)); //PrintToLog 


		//detailTarget = Asset->SentencesInDialogues[0];

		////currentItem = newValue;
		////int index = 0;
		////options.Find(newValue, index);
		////detailTarget = Asset->SentencesInDialogues[index];

		//DetailsViewForSentence->SetObjects(TArray<UObject*>{ detailTarget});
	};

	sentenceDetailButton.BindLambda([this]() 
		{
			ResetOption();
			return FReply::Handled();
		});
	DetailsViewForSentence->SetObjects(TArray<UObject*>{ detailTarget});

	ResetOption();
	//currentItem = options[0];
	currentItemint = optionsInt[0];

	InTabManager->RegisterTabSpawner("SentenceDetailTab", FOnSpawnTab::CreateLambda([=](const FSpawnTabArgs&)
		{
			return
				SNew(SDockTab)
				[

					SNew(SVerticalBox)
					+ SVerticalBox::Slot().VAlign(VAlign_Top)
				[
					DetailsViewForSentence
				]
			+ SVerticalBox::Slot().VAlign(VAlign_Top)
				[
					SNew(SButton)
					.Text(FText::FromString(FString("Reload")))
				.OnClicked(sentenceDetailButton)
				]
			+ SVerticalBox::Slot().VAlign(VAlign_Top)
				[
					SNew(SComboBox<FComboItemInt>)
					.OptionsSource(&optionsInt)
					.InitiallySelectedItem(currentItemint)
					.OnSelectionChanged_Lambda(comboBoxLambda)
					.OnGenerateWidget(this, &FDialogueAssetEditorToolkit::MakeWidgetForOption)
					[
						SNew(STextBlock).Text(this,&FDialogueAssetEditorToolkit::GetComboBoxLabel)
					]
				]
				];

		}))
		.SetDisplayName(INVTEXT("DialogueContent"))
			.SetGroup(WorkspaceMenuCategory.ToSharedRef());
}


TSharedRef<SWidget> FDialogueAssetEditorToolkit::MakeWidgetForOption(FComboItemInt InOption)
{
	return SNew(STextBlock).Text(FText::FromString(FString::FromInt (3)));
}

FText FDialogueAssetEditorToolkit::GetComboBoxLabel() const
{

	if (currentItemint.IsValid())
	{
		return FText::FromString(FString::FromInt(12));
	}
	else
	{
		return FText::FromString(FString("Enorme Banane il ya r la "));
	}
	/*if (currentItem.IsValid())
	{
		return FText::FromString(FString::FromInt(*currentItem));
	}
	else
	{
		return FText::FromString(FString("Enorme Banane il ya r la "));
	}*/
}

void FDialogueAssetEditorToolkit::ResetOption()
{
	options.Empty();
	int index = 0;
	for (USentence* sentence : Asset->SentencesInDialogues)
	{
		//auto banana = MakeShareable(&FString::FromInt(index));
		auto brgi = FString("jkhfeki");
		auto banana = MakeShareable(&brgi);
		//UE_LOG(LogTemp, Warning, TEXT("%s"), banana); //PrintToLog 
		//options.Add(banana);
		auto intiti = MakeShareable(&index);
		optionsInt.Add(intiti);
		index++;
	}

	for (auto e : optionsInt)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), e); //PrintToLog 
	}
	/*for (USentence* sentence : Asset->SentencesInDialogues)
	{
		auto banana = MakeShareable(&sentence->SentenceID);
		options.Add(banana);

	}*/
}

