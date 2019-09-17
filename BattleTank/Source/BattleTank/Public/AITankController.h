// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "AITankController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API AAITankController : public AAIController
{
	GENERATED_BODY()

public: 
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	float AcceptanceRadius = 3000.f;

};
