// Fill out your copyright notice in the Description page of Project Settings.


#include "Kinematic.h"
#include "SteeringOutput.h"

// Sets default values for this component's properties
FKinematic::FKinematic()
{
	Position = FVector::ZeroVector;
	Orientation = 0.f;

	Velocity = FVector::ZeroVector;
	Rotation = 0.f;
}

FKinematic::FKinematic(FVector StartPosition, float StartOrientation)
{
	Position = StartPosition;
	Orientation = StartOrientation;

	Velocity = FVector::ZeroVector;
	Rotation = 0.f;
}


void FKinematic::Update(SteeringOutput Steering, float MaxSpeed, float time)
{
	// Update position and orientation using Newton-Euler
	Position += Velocity * time;
	Orientation += Rotation * time;

	// Update velocity and rotation
	Velocity += Steering.Linear * time;
	Rotation += Steering.Angular * time;

	if (Velocity.Size() > MaxSpeed)
	{
		Velocity.Normalize();
		Velocity *= MaxSpeed;
	}
}
