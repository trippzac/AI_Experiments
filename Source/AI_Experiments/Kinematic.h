// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"

class AI_EXPERIMENTS_API FKinematic
{

public:	
	// Sets default values for this component's properties
	FKinematic();
	FKinematic(FVector StartPosition, float StartOrientation);

	void Update(class SteeringOutput Steering, float MaxSpeed, float time);

	// Base data members
	FVector Position;
	float Orientation;
	FVector Velocity;
	float Rotation;
		
};
