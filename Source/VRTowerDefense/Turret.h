// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turret.generated.h"

//Forward Declare
class UTurretCore;
class UTurretBase;
class UTurretCanon;

UCLASS()
class VRTOWERDEFENSE_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

	UPROPERTY(BlueprintReadWrite)
	UTurretBase* Base;

	UPROPERTY(BlueprintReadWrite)
	UTurretCore* Core;

	UPROPERTY(BlueprintReadWrite)
	UTurretCanon* Canon;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
