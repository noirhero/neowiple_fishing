// Copyright 2018 NeoWiple, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseFisher.generated.h"

class UCameraComponent;

UCLASS(Abstract, Blueprintable)
class NEOWIPLE_FISHING_API ABaseFisher : public APawn
{
	GENERATED_BODY()

public:
	ABaseFisher();

	virtual void			SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category="Camera")
		UCameraComponent*	CameraComponent;

protected:
	virtual void			BeginPlay() override;
};
