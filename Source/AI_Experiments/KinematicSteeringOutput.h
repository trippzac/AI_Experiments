// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"

class AI_EXPERIMENTS_API KinematicSteeringOutput
{
public:
	KinematicSteeringOutput();
	~KinematicSteeringOutput();

	FVector Velocity;
	float Rotation;
};
