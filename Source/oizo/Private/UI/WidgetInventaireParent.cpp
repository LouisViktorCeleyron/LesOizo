// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetInventaireParent.h"
#include "UObjectIterator.h"

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

