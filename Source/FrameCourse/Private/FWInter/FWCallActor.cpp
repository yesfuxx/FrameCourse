// Fill out your copyright notice in the Description page of Project Settings.


#include "FWInter/FWCallActor.h"

#include "FWCommon.h"
#include "FWInter/FWInterActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFWCallActor::AFWCallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AFWCallActor::FWCallFun(const FString& HitResult)
{
	FWHelper::Debug("FWCallFun", 500.f);
}

// Called when the game starts or when spawned
void AFWCallActor::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> ActArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFWInterActor::StaticClass(), ActArray);
	if (ActArray.Num() > 0)
	{
		IFWInterface* ActorPtr = Cast<IFWInterface>(ActArray[0]);
		//ActorPtr->Execute_FWFunThree(ActArray[0], FString("sssssss"));//官方推荐这种
		// ActorPtr->FWFunThree(...);
	}
	
}

// Called every frame
void AFWCallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

