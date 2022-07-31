// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseMovementComponent.h"
#include "BaseSeekComponent.generated.h"

/**
 * 
 */
UCLASS()
class AI_EXPERIMENTS_API UBaseSeekComponent : public UBaseMovementComponent
{
	GENERATED_BODY()

protected:

	SteeringOutput GetSteering() override;
	
};
