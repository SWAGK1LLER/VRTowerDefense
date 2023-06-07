// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../TurretCore.h"
#include "PlasmaCore.generated.h"

/**
 * 
 */
UCLASS()
class VRTOWERDEFENSE_API UPlasmaCore : public UTurretCore
{
	GENERATED_BODY()
	
public:
	
	UPlasmaCore();

	UPROPERTY(BlueprintReadOnly)
	float ArcSize = 3;
};
