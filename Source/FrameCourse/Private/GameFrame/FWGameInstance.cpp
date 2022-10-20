// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFrame/FWGameInstance.h"

#include "EngineUtils.h"
#include "FWCharacter.h"
#include "Common/FWCommon.h"
#include "Kismet/GameplayStatics.h"

void UFWGameInstance::GIEcho(FString Info, int32 Count)
{
	FWHelper::Debug(Info + FString("  ") + FString::FromInt(Count), 120.f);
}

bool UFWGameInstance::ProcessConsoleExec(const TCHAR* Cmd, FOutputDevice& Ar, UObject* Executor)
{
	bool Res = Super::ProcessConsoleExec(Cmd, Ar, Executor);
	if (!Res)
	{
		//获取场景对象方法一：
		for (TActorIterator<AFWCharacter> It(GetWorld()); It; ++It)
		{
			Res = It->ProcessConsoleExec(Cmd, Ar, Executor);
		}
		//获取场景对象方法二：
		// TArray<AActor*> ActArray;
		// UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFWCharacter::StaticClass(), ActArray);
		// for (AActor* Act : ActArray)
		// {
		// 	Res = Act->ProcessConsoleExec(Cmd, Ar, Executor);
		// }
	}
	return Res; 
}
