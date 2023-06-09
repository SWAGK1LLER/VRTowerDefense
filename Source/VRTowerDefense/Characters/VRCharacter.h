// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStaticsTypes.h"
#include "VRCharacter.generated.h"

//Forward Declarations
class UInputMappingContext;
class UCameraComponent;
class UWidgetInteractionComponent;
class UMotionControllerComponent;
class UNiagaraComponent;
class UVRHands;
class UInputAction;

UCLASS()
class VRTOWERDEFENSE_API AVRCharacter : public APawn
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionControllerLeft;

	UPROPERTY(VisibleAnywhere)
	UVRHands* LeftVRHand;

	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionControllerRight;

	UPROPERTY(VisibleAnywhere)
	UVRHands* RightVRHand;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CameraMesh;

	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionControllerLeftAim;

	UPROPERTY(VisibleAnywhere)
	UWidgetInteractionComponent* WidgetInteractionLeft;

	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionControllerRightAim;

	UPROPERTY(VisibleAnywhere)
	UWidgetInteractionComponent* WidgetInteractionRight;

	UPROPERTY(VisibleAnywhere)
	UNiagaraComponent* TeleportTraceNiagaraSystem;

	AVRCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		UInputMappingContext* PlayerMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		UInputMappingContext* HandsMapping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		UInputAction* TeleportAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float TeleportLauchSpeed = 650.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float TeleportProjectileRadius = 3.6f;

	void TeleportTrace(const FInputActionValue& Value);

protected: 

	virtual void BeginPlay() override;

private:

	TArray<FPredictProjectilePathPointData> TeleportTracePathPositions;
};
