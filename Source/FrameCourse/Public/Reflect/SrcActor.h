// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SrcActor.generated.h"

UCLASS()
class FRAMECOURSE_API ASrcActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASrcActor();

public:

	UFUNCTION()
	void UFunOne();

	UFUNCTION()
	void UFunTwo(FString InfoStr, int32& Count);

	UFUNCTION()
	bool UFunThree(FString InfoStr, int32 Count);

	UFUNCTION()//调用UFunction方法三：UFunction 参数传的指针只能继承于UObject的
	int32 UFunFour(FString InfoStr, int32& Count);
	
public:

	UPROPERTY(EditAnywhere)
	FString ActorName;

	UPROPERTY(EditAnywhere)
	bool IsActive;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
