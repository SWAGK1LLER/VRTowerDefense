// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexGrid.generated.h"

class UTileComponent;

USTRUCT(BlueprintType)
struct FGridRow
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Grid")
		TArray<UTileComponent*> _row;
};

UCLASS()
class VRTOWERDEFENSE_API AHexGrid : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AHexGrid();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Root")
		USceneComponent* _root_component = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
		UStaticMesh* _mesh_of_tile;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Grid")
		TArray<FGridRow> _grid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid Option")
		int _width = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Option")
		int _height = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Option")
		float _offset = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Grid Option")
		float _radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Option")
		float _scale = 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
