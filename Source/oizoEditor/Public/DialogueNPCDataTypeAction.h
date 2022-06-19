#pragma once
#include "AssetTypeActions_Base.h"
#include "AssetTypeActions/AssetTypeActions_Blueprint.h"
#include "SlateExtras.h"
#include "MyTestActor.h"
#include "DialogueNPC.h"


class FDialogueNPCDataTypeAction : public FAssetTypeActions_Blueprint
{
private:
	FDialogueNPCDataTypeAction(EAssetTypeCategories::Type InAssetCategory);
public:
	virtual FText GetName() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true;}
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;

	void ExecuteReimport(TArray<TWeakObjectPtr<UDialogueNPC>> Objects);


private:
	EAssetTypeCategories::Type MyAssetCategory;
};
