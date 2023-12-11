// Fill out your copyright notice in the Description page of Project Settings.
/*
#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "DialogueGraphSchema.generated.h"

/**
 * 
UCLASS()
class OIZOEDITOR_API UDialogueGraphSchema : public UEdGraphSchema
{
	GENERATED_UCLASS_BODY()
	//~ Begin EdGraphSchema Interface
	virtual void CreateDefaultNodesForGraph(UEdGraph& Graph) const override;
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;
	virtual void GetContextMenuActions(const UEdGraph* CurrentGraph, const UEdGraphNode* InGraphNode, const UEdGraphPin* InGraphPin, class FMenuBuilder* MenuBuilder, bool bIsDebugging) const override;
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;
	virtual const FPinConnectionResponse CanMergeNodes(const UEdGraphNode* A, const UEdGraphNode* B) const override;
	virtual FLinearColor GetPinTypeColor(const FEdGraphPinType& PinType) const override;
	virtual int32 GetNodeSelectionCount(const UEdGraph* Graph) const override;
	virtual bool IsCacheVisualizationOutOfDate(int32 InVisualizationCacheID) const override;
	virtual int32 GetCurrentVisualizationCacheID() const override;
	virtual void ForceVisualizationCacheClear() const override;
	virtual TSharedPtr<FEdGraphSchemaAction> GetCreateCommentAction() const override;
};
 */
