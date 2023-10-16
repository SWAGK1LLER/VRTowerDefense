// Fill out your copyright notice in the Description page of Project Settings.


#include "TileComponent.h"

UTileComponent::UTileComponent()
{
}

bool UTileComponent::SetStaticMesh(UStaticMesh* NewMesh)
{
	_staticMesh = NewMesh;

	return UStaticMeshComponent::SetStaticMesh(NewMesh);
}