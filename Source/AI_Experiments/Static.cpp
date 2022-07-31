// Fill out your copyright notice in the Description page of Project Settings.


#include "Static.h"
#include "KinematicSteeringOutput.h"

// Sets default values for this component's properties
FStatic::FStatic()
{
	Position = FVector::ZeroVector;
	Orientation = 0.f;
}

FStatic::FStatic(FVector StartPosition, float StartOrientation)
{
	Position = StartPosition;
	Orientation = StartOrientation;
}

void FStatic::Update(KinematicSteeringOutput KinematicSteering, float time)
{
	Position += KinematicSteering.Velocity * time;
	// Check if orientation is determined by rotation or by facing direction of velocity
	if (KinematicSteering.Rotation != 0)
	{
		Orientation += KinematicSteering.Rotation * time;
	}
	else
	{
		Orientation = NewOrientation(Orientation, KinematicSteering);
	}
}

float FStatic::NewOrientation(float Current, KinematicSteeringOutput KinematicSteering)
{
	if (KinematicSteering.Velocity.Size() > 0)
	{
		return 180*atan2(KinematicSteering.Velocity.Y, KinematicSteering.Velocity.X)/PI;
	}
	else
	{
		return Current;
	}
}