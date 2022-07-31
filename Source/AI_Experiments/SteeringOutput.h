// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class AI_EXPERIMENTS_API SteeringOutput
{
public:
	SteeringOutput();
	~SteeringOutput();

	FVector Linear;
	float Angular;
};
