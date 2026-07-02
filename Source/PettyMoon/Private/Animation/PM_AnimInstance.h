// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PM_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UPM_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
private:
	UPROPERTY()
	TObjectPtr<class ACharacter> OwnerCharacter;
	
	UPROPERTY()
	TObjectPtr<class UCharacterMovementComponent> MovementComponent;
};
