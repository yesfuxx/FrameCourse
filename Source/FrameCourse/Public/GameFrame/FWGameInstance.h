// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FWGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FRAMECOURSE_API UFWGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	//控制台调用 控制台只能调 GameInstance 和 GameMode下的方法 可用于Debug
	UFUNCTION(Exec, Category = "GameFramework")
	void GIEcho(FString Info, int32 Count);

	virtual bool ProcessConsoleExec(const TCHAR* Cmd, FOutputDevice& Ar, UObject* Executor) override;
	
};
