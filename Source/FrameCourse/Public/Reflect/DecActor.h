// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DecActor.generated.h"

class ASrcActor;

UCLASS()
class FRAMECOURSE_API ADecActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecActor();

	//反射实例化对象
	void ReflectInstance();

	//反射操作UProperty对象
	void ControlUProperty();

	//调用UFunction方法一：FScriptDelegate
	void RunUFunOne();

	//调用UFunction方法一：FBaseDelegate
	void RunUFunTwo();

	// 调用UFunction方法三：UFunction
	void RunUFunThree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	ASrcActor* SrcAct;
	UObject* SrcObj;

};
