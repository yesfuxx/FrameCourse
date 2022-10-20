// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FWInterface.generated.h"


/*
 * *UPROPERTY()变量会报错
 *
 * 带 meta = (CannotImplementInterfaceInBlueprint)只能够接受UFunction(BlueprintCallable)的方法，并且要写出虚函数
 * 不带，不能够接受UFunction(BlueprintCallable)，
 * 可以接受
 * UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
 * UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
 * UFUNCTION(BlueprintNativeEvent)
 * UFUNCTION(BlueprintNativeEvent)
 *
 */

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFWInterface : public UInterface
{
	// GENERATED_BODY()
	//改成这个 UFUNCTION(......) 括号里面才能填参数
	GENERATED_UINTERFACE_BODY()
};

/**
 *

 */
class FRAMECOURSE_API IFWInterface
{
	// GENERATED_BODY()
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "FrameWork")
	void FWFunOne(const FString& HitResult);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "FrameWork")
	void FWFunTwo(const FString& HitResult);

	UFUNCTION(BlueprintNativeEvent, Category = "FrameWork")
	void FWFunThree(const FString& HitResult);	
};
