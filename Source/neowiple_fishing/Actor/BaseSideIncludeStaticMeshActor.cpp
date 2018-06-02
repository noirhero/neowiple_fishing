// Copyright 2018 NeoWiple, Inc. All Rights Reserved.

#include "BaseSideIncludeStaticMeshActor.h"

#include "Engine/CollisionProfile.h"
#include "Components/StaticMeshComponent.h"

ABaseSideIncludeStaticMeshActor::ABaseSideIncludeStaticMeshActor()
{
	SideStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SideStaticMeshComponent"));
	SideStaticMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	SideStaticMeshComponent->Mobility = EComponentMobility::Static;
	SideStaticMeshComponent->bGenerateOverlapEvents = false;
	SideStaticMeshComponent->bUseDefaultCollision = true;
	SideStaticMeshComponent->SetupAttachment(RootComponent);
}
