// Fill out your copyright notice in the Description page of Project Settings.


#include "DeleEvent/FWDEActor.h"

// Sets default values
AFWDEActor::AFWDEActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFWDEActor::RegFunDel(FWDE_Dy_Sl_Zero TargetFun)
{
	TargetFun.ExecuteIfBound();
}

void AFWDEActor::RegFunOne(TFunction<void(FString)> TargetFun)
{
	TFunOne = TargetFun;
	TFunOne(FString("RegFunOne"));
}

void AFWDEActor::RegFunTest(FWDE_Single_Two InMethod)
{
	TestMethod = InMethod;
	TestMethod.ExecuteIfBound(FString("aaaa"), 123);
}

// Called when the game starts or when spawned
void AFWDEActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFWDEActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

