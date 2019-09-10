// Fill out your copyright notice in the Description page of Project Settings.


#include "AITankController.h"

void AAITankController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}
}

void AAITankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move at player

		// Aim towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* AAITankController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* AAITankController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

