// Copyright 2018 NeoWiple, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "BaseSideIncludeStaticMeshActor.generated.h"

UCLASS(Abstract, Blueprintable)
class NEOWIPLE_FISHING_API ABaseSideIncludeStaticMeshActor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	ABaseSideIncludeStaticMeshActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (ExposeFunctionCategories = "Mesh,Rendering,Physics,Components|StaticMesh", AllowPrivateAccess = "true"))
		UStaticMeshComponent* SideStaticMeshComponent;
};
