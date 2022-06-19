#include "DialogueNPCDataTypeAction.h"

FDialogueNPCDataTypeAction::FDialogueNPCDataTypeAction(EAssetTypeCategories::Type InAssetCategory)
	: MyAssetCategory(InAssetCategory)
{
}

FText FDialogueNPCDataTypeAction::GetName() const
{
	return FText::FromString("NPC_Dialogue");
}

UClass* FDialogueNPCDataTypeAction::GetSupportedClass() const
{
	return AMyTestActor::StaticClass();
}

FColor FDialogueNPCDataTypeAction::GetTypeColor() const
{
	return FColor(232,240,20); 
}

uint32 FDialogueNPCDataTypeAction::GetCategories()
{
	return MyAssetCategory;
}

void FDialogueNPCDataTypeAction::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
{
	auto myDataAsset = GetTypedWeakObjectPtrs<UDialogueNPC>(InObjects);

	MenuBuilder.AddMenuEntry(
        FText::FromString("El Pelicano"),
        FText::FromString("El pelicano est un enero de avez marinas famoso pour su enorme pico "),
        FSlateIcon(),
        FUIAction(
            FExecuteAction::CreateSP(this, &FDialogueNPCDataTypeAction::ExecuteReimport, myDataAsset),
            FCanExecuteAction()));
}

void FDialogueNPCDataTypeAction::ExecuteReimport(TArray<TWeakObjectPtr<UDialogueNPC>> Objects)
{
	FString t = FString("coucou"); //Message
	GEngine->AddOnScreenDebugMessage(FMath::Rand(),10,FColor::Red,t); //Print to Screen
	UE_LOG(LogTemp,Warning,TEXT("%s"), *t); //PrintToLog
}
