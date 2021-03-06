// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BulletSponge/AI/EnemyCharacter.h"

void ABasicAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);

		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}

//Unsure if this is actually needed for this as will be using behavior trees
//instead of having a AI functionality placed in tick function
void ABasicAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

bool ABasicAIController::IsDead() const
{
	AEnemyCharacter* ControlledCharacter = Cast<AEnemyCharacter>(GetPawn());
	if (ControlledCharacter != nullptr)
		return ControlledCharacter->IsDead();

	return true;
}