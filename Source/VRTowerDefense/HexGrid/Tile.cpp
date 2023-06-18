// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_root_component = CreateDefaultSubobject<USceneComponent>("Root");
	this->SetRootComponent(_root_component);

	_hexagone = CreateDefaultSubobject<UStaticMeshComponent>("Hexagone");
	_hexagone->SetupAttachment(_root_component);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Mesh/Hexagone.Hexagone'"));
	UStaticMesh* asset = MeshAsset.Object;

	_hexagone->SetStaticMesh(asset);
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

