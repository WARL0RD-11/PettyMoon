// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PM_PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APM_PlayerCharacter::APM_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	SpringArm->TargetArmLength = 500.f;
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	bUseControllerRotationYaw = false;

}

void APM_PlayerCharacter::PawnClientRestart()
{
	Super::PawnClientRestart();
}	

void APM_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void APM_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
