// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class BULLETSPONGE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void MoveFwdBwd(float AxisValue);
	void MoveSideways(float AxisValue);
	void LookUpDownRate(float AxisValue);
	void LookSidewaysRate(float AxisValue);

	UPROPERTY(EditAnywhere)
		float RotationRate = 40.0f;
	

};
