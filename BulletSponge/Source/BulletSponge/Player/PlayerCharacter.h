// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class AGunBase;

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

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	void PullTrigger();

	UFUNCTION(BlueprintPure)
		bool IsDead() const;

	UFUNCTION(BlueprintPure)
		float GetHealthPercent() const;

	UFUNCTION(BlueprintPure)
		float GetAmmoPercent() const;

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
	UPROPERTY(EditDefaultsOnly)
		float MaxHealth = 100.0f;
	UPROPERTY(EditDefaultsOnly)
		float MaxAmmo = 10.0f;
	UPROPERTY(EditDefaultsOnly)
		float DamageTakenMultiplier = 10.0f;

	UPROPERTY(VisibleAnywhere)
		float Health;
	UPROPERTY(VisibleAnywhere)
		float Ammo;
	UPROPERTY(VisibleAnywhere)
		float StartAmmo = 3.0f;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AGunBase> GunClass;

	UPROPERTY()
		AGunBase* Gun;

};
