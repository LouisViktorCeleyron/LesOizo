// Fill out your copyright notice in the Description page of Project Settings.


#include "ClassicFunctionLibrary.h"
#include "Engine.h"
#include "SubclassOf.h"
#include "UObject/Class.h"
#include "UObjectIterator.h"
#include "Kismet/GameplayStatics.h"

UCastleNestInstance* UClassicFunctionLibrary::GetCastleNestInstance()
{
	return Cast<UCastleNestInstance>(UGameplayStatics::GetGameInstance(UGameplayStatics::GetPlayerController(GEngine->GameViewport->GetWorld(), 0)));
}
