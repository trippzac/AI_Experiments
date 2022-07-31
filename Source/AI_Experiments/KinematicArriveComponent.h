// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KinematicMovementComponent.h"
#include "KinematicArriveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AI_EXPERIMENTS_API UKinematicArriveComponent : public UKinematicMovementComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UKinematicArriveComponent();

protected:

	// Satisfaction radius
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Radius = 10.f;
	// Time to target constant
	UPROPERTY(EditAnywhere, Category = "Movement")
	float TimeToTarget = 0.25f;

	KinematicSteeringOutput GetSteering() override;

};
