// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "BulletSponge/Weapons/GunBase.h"
#include "Components/CapsuleComponent.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Gun = GetWorld()->SpawnActor<AGunBase>(GunClass);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform);
	Gun->SetOwner(this);
	Health = MaxHealth;
	Ammo = StartAmmo;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveFwdBwd"), this, &APlayerCharacter::MoveFwdBwd);
	PlayerInputComponent->BindAxis(TEXT("MoveSideways"), this, &APlayerCharacter::MoveSideways);
	PlayerInputComponent->BindAxis(TEXT("LookUpDown"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookSideways"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUpDownRate"), this, &APlayerCharacter::LookUpDownRate);
	PlayerInputComponent->BindAxis(TEXT("LookSidewaysRate"), this, &APlayerCharacter::LookSidewaysRate);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &APlayerCharacter::PullTrigger);
}

//MovementFunctions
void APlayerCharacter::MoveFwdBwd(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void APlayerCharacter::MoveSideways(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void APlayerCharacter::LookUpDownRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::LookSidewaysRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::PullTrigger()
{
	if (Ammo > 0.0f)
	{
		Ammo--;
		Gun->PullTrigger();
	}
	UE_LOG(LogTemp, Warning, TEXT("Ammo is %f"), Ammo);
}

float APlayerCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	//UE_LOG(LogTemp, Error, TEXT("Player taking damage!!"));
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (Ammo < MaxAmmo)
	{
		Ammo += DamageToApply;
		DamageToApply = 0.0f;
		return DamageToApply;
	}
	else
	{
		DamageToApply = DamageToApply * DamageTakenMultiplier; // will need to remove magic number for damage scale to be editable
		
		if (DamageToApply > Health)
			DamageToApply = Health;

		Health -= DamageToApply;
		//UE_LOG(LogTemp, Warning, TEXT("Player Health is %f"), Health);

		//add check if dead

		return DamageToApply;
	}
}