// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseCharacter.generated.h"

UCLASS()
class FASTGAME_API ABaseCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	bool IsScreenTouch;

	//set rotation between two rotation by alpha
	UFUNCTION(BlueprintCallable)
		void RotationLerpComponent(UStaticMeshComponent* RotateObject, FRotator ToRotate, FRotator FromRotate, float alpha);

	virtual void BeginPlay() override;
	


	

public:	
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
