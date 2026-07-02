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
		EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::HandleLookAction);
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::HandleMoveAction);
	}	
}

void APM_PlayerController::HandleJumpAction(const FInputActionValue& Value)
{
	if (ACharacter* ControlledCharacter = Cast<ACharacter>(ControlledPawn))
	{
		ControlledCharacter->Jump();
	}
}

void APM_PlayerController::HandleLookAction(const FInputActionValue& Value)
{
	FVector2D LookAxisValue = Value.Get<FVector2D>();
	AddPitchInput(-1 * LookAxisValue.Y);
	AddYawInput(LookAxisValue.X);
}

void APM_PlayerController::HandleMoveAction(const FInputActionValue& Value)
{
	if (!IsLocalController()) return;

	FVector2D MoveAxisValue = Value.Get<FVector2D>();
	MoveAxisValue.Normalize();
	const FRotator YawRotation(0, GetControlRotation().Yaw, 0);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (ACharacter* ControlledCharacter = Cast<ACharacter>(ControlledPawn))
	{
		ControlledCharacter->AddMovementInput(ForwardDirection, MoveAxisValue.Y);
		ControlledCharacter->AddMovementInput(RightDirection, MoveAxisValue.X);
	}
}