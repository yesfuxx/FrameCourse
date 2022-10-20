// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FWCallInter.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UFWCallInter : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class FRAMECOURSE_API IFWCallInter
{
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, Category = "FrameWork")
	virtual void FWCallFun(const FString& HitResult) = 0;
	
	
};
