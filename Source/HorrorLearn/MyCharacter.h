// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"


class UCameraComponent;
class UInputAction;
struct FInputActionValue;

UCLASS()
class HORRORLEARN_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

	//First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

protected:

	//Move Input Action
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	
	//Called from Input Actions for movement input
	void MoveInput(const FInputActionValue& Value);

	//Handles move inputs from either controls or UI
	UFUNCTION(BlueprintCallable, Category = "Input")
	virtual void DoMove(float Right, float Forward);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
