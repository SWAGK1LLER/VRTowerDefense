// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TurretCanon.generated.h"

/**
 * 
 */
UCLASS()
class VRTOWERDEFENSE_API UTurretCanon : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	float CriticalMultiplier;

	UPROPERTY(BlueprintReadOnly)
	float RateOfFire;

	UPROPERTY(BlueprintReadOnly)
	float AngleOfFire;

	UPROPERTY(BlueprintReadOnly)
	float Range;

	UPROPERTY(BlueprintReadOnly)
	float ProjectileSpeed;
	
};
