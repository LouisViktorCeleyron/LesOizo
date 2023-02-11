// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AboutScreen.h"
#include "UserWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CastleNestInstance.h"
#include "ClassicFunctionLibrary.generated.h"

UENUM()
enum class ETrueFalseEnum : uint8
{
	TrueSwitch,
	FalseSwitch
};

/**
 * 
 */
UCLASS()
class OIZO_API UClassicFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	
public: 

	UFUNCTION(BlueprintCallable)
		static UCastleNestInstance* GetCastleNestInstance();
	UFUNCTION(BlueprintCallable, Meta = (ExpandEnumAsExecs = "Branches"))
		static void ReadSwitch(FString switchID, ETrueFalseEnum & Branches);

};
