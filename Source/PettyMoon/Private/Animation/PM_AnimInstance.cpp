// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/PM_AnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

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
}

void UPM_AnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
}
