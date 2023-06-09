// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turret.generated.h"

//Forward Declarations
class UTurretCore;
class UTurretBase;
class UTurretCanon;
enum class EAmmoType : uint8;

UCLASS()
class VRTOWERDEFENSE_API ATurret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurret();

	UPROPERTY(BlueprintReadOnly)
	UTurretBase* Base;

	UPROPERTY(BlueprintReadOnly)
	UTurretCore* Core;

	UPROPERTY(BlueprintReadOnly)
	UTurretCanon* Canon;

	UFUNCTION(BlueprintCallable)
	void AsignNewCore(TSubclassOf<UTurretCore> NewCoreClass, EAmmoType NewCore);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
