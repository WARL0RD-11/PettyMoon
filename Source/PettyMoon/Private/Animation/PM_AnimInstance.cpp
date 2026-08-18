// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/PM_AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "math.h"

void UPM_AnimInstance :: NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	if (!OwnerCharacter) return;
	
	MovementComponent = OwnerCharacter->GetCharacterMovement();
	PrevBodyRot = OwnerCharacter->GetActorRotation();
}

void UPM_AnimInstance :: NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	//Re- Acquring Character and Movement Component in case they are not set

	if (!OwnerCharacter)
	{
		OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());

		if (!OwnerCharacter)
		{
			UE_LOG(
				LogTemp,
				Warning,
				TEXT("AnimInstance [%s]: NO PAWN OWNER"),
				*GetName()
			);

			return;
		}
	}

	if (!MovementComponent)
	{
		MovementComponent = OwnerCharacter->GetCharacterMovement();

		if (!MovementComponent)
		{
			return;
		}
	}

	Speed = OwnerCharacter->GetVelocity().Size2D();

		//Jumping Logic
	bIsJumping = MovementComponent->IsFalling();
	
	//Lean Logic
	FRotator BodyRot = OwnerCharacter->GetActorRotation();
	FRotator BodyRotDelta = UKismetMathLibrary::NormalizedDeltaRotator(BodyRot, PrevBodyRot);
	PrevBodyRot = BodyRot;
	
	Lean = BodyRotDelta.Yaw / DeltaSeconds;
	LeanSpeed = FMath::FInterpTo(LeanSpeed, Lean, DeltaSeconds, 
		InterpLeanSpeed);
	


	//Look Offset Logic
	FRotator ControlRot = OwnerCharacter->GetBaseAimRotation();
	LookRotOffset = UKismetMathLibrary::NormalizedDeltaRotator(ControlRot, BodyRot);

}

void UPM_AnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}
