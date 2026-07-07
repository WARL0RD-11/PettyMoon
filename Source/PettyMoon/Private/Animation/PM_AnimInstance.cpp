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
}

void UPM_AnimInstance :: NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if (!OwnerCharacter) return;
	
	Speed = OwnerCharacter->GetVelocity().Length();
	
	//Lean Logic
	FRotator BodyRot = OwnerCharacter->GetActorRotation();
	FRotator BodyRotDelta = UKismetMathLibrary::NormalizedDeltaRotator(BodyRot, PrevBodyRot);
	PrevBodyRot = BodyRot;
	
	Lean = BodyRotDelta.Yaw / DeltaSeconds;
	LeanSpeed = FMath::FInterpTo(LeanSpeed, Lean, DeltaSeconds, 
		InterpLeanSpeed);
	//Lean ENDS
	

}

void UPM_AnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}
