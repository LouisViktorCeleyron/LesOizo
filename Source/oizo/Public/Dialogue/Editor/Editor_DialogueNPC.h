// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Dialogue/DialogueNPC.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Editor_DialogueNPC.generated.h"

/**
 *
 * Faudrait que je mette les positions et tt ici mais mega flemme je vais les mettre dans Dialogue NPC faudras justqe que je pense a le retirer pour
 * le mettre ici plus tard
 */
UCLASS()
class OIZO_API UEditor_DialogueNPC : public UPrimaryDataAsset
{
	GENERATED_BODY()
	virtual bool IsEditorOnly() const override;
	public:
	
	public:
	UPROPERTY(BlueprintReadWrite)
	UDialogueNPC* target;
};
