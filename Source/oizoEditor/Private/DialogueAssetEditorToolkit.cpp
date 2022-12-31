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


void FDialogueAssetEditorToolkit::DisplayDialogueDetail(const TSharedRef<class FTabManager>& InTabManager)
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	TSharedRef<IDetailsView> DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	DetailsView->SetObjects(TArray<UObject*>{ Asset });
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
	//Init Editor
	FPropertyEditorModule& PropertyEditorModuleForSentence = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgsForSentence;
	DetailsViewArgsForSentence.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	TSharedRef<IDetailsView> DetailsViewForSentence = PropertyEditorModuleForSentence.CreateDetailView(DetailsViewArgsForSentence);
	
	//Display
	detailTarget = Asset->SentencesInDialogues[GenerateIndex()];
	DetailsViewForSentence->SetObjects(TArray<UObject*>{ detailTarget});

	//Lanbda for button
	sentenceDetailButton.BindLambda([this, DetailsViewForSentence]()
		{
			detailTarget = Asset->SentencesInDialogues[GenerateIndex()];
			DetailsViewForSentence->SetObjects(TArray<UObject*>{ detailTarget});
			return FReply::Handled();

		});


	//Slate
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
				];

		}))
		.SetDisplayName(INVTEXT("DialogueContent"))
			.SetGroup(WorkspaceMenuCategory.ToSharedRef());
}

int FDialogueAssetEditorToolkit::GenerateIndex()
{
	return FMath::Min(Asset->sentenceIndex, Asset->SentencesInDialogues.Num() - 1);;
}

