// Fill out your copyright notice in the Description page of Project Settings.

#include "KinematicSeekComponent.h"
#include "KinematicSteeringOutput.h"

// Sets default values for this component's properties
UKinematicSeekComponent::UKinematicSeekComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

KinematicSteeringOutput UKinematicSeekComponent::GetSteering()
{
	KinematicSteeringOutput Result = KinematicSteeringOutput();

	Result.Velocity = Target - Character.Position;
	Result.Velocity.Normalize();
	Result.Velocity *= MaxSpeed;

	return Result;
}
