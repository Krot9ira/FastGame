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
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		bool IsScreenTouch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCameraComponent* Camera;


	//set rotation between two rotation by alpha
	UFUNCTION(BlueprintCallable)
		void RotationLerpComponent(UStaticMeshComponent* RotateObject, FRotator ToRotate, FRotator FromRotate, float alpha);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	


	

public:	
	//Ball which will fly
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
