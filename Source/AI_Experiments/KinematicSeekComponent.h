// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KinematicMovementComponent.h"
#include "KinematicSeekComponent.generated.h"

class KinematicSteeringOutput;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AI_EXPERIMENTS_API UKinematicSeekComponent : public UKinematicMovementComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UKinematicSeekComponent();

protected:

	KinematicSteeringOutput GetSteering() override;

};
