// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemAsset.h"


#include "CastlenestPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"


void UItemAsset::Action()
{
}

void UItemChapoAsset::Action()
{
	auto _controller = UGameplayStatics::GetPlayerController(GetWorld(),0);
	auto _state = Cast<ACastlenestPlayerState>(_controller->PlayerState);

	_state->ChangeChapo(this);
	
}
