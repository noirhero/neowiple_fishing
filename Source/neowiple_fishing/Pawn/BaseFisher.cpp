// Copyright 2018 NeoWiple, Inc. All Rights Reserved.

#include "BaseFisher.h"

#include "Camera/CameraComponent.h"

ABaseFisher::ABaseFisher()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(RootComponent);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ABaseFisher::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseFisher::BeginPlay()
{
}
