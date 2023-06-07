// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TurretCore.generated.h"

UENUM(BlueprintType)
enum class EAmmoType : uint8
{
	EAT_Pyro UMETA(DisplayName = "Pyro"),
	EAT_Cryo UMETA(DisplayName = "Cryo"),
	EAT_Lead UMETA(DisplayName = "Lead"),
	EAT_Radioactive UMETA(DisplayName = "Radioactive"),
	EAT_Plasma UMETA(DisplayName = "Plasma")
};

/**
 * 
 */
UCLASS()
class VRTOWERDEFENSE_API UTurretCore : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly)
	EAmmoType Ammo;

	UPROPERTY(BlueprintReadOnly)
	float Damage;
};
