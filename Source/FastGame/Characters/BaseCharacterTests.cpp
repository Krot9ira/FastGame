// Fill out your copyright notice in the Description page of Project Settings.
#if (WITH_DEV_AUTOMATION_TESTS)

#include "Characters/BaseCharacterTests.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "BaseCharacter.h"
#include "Engine/World.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FRotationPlank, "FastGame.Character.RotatePlank", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::HighPriority);

bool FRotationPlank::RunTest(const FString& Parameters)
{
	ABaseCharacter* TestCharacter = NewObject<ABaseCharacter>();
	if (!TestNotNull("TestCharacter exist", TestCharacter))
	{
		return false;
	}
	FRotator TempRotationLeft = TestCharacter->PlankLeft->GetRelativeRotation();
	FRotator TempRotationRight = TestCharacter->PlankRight->GetRelativeRotation();
	TestCharacter->LeftPlankRotation1 = FRotator(22.0f, 44.0f, 0.0f);
	TestCharacter->RightPlankRotation1 = FRotator(33.0f, 55.0f, 0.0f);

	TestCharacter->TestRotationComponent(1);
	
	TestTrueExpr((TempRotationLeft != TestCharacter->PlankLeft->GetRelativeRotation()) && (TempRotationRight != TestCharacter->PlankRight->GetRelativeRotation()));
	
	return true;
	
}

#endif 