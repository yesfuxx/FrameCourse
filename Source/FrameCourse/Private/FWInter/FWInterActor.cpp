// Fill out your copyright notice in the Description page of Project Settings.


#include "FWInter/FWInterActor.h"

#include "FWCommon.h"

// Sets default values
AFWInterActor::AFWInterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFWInterActor::FWFunOne_Implementation(const FString& HitResult)
{
	FWHelper::Debug("FWFunOne", 500.f);
}

void AFWInterActor::FWFunThree_Implementation(const FString& HitResult)
{
	FWHelper::Debug("FWFunThree", 500.f);
}

// Called when the game starts or when spawned
void AFWInterActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFWInterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

