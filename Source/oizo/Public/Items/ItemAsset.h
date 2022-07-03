// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/Texture.h"
#include "ItemAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class OIZO_API UItemAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	FString Name;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	FString Description;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	UTexture2D* Icon;
	UPROPERTY(BlueprintReadOnly,EditAnywhere)
	UStaticMesh* Mesh;
	

	
};


UCLASS(Blueprintable)
class UItemChapoAsset : public UItemAsset
{
	GENERATED_BODY()
public:
	
	
	
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChapoDelegate,UItemChapoAsset*,Chapo);