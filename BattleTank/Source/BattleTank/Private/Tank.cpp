// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimComponent.h"
#include "TankMovementComponent.h"
#include "..\Public\Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Donkey: Tank C++ Construct"), *TankName);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Donkey: Tank C++ Begin Play"), *TankName);
}


void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastTimeFired) > ReloadTimeInSeconds;
	
	if (Barrel && isReloaded)
	{

		auto Projectile = GetWorld()->SpawnActor<AProjectile>
			(ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("Projectile")),
				Barrel->GetSocketRotation(FName("Projectile"))
				);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastTimeFired = FPlatformTime::Seconds();
	}
}


void ATank::AimAt(FVector HitLocation)
{	
	if (!TankAimComponent) { return; }
	TankAimComponent->AimAt(HitLocation, LaunchSpeed);
	
}