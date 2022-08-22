// Fill out your copyright notice in the Description page of Project Settings.


#include "CastlenestPlayerController.h"
#include "Engine/Engine.h"
#include "UserWidget.h"


void ACastlenestPlayerController::BeginPlay()
{
	auto _this = this;
	
	// FString t = FString(IsValid(this)?"C'est ok":"C'est pas ok"); //Message
	// GEngine->AddOnScreenDebugMessage(FMath::Rand(),10,FColor::Red,t); //Print to Screen
	// UE_LOG(LogTemp,Warning,TEXT("%s"), *t); //PrintToLog

	widgetInventory = CreateWidget<UWidgetInventaireParent>(_this,widgetInventoryClass);
	SetActorTickEnabled(true);
	Super::BeginPlay();	
}

void ACastlenestPlayerController::AddInventoryToViewPort()
{
	const auto _capture3DObject = GetWorld()->SpawnActor<ACapture3DObject>(captureObjectClass,FVector(1000,1000,1000),FRotator(0,0,0));
	
	if(IsValid(widgetInventory))
	{
		widgetInventory->AddToViewport();
		widgetInventory->StudioBP = _capture3DObject;
	}
}

void ACastlenestPlayerController::RemoveInventoryFromViewPort()
{
	if(IsValid(widgetInventory))
	{
		widgetInventory->RemoveFromParent();
		for (UWidgetInventaireParent* widget : AllChildren)
		{
			widget->RemoveFromParent();
		}
	}
}





