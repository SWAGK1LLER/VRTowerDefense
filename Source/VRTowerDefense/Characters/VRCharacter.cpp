// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"
#include <HeadMountedDisplayFunctionLibrary.h>
#include <Kismet/KismetSystemLibrary.h>
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "NiagaraComponent.h"
#include "VRHands.h"
#include <EnhancedInputComponent.h>

// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MotionControllerLeft = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionControllerLeft"));
	MotionControllerLeft->SetupAttachment(RootComponent);
	LeftVRHand = CreateDefaultSubobject<UVRHands>(TEXT("LeftVRHand"));
	LeftVRHand->SetupAttachment(MotionControllerLeft);

	MotionControllerRight = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionControllerRight"));
	MotionControllerRight->SetupAttachment(RootComponent);
	RightVRHand = CreateDefaultSubobject<UVRHands>(TEXT("RightVRHand"));
	RightVRHand->SetupAttachment(MotionControllerRight);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	CameraMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CameraMesh"));
	CameraMesh->SetupAttachment(Camera);

	MotionControllerLeftAim = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionControllerLeftAim"));
	MotionControllerLeftAim->SetupAttachment(RootComponent);
	WidgetInteractionLeft = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteractionLeft"));
	WidgetInteractionLeft->SetupAttachment(MotionControllerLeftAim);

	MotionControllerRightAim = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionControllerRightAim"));
	MotionControllerRightAim->SetupAttachment(RootComponent);
	WidgetInteractionRight = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteractionRight"));
	WidgetInteractionRight->SetupAttachment(MotionControllerRightAim);

	TeleportTraceNiagaraSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("TeleportTraceNiagaraSystem"));
	TeleportTraceNiagaraSystem->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Stage);
		UKismetSystemLibrary::ExecuteConsoleCommand(this, "vr.PixelDensity 1.0");
		if (auto PlayerController = Cast<APlayerController>(GetController()))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(PlayerMapping, 0);
				Subsystem->AddMappingContext(HandsMapping, 0);
			}
		}
	}

}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(TeleportAction, ETriggerEvent::Triggered, this, &AVRCharacter::TeleportTrace);
	}
}

void AVRCharacter::TeleportTrace(const FInputActionValue& Value)
{
	FPredictProjectilePathParams ProjectilePathParams;
	FPredictProjectilePathResult ProjectilePathResult;
	ProjectilePathParams.StartLocation = MotionControllerRightAim->GetComponentLocation();
	ProjectilePathParams.LaunchVelocity = MotionControllerRightAim->GetForwardVector() * TeleportLauchSpeed;
	ProjectilePathParams.bTraceWithCollision = true;
	ProjectilePathParams.ProjectileRadius = TeleportProjectileRadius;
	ProjectilePathParams.ObjectTypes = TArray<TEnumAsByte<EObjectTypeQuery>>{ EObjectTypeQuery::ObjectTypeQuery1 };
	ProjectilePathParams.SimFrequency = 15;
	ProjectilePathParams.MaxSimTime = 2;
	UGameplayStatics::PredictProjectilePath(this, ProjectilePathParams, ProjectilePathResult);
	ProjectilePathResult.HitResult;
	TeleportTracePathPositions = ProjectilePathResult.PathData;
	FPredictProjectilePathPointData StartingPoint;
	StartingPoint.Location = MotionControllerRightAim->GetComponentLocation();
	TeleportTracePathPositions.Insert(StartingPoint, 0);
}