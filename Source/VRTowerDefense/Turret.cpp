// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "TurretBase.h"
#include "TurretCore.h"
#include "TurretCanon.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Base = CreateDefaultSubobject<UTurretBase>(TEXT("TurretBase"));
	Core = CreateDefaultSubobject<UTurretCore>(TEXT("TurretCore"));
	Canon = CreateDefaultSubobject<UTurretCanon>(TEXT("TurretCanon"));
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

