// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"

class AI_EXPERIMENTS_API FStatic
{

public:	
	// Sets default values for this component's properties
	FStatic();
	FStatic(FVector StartPosition, float StartOrientation);

	void Update(class KinematicSteeringOutput KinematicSteering, float time);

	FVector Position;
	float Orientation;

protected:
	float NewOrientation(float Current, class KinematicSteeringOutput KinematicSteering);

};
