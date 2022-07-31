// Fill out your copyright notice in the Description page of Project Settings.


#include "KinematicMovementComponent.h"
#include "KinematicSteeringOutput.h"

// Sets default values for this component's properties
UKinematicMovementComponent::UKinematicMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UKinematicMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
	{
		Character = FStatic(GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation().Yaw);
	}
	else
	{
		Character = FStatic();
	}
	
}

KinematicSteeringOutput UKinematicMovementComponent::GetSteering()
{
	return KinematicSteeringOutput();
}


// Called every frame
void UKinematicMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Character.Update(GetSteering(), DeltaTime);

	if (GetOwner())
	{
		GetOwner()->SetActorLocation(Character.Position);
		GetOwner()->SetActorRotation(FRotator(0, Character.Orientation, 0));
	}
}

