// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SwitchStructs.h"

#include "SwitchsStuffs.generated.h"

/**
 * 
 */


UENUM()
enum class ETrueFalseEnum : uint8
{
	TrueSwitch,
	FalseSwitch
};


UCLASS()
class OIZO_API USwitchsStuffs : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Meta = (ExpandEnumAsExecs = "Branches"))
	static void ReadSwitch(FString switchID, ETrueFalseEnum & Branches);
	
};
