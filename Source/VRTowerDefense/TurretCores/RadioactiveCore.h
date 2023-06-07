// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../TurretCore.h"
#include "RadioactiveCore.generated.h"

/**
 * 
 */
UCLASS()
class VRTOWERDEFENSE_API URadioactiveCore : public UTurretCore
{
	GENERATED_BODY()
	
public:

	URadioactiveCore();

	UPROPERTY(BlueprintReadOnly)
	float DamageOverTime = 1;
};
