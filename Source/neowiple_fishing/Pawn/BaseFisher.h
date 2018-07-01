// Copyright 2018 NeoWiple, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseFisher.generated.h"

class UCameraComponent;
class UCurveFloat;

UCLASS(Abstract, Blueprintable)
class NEOWIPLE_FISHING_API ABaseFisher : public APawn
{
	GENERATED_BODY()

public:
	ABaseFisher();

	virtual void			SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void			Tick(float DeltaSeconds);

	UFUNCTION(BlueprintCallable, Category = "Throwing")
		float				GetThrowingPower() const { return ThrowingOutput; }

	UPROPERTY(VisibleAnywhere, Category="Camera")
		UCameraComponent*	CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Throwing")
		UCurveFloat*		ThrowingCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Throwing")
		float				ThrowingSpeed;

protected:
	virtual void			BeginPlay() override;
	virtual void			TouchPressed();
	virtual void			TouchReleased();
	virtual void			TouchLeftX(float Scale);

	void					UpdateThrowingPower(float DeltaSeconds);

	bool					IsTouch;
	float					ThrowingInput;
	float					ThrowingOutput;
};
