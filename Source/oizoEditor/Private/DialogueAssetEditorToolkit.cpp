#include "DialogueAssetEditorToolkit.h"
#include "Widgets/Docking/SDockTab.h"
#include "DiaogueAssetWidget.h"
#include "Sentence.h"
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

	FPropertyEditorModule& PropertyEditorModuleForSentence = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgsForSentence;
	DetailsViewArgsForSentence.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	TSharedRef<IDetailsView> DetailsViewForSentence = PropertyEditorModuleForSentence.CreateDetailView(DetailsViewArgsForSentence);
	
	detailTarget = Asset->SentencesInDialogues[Asset->sentenceIndex];			
	auto tempLambda = [this, DetailsViewForSentence, &PropertyEditorModuleForSentence]()
	{
		detailTarget = Asset->SentencesInDialogues[Asset->sentenceIndex];
		Asset->Modify();
		DetailsViewForSentence->SetObjects(TArray<UObject*>{ detailTarget});
		DetailsViewForSentence->ForceRefresh();
		PropertyEditorModuleForSentence.NotifyCustomizationModuleChanged();
	};
	//Asset->clicked.BindDynamic(this, FDialogueAssetEditorToolkit::UpdateDetails);
	DetailsViewForSentence->SetObjects(TArray<UObject*>{ detailTarget});
	InTabManager->RegisterTabSpawner("NormalDistributionPDFTab", FOnSpawnTab::CreateLambda([=](const FSpawnTabArgs&)
		{
			return SNew(SDockTab)
				[
					DetailsViewForSentence
				];
		}))
		.SetDisplayName(INVTEXT("DialogueContent"))
			.SetGroup(WorkspaceMenuCategory.ToSharedRef());
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

		FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		FDetailsViewArgs DetailsViewArgs;
		DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
		TSharedRef<IDetailsView> DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

		DetailsView->SetObjects(TArray<UObject*>{ Asset });
		//DetailsView->SetObjects(TArray<UObject*>{ Asset->SentencesInDialogues[0] });
		InTabManager->RegisterTabSpawner("NormalDistributionDetailsTab", FOnSpawnTab::CreateLambda([=](const FSpawnTabArgs&)
			{
				return SNew(SDockTab)
					[
						DetailsView
					];
			}))
			.SetDisplayName(INVTEXT("Details"))
				.SetGroup(WorkspaceMenuCategory.ToSharedRef());

}

void FDialogueAssetEditorToolkit::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
	InTabManager->UnregisterTabSpawner("NormalDistributionPDFTab");
	InTabManager->UnregisterTabSpawner("NormalDistributionDetailsTab");
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
