// Copyright 2018 NeoWiple, Inc. All Rights Reserved.

#include "BaseFisher.h"

#include "Engine/Engine.h"
#include "Camera/CameraComponent.h"
#include "Curves/CurveFloat.h"
#include "Components/InputComponent.h"

ABaseFisher::ABaseFisher()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(RootComponent);

	ThrowingCurve = nullptr;
	ThrowingSpeed = 1.0f;

	IsTouch = false;
	ThrowingInput = ThrowingOutput = 0.0f;

	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	AutoReceiveInput = EAutoReceiveInput::Player0;
}

void ABaseFisher::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdateThrowingPower(DeltaSeconds);
}

void ABaseFisher::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("TouchScreen"), EInputEvent::IE_Pressed, this, &ABaseFisher::TouchPressed);
	PlayerInputComponent->BindAction(TEXT("TouchScreen"), EInputEvent::IE_Released, this, &ABaseFisher::TouchReleased);
}

void ABaseFisher::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr == ThrowingCurve)
	{
		ThrowingCurve = CreateDefaultSubobject<UCurveFloat>(TEXT("ThrowingCurve"));
	}
}

void ABaseFisher::TouchPressed()
{
	IsTouch = true;
	ThrowingInput = ThrowingOutput = 0.0f;
}

void ABaseFisher::TouchReleased()
{
	IsTouch = false;
}

void ABaseFisher::UpdateThrowingPower(float DeltaSeconds)
{
	if (false == IsTouch || nullptr == ThrowingCurve)
	{
		return;
	}

	ThrowingInput = FMath::Fmod(ThrowingInput + DeltaSeconds * ThrowingSpeed, 2.0f);
	ThrowingOutput = FMath::Clamp(ThrowingCurve->GetFloatValue(ThrowingInput), 0.0f, 1.0f);

	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, FString::Printf(TEXT("Input : %f, Output : %f"), ThrowingInput, ThrowingOutput));
}
