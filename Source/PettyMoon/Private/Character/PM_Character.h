// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h" // <-- FIX: Include the correct header for ACharacter
#include "PM_Character.generated.h"

UCLASS()
class APM_Character : public ACharacter
{
	GENERATED_BODY()
	
public:	
	APM_Character();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:


};
