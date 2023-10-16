// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexShapedGrid.generated.h"

//https://www.redblobgames.com/grids/hexagons/implementation.html

USTRUCT(BlueprintType)
struct VRTOWERDEFENSE_API FHex
{
	GENERATED_BODY()

	//Cube storage, axial constructor
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid")
	int _q = 0;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid")
	int _r = 0;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid")
	int _s = 0;

	//  (r)-1
	//	     / \
	// -1 <- | | -> +1 (q)
	//		 \ / +1

	FHex();

	FHex(int q, int r);

	//Copy constructor
	FHex(const FHex& other);

	//copy assignement
	FHex& operator=(const FHex& other)
	{
		_q = other._q;
		_r = other._r;
		_s = other._s;
		return *this;
	}

	bool operator== (const FHex& b) const
	{
		return this->_q == b._q && this->_r == b._r && this->_s == b._s;
	}

	bool operator!= (const FHex& b)
	{
		return !(*this == b);
	}

	static FHex HexAdd(const FHex& a, const FHex& b);

	static FHex HexSubstract(const FHex& a, const FHex& b);

	static FHex HexMultiply(const FHex& a, int k);

	static int HexLength(const FHex& a);

	static int HexDistance(const FHex& a, const FHex& b);

	/* min=0, max=5 */
	static FHex Direction(int dir);

	static FHex HexNeighbour(const FHex& a, int dir);

	static TArray<FHex> HexNeighbours(const FHex& a);

	static const TArray<FHex> _axialDirections;
};

FORCEINLINE uint32 GetTypeHash(const FHex& other)
{
	return FCrc::MemCrc32(&other, sizeof(FHex));
}

UCLASS()
class VRTOWERDEFENSE_API AHexShapedGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHexShapedGrid();



	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Root")
	USceneComponent* _rootComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile")
	UStaticMesh* _basicMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid")
	FHex _gridCenter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid")
	TSet<FHex> _gridCoord;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid Option")
	int _gridRange = 5;

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