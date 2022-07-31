// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMovementComponent.h"
#include "SteeringOutput.h"

// Sets default values for this component's properties
UBaseMovementComponent::UBaseMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UBaseMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
	{
		Character = FKinematic(GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation().Yaw);
	}
	else
	{
		Character = FKinematic();
	}
	
}

SteeringOutput UBaseMovementComponent::GetSteering()
{
	return SteeringOutput();
}


// Called every frame
void UBaseMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Character.Update(GetSteering(), MaxSpeed, DeltaTime);

	if (GetOwner())
	{
		GetOwner()->SetActorLocation(Character.Position);
		GetOwner()->SetActorRotation(FRotator(0, Character.Orientation, 0));
	}
}

