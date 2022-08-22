// Fill out your copyright notice in the Description page of Project Settings.


#include "UObjectIterator.h"
#include "WidgetInventaireParent.h"

void UWidgetInventaireParent::DestroyStudioBP()
{
	if(StudioBP!=nullptr )
	{
		StudioBP->Destroy();
	}
}

void UWidgetInventaireParent::RemoveFromParent()
{
	DestroyStudioBP();
	UCastlenestBaseUserWidget::RemoveFromParent();
}

