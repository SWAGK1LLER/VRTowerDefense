// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "VRHands.generated.h"

/**
 * 
 */
UCLASS()
class VRTOWERDEFENSE_API UVRHands : public USkeletalMeshComponent
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		bool Mirror;
};
