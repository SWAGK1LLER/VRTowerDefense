// Fill out your copyright notice in the Description page of Project Settings.


#include "HexGrid.h"
#include "Components/ChildActorComponent.h"
#include "TileComponent.h"

// Sets default values
AHexGrid::AHexGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_root_component = CreateDefaultSubobject<USceneComponent>("Root");
	this->SetRootComponent(_root_component);

	//for (int i = 0; i < _width; ++i)
	//{
	//	std::vector<UTileComponent*> row;

	//	for (int j = 0; j < _height; ++j)
	//	{
	//		FName name = *FString::Printf(TEXT("Tile_%d_%d"), i, j);

	//		UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//			UTileComponent* tile = CreateDefaultSubobject<UTileComponent>(name);

	//		tile->SetupAttachment(_root_component);

	//		row.push_back(tile);
	//	}

	//	_grid.push_back(row);
	//}
}

// Called when the game starts or when spawned
void AHexGrid::BeginPlay()
{
	Super::BeginPlay();

	FVector newScale(_scale, _scale, 1);

	_radius =  _mesh_of_tile->GetBoundingBox().Max.X * _scale;

	float rowOffset = _radius * -1;;
	bool isA = false;

	//create colomn
	for (int i = 0; i < _width; ++i)
	{
		TArray<UTileComponent*> row;

		float innerRadius = (_radius * 2 / sqrt(3)) * 1.5;

		FVector location;
		location.Y = i * innerRadius + _offset * i;

		//create row
		for (int j = 0; j < _height; ++j)
		{
			FName name = *FString::Printf(TEXT("Tile_%d_%d"), i, j);
			
			UTileComponent* tile = NewObject<UTileComponent>(this, name);
			tile->RegisterComponent();
			this->AddInstanceComponent(tile);

			tile->SetStaticMesh(_mesh_of_tile);
			tile->AttachToComponent(
				_root_component, FAttachmentTransformRules::SnapToTargetIncludingScale);

			location.X = j * _radius * 2 + _offset * j + rowOffset;

			tile->SetRelativeLocation(location);
			tile->SetRelativeScale3D(newScale);

			row.Add(tile);
		}

		if (isA)
		{
			rowOffset = _radius * -1;
			isA = false;
		}
		else
		{
			rowOffset = 0;
			isA = true;
		}

		FGridRow newRow;
		newRow._row = row;
		_grid.Add(newRow);
	}
}

// Called every frame
void AHexGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

