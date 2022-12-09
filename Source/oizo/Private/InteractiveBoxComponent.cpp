// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveBoxComponent.h"

void UInteractiveBoxComponent::BeginPlay()
{
	UBoxComponent::BeginPlay();
	OnComponentBeginOverlap.AddUniqueDynamic(this, &UInteractiveBoxComponent::OnStartInteractiveOverlapped);
	OnComponentEndOverlap.AddUniqueDynamic(this, &UInteractiveBoxComponent::OnEndInteractiveOverlapped);
	
}

void UInteractiveBoxComponent::OnStartInteractiveOverlapped_Implementation(UPrimitiveComponent* overlappedComp, AActor* other, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{

}

void UInteractiveBoxComponent::OnEndInteractiveOverlapped_Implementation(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{

}
