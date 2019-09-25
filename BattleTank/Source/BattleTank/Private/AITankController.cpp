// Fill out your copyright notice in the Description page of Project Settings.


#include "AITankController.h"
#include "BattleTank.h"
#include "TankAimComponent.h"

void AAITankController::BeginPlay()
{
	Super::BeginPlay();

}

void AAITankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
		// TODO Move at player
		MoveToActor(PlayerTank, AcceptanceRadius);
		// Aim towards player
		auto AimComponent = ControlledTank->FindComponentByClass<UTankAimComponent>();
		AimComponent->AimAt(PlayerTank->GetActorLocation());
		
		AimComponent->Fire();
	
}


