// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "BaseCharacter.generated.h"

UCLASS()
class FASTGAME_API ABaseCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseCharacter();

protected:
	//Defoult value which sets if seed value is unacceptable
	const float DefoultDistanceFromBall = 350.0f;
	const float DefoultPlankRotationSpeed = 6.0f;
	const float DefoultCameraSpeed = 10.0f;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		bool IsScreenTouch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCameraComponent* Camera;
	//How far dow from ball can be planks
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxDistanceFromBall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PlankRotationSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CameraSpeed;
	


	//set rotation between two rotation by alpha
	UFUNCTION(BlueprintCallable)
		void RotationLerpComponent(UStaticMeshComponent* RotateObject, FRotator ToRotate, FRotator FromRotate, float alpha);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	


	

public:	
	//Ball which will fly
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		UStaticMeshComponent* Ball;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxHighRun;

	//Plank which will launch ball
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		UStaticMeshComponent* PlankRight;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		UStaticMeshComponent* PlankLeft;

	//Defoult Rotation of planks
	UPROPERTY(EditAnywhere)
		FRotator LeftPlankRotation0;
	UPROPERTY(EditAnywhere)
		FRotator RightPlankRotation0;

	//Rotation which planks get when player touch screen
	UPROPERTY(EditAnywhere)
		FRotator LeftPlankRotation1;
	UPROPERTY(EditAnywhere)
		FRotator RightPlankRotation1;
	UPROPERTY(EditAnywhere)
		float Alpha;

	//Player touching screen events
	UFUNCTION(BlueprintCallable)
		void TouchScreen();
	UFUNCTION(BlueprintCallable)
		void StopTouchScreen();

	//function for test
	void TestRotationComponent(float Alpha);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
