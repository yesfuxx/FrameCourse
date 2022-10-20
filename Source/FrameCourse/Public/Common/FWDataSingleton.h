// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FWDataSingleton.generated.h"

class UTexture2D;

/**
 * 项目设置指定 Game Singleton Class，游戏运行时建议不修改该类中的值
 */
//Blueprintable 蓝图可用
//BlueprintType 其他蓝图可用该类型作为变量
UCLASS(Blueprintable, BlueprintType)
class FRAMECOURSE_API UFWDataSingleton : public UObject
{
	GENERATED_BODY()

public:

	UFWDataSingleton();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FrameWork")
	TArray<UClass*> SourceBlueprints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FrameWork")
	UTexture2D* SourceT2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FrameWork")
	FVector SourceVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FrameWork")
	FString SourceFilePath;
};
