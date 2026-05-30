// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PM_Character.h"
#include "Components/SkeletalMeshComponent.h"

APM_Character::APM_Character()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void APM_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void APM_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

