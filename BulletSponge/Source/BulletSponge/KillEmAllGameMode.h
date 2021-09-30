// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BulletSpongeGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BULLETSPONGE_API AKillEmAllGameMode : public ABulletSpongeGameModeBase
{
	GENERATED_BODY()
public:
	void PawnKilled(APawn* PawnKilled);

private:
	void EndGame(bool bIsPlayerWinner);
	
};
