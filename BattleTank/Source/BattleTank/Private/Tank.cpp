// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankAimComponent.h"
#include "..\Public\Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimComponent = CreateDefaultSubobject<UTankAimComponent>(FName ("Aim Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}



void ATank::SetBarrelRef(UTankBarrel* BarrelToSet) 
{
	TankAimComponent->SetBarrelRef(BarrelToSet);
}

void ATank::SetTurretRef(UTankTurret* TurretToSet)
{
	TankAimComponent->SetTurretRef(TurretToSet);
}

void ATank::Fire()
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Tank Fires"), Time);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{	
	TankAimComponent->AimAt(HitLocation, LaunchSpeed);
	
}