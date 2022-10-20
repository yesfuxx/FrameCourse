// Fill out your copyright notice in the Description page of Project Settings.


#include "DeleEvent/FWReceActor.h"

#include "FWCommon.h"
#include "DeleEvent/FWDEActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFWReceActor::AFWReceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFWReceActor::EchoInfoOne(FString InfoStr)
{
	FWHelper::Debug(InfoStr, 500.f);
}

void AFWReceActor::EchoInfoTwo(FString InfoStr, int32 Count)
{
	FWHelper::Debug(InfoStr + FString("-->") + FString::FromInt(Count), 500.f);
}

bool AFWReceActor::EchoInfoThree(FString InfoStr, int32 Count)
{
	FWHelper::Debug(InfoStr + FString("-->") + FString::FromInt(Count), 500.f);
	return true;
}

// Called when the game starts or when spawned
void AFWReceActor::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> ActArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFWDEActor::StaticClass(), ActArray);
	if (ActArray.Num() > 0)
	{
		AFWDEActor* DEActor = Cast<AFWDEActor>(ActArray[0]);

		//方法一：TFunction的函数传递
		// DEActor->RegFunOne([this](FString InfoStr)
		// {
		// 	EchoInfoOne(InfoStr);
		// });

		//方法二：TMemFunPtrType的函数传递
		// DEActor->RegFunTwo(this, &AFWReceActor::EchoInfoTwo);

		//方法三：FMethodPtr函数传递
		// DEActor->RegFunThree(this, &AFWReceActor::EchoInfoTwo);
		
		DECLARE_DELEGATE_TwoParams(FTempDele2, FString, int32)
		FTempDele2 aa;
		aa.BindUObject(this, &AFWReceActor::EchoInfoTwo);
		DEActor->RegFunTest(aa);

		//方法四：FMethodPtr扩展
		DECLARE_DELEGATE_TwoParams(FTempDele, FString, int32)
		DEActor->RegFunFour<FTempDele>(this, &AFWReceActor::EchoInfoTwo, FString("RegFunFour"), 123123);

		//方法五：TFunction扩展
		DEActor->RegFunFive<bool, FString, int32>([this](FString InfoStr, int32 Count)
		{
			return EchoInfoThree(InfoStr, Count);
		});
	}	
}

// Called every frame
void AFWReceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

