// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/PM_Character.h"
#include "PM_PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class APM_PlayerCharacter : public APM_Character
{
	GENERATED_BODY()
public:
	APM_PlayerCharacter();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void PawnClientRestart() override;	
private:
	UPROPERTY(VisibleDefaultsOnly, Category = "View")
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "View")
	TObjectPtr<class UCameraComponent> Camera;

	
};
