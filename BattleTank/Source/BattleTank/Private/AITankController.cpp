// Fill out your copyright notice in the Description page of Project Settings.


#include "AITankController.h"
#include "Tank.h"

void AAITankController::BeginPlay()
{
	Super::BeginPlay();

}

void AAITankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// TODO Move at player
		MoveToActor(PlayerTank, AcceptanceRadius);
		// Aim towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire();
	}
}


