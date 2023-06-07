// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../TurretCore.h"
#include "PyroCore.generated.h"

/**
 * 
 */
UCLASS()
class VRTOWERDEFENSE_API UPyroCore : public UTurretCore
{
	GENERATED_BODY()

public:

	UPyroCore();

	UPROPERTY(BlueprintReadOnly)
	float DamageOverTimeOnGround = 1;
};
