// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TileComponent.generated.h"

/**
 * 
 */
UCLASS()
class VRTOWERDEFENSE_API UTileComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UStaticMesh* _static_mesh;

	UTileComponent();
};
