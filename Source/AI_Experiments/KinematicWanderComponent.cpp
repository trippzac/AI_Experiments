// Fill out your copyright notice in the Description page of Project Settings.


#include "KinematicWanderComponent.h"
#include "KinematicSteeringOutput.h"

// Sets default values for this component's properties
UKinematicWanderComponent::UKinematicWanderComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

KinematicSteeringOutput UKinematicWanderComponent::GetSteering()
{
	KinematicSteeringOutput Result = KinematicSteeringOutput();

	Result.Velocity = FRotator(0, Character.Orientation, 0).Vector();
	Result.Velocity.Normalize();
	Result.Velocity *= MaxSpeed;

	Result.Rotation = RandomBinomial() * MaxRotation;

	return Result;
}
