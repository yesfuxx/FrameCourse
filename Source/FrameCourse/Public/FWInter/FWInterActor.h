// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FWInterface.h"
#include "GameFramework/Actor.h"
#include "FWInterActor.generated.h"

UCLASS()
class FRAMECOURSE_API AFWInterActor : public AActor , public IFWInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFWInterActor();
	
	virtual void FWFunOne_Implementation(const FString& HitResult) override;

	virtual void FWFunThree_Implementation(const FString& HitResult) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
