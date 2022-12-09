// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "InteractiveBoxComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class OIZO_API UInteractiveBoxComponent : public UBoxComponent
{
	GENERATED_BODY()
private :
	virtual void BeginPlay() override;
public :
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnStartInteractiveOverlapped(UPrimitiveComponent* overlappedComp, AActor* other, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);
	void OnStartInteractiveOverlapped_Implementation(UPrimitiveComponent* overlappedComp, AActor* other, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnEndInteractiveOverlapped(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex);
	void OnEndInteractiveOverlapped_Implementation(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex);

};
