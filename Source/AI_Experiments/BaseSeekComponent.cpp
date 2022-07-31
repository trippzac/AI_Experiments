// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSeekComponent.h"
#include "SteeringOutput.h"

SteeringOutput UBaseSeekComponent::GetSteering()
{
	SteeringOutput Result = SteeringOutput();

	// Accelerate in the direction of the target
	Result.Linear = Target.Position - Character.Position;
	// Accelerate at MaxAcceleration
	Result.Linear.Normalize();
	Result.Linear *= MaxAcceleration;

	Result.Angular = 0.f;

	return Result;
}
