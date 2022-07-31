// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Static.h"
#include "KinematicMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AI_EXPERIMENTS_API UKinematicMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UKinematicMovementComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FStatic Character;
	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite)
	FVector Target = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxSpeed = 200.f;

	virtual KinematicSteeringOutput GetSteering();

};
