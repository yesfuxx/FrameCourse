// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FWCharacter.generated.h"

UCLASS()
class FRAMECOURSE_API AFWCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFWCharacter();

	UFUNCTION(BlueprintCallable, Category = "FrameWork")
	void CAFuncOne(int32 Input, bool& Output);

	//蓝图实现，c++调用蓝图方法
	UFUNCTION(BlueprintImplementableEvent, Category = "FrameWork")
	void CAFuncTwo(int32 Input, bool& Output);

	//都可以实现，c++中实现，需加 _Implementation
	UFUNCTION(BlueprintNativeEvent, Category = "FrameWork")
	void CAFuncThree(int32 Input, bool& Output);

	//控制台调用 控制台只能调 GameInstance 和 GameMode下的方法 可用于Debug
	UFUNCTION(Exec, Category = "FrameWork")
	void CAFuncFour(FString Info, int32 Count);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif	
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FrameWork")
	AActor* CAOne;//场景中实际存在的场景指针

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FrameWork")
	TSubclassOf<AActor> CATwo;//对象的类的类型，允许使用类型安全传递UClass的模块

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FrameWork")
	TSoftObjectPtr<AActor> CAThree;//对象的软引用，需要的时候后再加载

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FrameWork")
	TSoftClassPtr<AActor> CAFour;//对象的类的类型的软引用，需要的时候后再加载

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FrameWork")
	TAssetPtr<AActor> CAFive;//资源引用，是对FStringAssetReference的封装，包含对象路径与弱指针

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MetaClass = "Actor"), Category = "FrameWork")
	FStringAssetReference CASix;//资源路径的引用

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "AllowEdit", ToolTip = "I am a bool"), Category = "FrameWork")
	bool CAAllow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 10, ClampMax = 100, EditCondition = CAAllow), Category = "FrameWork")

	int32 CACount;
		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
