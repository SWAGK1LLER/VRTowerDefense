// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../TurretCore.h"
#include "CryoCore.generated.h"

/**
 * 
 */
UCLASS()
class VRTOWERDEFENSE_API UCryoCore : public UTurretCore
{
	GENERATED_BODY()
	
public:
	UCryoCore();

	UPROPERTY(BlueprintReadOnly)
	float SlowRate = 10;
};
