// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	PlankLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlankLeft"));
	PlankLeft->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	PlankRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlankRight"));
	PlankRight->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	LeftPlankRotation0 = PlankLeft->GetRelativeRotation();
	RightPlankRotation0 = PlankRight->GetRelativeRotation();
}

void ABaseCharacter::RotationLerpComponent(UStaticMeshComponent* RotateObject, FRotator ToRotate, FRotator FromRotate, float alpha)
{
	if (FQuat(RotateObject->GetRelativeRotation()) != FMath::Lerp(FQuat(ToRotate), FQuat(FRotator(FromRotate)), alpha))
	{
		RotateObject->SetRelativeRotation(FMath::Lerp(FQuat(ToRotate), FQuat(FRotator(FromRotate)), alpha));
	}
	
}



// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsScreenTouch)
	{
		Alpha = FMath::FInterpTo(Alpha, 1, DeltaTime, 5);
	}
	else
	{
		Alpha = FMath::FInterpTo(Alpha, 0, DeltaTime, 5);
	}
	RotationLerpComponent(PlankLeft, LeftPlankRotation0, LeftPlankRotation1, Alpha);
	RotationLerpComponent(PlankRight, RightPlankRotation0, RightPlankRotation1, Alpha);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Touch", IE_Pressed,this, &ABaseCharacter::TouchScreen);
	PlayerInputComponent->BindAction("Touch", IE_Released, this, &ABaseCharacter::StopTouchScreen);
}

void ABaseCharacter::TouchScreen()
{
	IsScreenTouch = true;
}

void ABaseCharacter::StopTouchScreen()
{
	IsScreenTouch = false;
}

void ABaseCharacter::TestRotationComponent(float TempAlpha)
{
	RotationLerpComponent(PlankLeft, LeftPlankRotation0, LeftPlankRotation1, TempAlpha);
	RotationLerpComponent(PlankRight, RightPlankRotation0, RightPlankRotation1, TempAlpha);
}



