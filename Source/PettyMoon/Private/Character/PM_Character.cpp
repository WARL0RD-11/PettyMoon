// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PM_Character.h"

// Sets default values
APM_Character::APM_Character()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APM_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APM_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

