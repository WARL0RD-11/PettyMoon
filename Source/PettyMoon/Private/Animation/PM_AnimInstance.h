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

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	FORCEINLINE float GetSpeed() const { return Speed; }
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	FORCEINLINE bool bIsMoving() const { return Speed != 0.0f; }
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	FORCEINLINE bool bIsNotMoving() const { return Speed == 0.0f; }
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	FORCEINLINE float GetLean() const { return Lean; }
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	FORCEINLINE float GetLeanSpeed() const { return LeanSpeed; }

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
	
private:
	UPROPERTY()
	TObjectPtr<class ACharacter> OwnerCharacter;
	
	UPROPERTY()
	TObjectPtr<class UCharacterMovementComponent> MovementComponent;
	
	//Control Variables
	float Speed;
	float Lean;
	FRotator PrevBodyRot;
	
	//Tunable Variable
	UPROPERTY(EditAnywhere, Category = "Movement")
	float LeanSpeed; //Smoothed Lean Speed
	
	UPROPERTY(EditAnywhere, Category = "Animation")
	float InterpLeanSpeed = 1.f;
};
