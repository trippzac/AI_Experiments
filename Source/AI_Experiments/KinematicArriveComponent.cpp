// Fill out your copyright notice in the Description page of Project Settings.

#include "KinematicArriveComponent.h"
#include "KinematicSteeringOutput.h"

// Sets default values for this component's properties
UKinematicArriveComponent::UKinematicArriveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

KinematicSteeringOutput UKinematicArriveComponent::GetSteering()
{

	KinematicSteeringOutput Result = KinematicSteeringOutput();

	Result.Velocity = Target - Character.Position;
	if (Result.Velocity.Size() < Radius)
	{
		return KinematicSteeringOutput();
	}

	Result.Velocity /= TimeToTarget;
	if (Result.Velocity.Size() > MaxSpeed)
	{
		Result.Velocity.Normalize();
		Result.Velocity *= MaxSpeed;
	}

	return Result;
}
