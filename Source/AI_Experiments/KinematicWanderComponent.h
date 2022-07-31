// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KinematicMovementComponent.h"
#include "KinematicWanderComponent.generated.h"

UCLASS()
class AI_EXPERIMENTS_API UKinematicWanderComponent : public UKinematicMovementComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UKinematicWanderComponent();

protected:

	KinematicSteeringOutput GetSteering() override;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxRotation = 90.f;

	float RandomBinomial() {
		return (FMath::FRandRange(0, 1) - FMath::FRandRange(0, 1));
	}
};
