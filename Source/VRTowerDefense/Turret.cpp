// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "TurretBase.h"
#include "TurretCore.h"
#include "TurretCanon.h"
#include "TurretCores/CryoCore.h"
#include "TurretCores/LeadCore.h"
#include "TurretCores/PyroCore.h"
#include "TurretCores/PlasmaCore.h"
#include "TurretCores/RadioactiveCore.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ATurret::ATurret()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ATurret::AsignNewCore(TSubclassOf<UTurretCore> NewCoreClass, EAmmoType NewCore)
{
	FTransform newTransform;
	newTransform.SetRotation(FQuat(0,0,0,0));
	newTransform.SetTranslation(FVector(0, 0, 0));
	newTransform.SetScale3D(FVector(1, 1, 1));
	switch (NewCore)
	{
	case EAmmoType::EAT_Cryo : Core = Cast<UCryoCore>(AddComponentByClass(NewCoreClass, false, newTransform, false));
		Core->SetupAttachment(RootComponent);
		break;
	case EAmmoType::EAT_Lead: Core = Cast<ULeadCore>(AddComponentByClass(NewCoreClass, false, newTransform, false));
		Core->SetupAttachment(RootComponent);
		break;
	case EAmmoType::EAT_Plasma: Core = Cast<UPlasmaCore>(AddComponentByClass(NewCoreClass, false, newTransform, false));
		Core->SetupAttachment(RootComponent);
		break;
	case EAmmoType::EAT_Pyro: Core = Cast<UPyroCore>(AddComponentByClass(NewCoreClass, false, newTransform, false));
		Core->SetupAttachment(RootComponent);
		break;
	case EAmmoType::EAT_Radioactive: Core = Cast<URadioactiveCore>(AddComponentByClass(NewCoreClass, false, newTransform, false));
		Core->SetupAttachment(RootComponent);
		break;
	}
	
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

