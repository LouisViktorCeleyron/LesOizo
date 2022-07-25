// Fill out your copyright notice in the Description page of Project Settings.


#include "CastlenestBaseUserWidget.h"

 void UCastlenestBaseUserWidget::RemoveFromParent()
 {
 	CalledOnRemove.Broadcast();
 	UUserWidget::RemoveFromParent();
 }
