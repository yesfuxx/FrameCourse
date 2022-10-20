// Fill out your copyright notice in the Description page of Project Settings.


#include "Reflect/SrcActor.h"

#include "FWCommon.h"

// Sets default values
ASrcActor::ASrcActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ActorName = FString("ASrcActor");
	IsActive = true;

}

void ASrcActor::UFunOne()
{
	FWHelper::Debug("ASrcActor --> UFunOne");
}

void ASrcActor::UFunTwo(FString InfoStr, int32& Count)
{
	FWHelper::Debug(InfoStr + " --> " + FString::FromInt(Count));
	Count = 980;
}

bool ASrcActor::UFunThree(FString InfoStr, int32 Count)
{
	FWHelper::Debug(InfoStr + " --> " + FString::FromInt(Count));
	Count = 567;
	return true;
}

int32 ASrcActor::UFunFour(FString InfoStr, int32& Count)
{
	FWHelper::Debug(InfoStr + " --> " + FString::FromInt(Count));
	Count = 532;
	return 769;
}

// Called when the game starts or when spawned
void ASrcActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASrcActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

