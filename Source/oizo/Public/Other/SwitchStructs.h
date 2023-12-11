// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "SwitchStructs.generated.h"

USTRUCT(BlueprintType)
struct FSwitch
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool isTrue;
};