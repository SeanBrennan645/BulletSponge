// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletSpongePlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void ABulletSpongePlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);
	if (HUD != nullptr)
		HUD->AddToViewport();
}