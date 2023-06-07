// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TurretBase.generated.h"

/**
 * 
 */
UCLASS()
class VRTOWERDEFENSE_API UTurretBase : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly)
	float CriticalChances;

	UPROPERTY(BlueprintReadOnly)
	float RotationSpeed;

	UPROPERTY(BlueprintReadOnly)
	float Accuracy;

	UPROPERTY(BlueprintReadOnly)
	float Health;
};
