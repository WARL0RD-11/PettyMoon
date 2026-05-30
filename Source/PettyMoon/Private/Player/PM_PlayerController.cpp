// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PM_PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "GameFramework/Character.h"

APM_PlayerController::APM_PlayerController()
{
	bReplicates = true;	
}

void APM_PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
}

void APM_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	ControlledPawn = GetPawn();

	if (!ControlledPawn) return;

	if (IsLocalController())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::
			GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
}

void APM_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (!IsLocalController()) return;

	UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(InputComponent);

	if(EIC)
	{
		EIC->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ThisClass::HandleJumpAction);
	}	
}

void APM_PlayerController::HandleJumpAction(const FInputActionValue& Value)
{
	if (ACharacter* ControlledCharacter = Cast<ACharacter>(ControlledPawn))
	{
		ControlledCharacter->Jump();
	}
}
