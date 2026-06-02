// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"	
#include "PM_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class APM_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APM_PlayerController();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, Category = "Inputs")
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, Category = "Inputs|Actions")
	TObjectPtr<class UInputAction> JumpAction;	


	UPROPERTY(EditAnywhere, Category = "Inputs|Actions")
	TObjectPtr<class UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category = "Inputs|Actions")
	TObjectPtr<class UInputAction> MoveAction;
	
private:
	APawn* ControlledPawn;	
	void HandleJumpAction(const FInputActionValue& Value);	

	void HandleLookAction(const FInputActionValue& Value);

	void HandleMoveAction(const FInputActionValue& Value);
};
 