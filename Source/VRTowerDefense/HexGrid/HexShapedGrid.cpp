// Fill out your copyright notice in the Description page of Project Settings.


#include "HexShapedGrid.h"
#include "TileComponent.h"

// Sets default values
AHexShapedGrid::AHexShapedGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_rootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	this->SetRootComponent(_rootComponent);
}

// Called when the game starts or when spawned
void AHexShapedGrid::BeginPlay()
{
	Super::BeginPlay();

	_gridCoord.Add(_gridCenter);

	for (int q = -_gridRange; q <= _gridRange; ++q)
	{
		int min = FMath::Max(-_gridRange, -q - _gridRange);
		int max = FMath::Min(_gridRange, -q + _gridRange);
		
		for (int r = min; r <= max; ++r)
			_gridCoord.Add(FHex::HexAdd(_gridCenter, FHex(q, r)));
	}
}

// Called every frame
void AHexShapedGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#pragma region FHex
const TArray<FHex> FHex::_axialDirections = {
		   FHex(1, 0), FHex(1, -1), FHex(0, -1),
		   FHex(-1, 0), FHex(-1, 1), FHex(0, 1),
};

FHex::FHex()
	: _q(0), _r(0), _s(0)
{
}
FHex::FHex(int q, int r)
	: _q(q), _r(r), _s(-q - r)
{
}

FHex::FHex(const FHex& other)
	: _q(other._q), _r(other._r), _s(other._s)
{
}

FHex FHex::HexAdd(const FHex& a, const FHex& b)
{
	return FHex(a._q + b._q, a._r + b._r);
}

FHex FHex::HexSubstract(const FHex& a, const FHex& b)
{
	return FHex(a._q - b._q, a._r - b._r);
}

FHex FHex::HexMultiply(const FHex& a, int k)
{
	return FHex(a._q * k, a._r * k);
}

int FHex::HexLength(const FHex& a)
{
	return int((FMath::Abs(a._q) + FMath::Abs(a._r) + FMath::Abs(a._s)) / 2);
}

int FHex::HexDistance(const FHex& a, const FHex& b)
{
	FHex sub(HexSubstract(a, b));
	return HexLength(sub);
}

FHex FHex::Direction(int dir)
{
	if (dir < 0 || 5 < dir)
		dir = dir % 5;

	return _axialDirections[dir];
}

FHex FHex::HexNeighbour(const FHex& a, int dir)
{
	return HexAdd(a, Direction(dir));
}

TArray<FHex> FHex::HexNeighbours(const FHex& a)
{
	TArray<FHex> tmp;

	for (int i = 0; i < _axialDirections.Num(); ++i)
		tmp.Add(HexAdd(a, _axialDirections[i]));

	return tmp;
}
#pragma endregion