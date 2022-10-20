// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FWAffectWidget.generated.h"

class UImage;
class UCanvasPanel;
class UButton;

/**
 * 
 */
UCLASS()
class FRAMECOURSE_API UFWAffectWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UFWAffectWidget(const FObjectInitializer& ObjectInitializer);

	//Widget的初始化函数
	virtual bool Initialize() override;

	UFUNCTION()
	void ButtonOneEvent();

	UFUNCTION()
	void ButtonTwoEvent();

	UFUNCTION(BlueprintCallable, Category = "FrameWork")
	void ButtonThreeEvent();

public:

	//获取控件方法三：反射绑定
	UPROPERTY(Meta = (BindWidget))
	UButton* ButtonOne;

private:

	UImage* BGImage;

	UCanvasPanel* RootPanel;

	//动态图片
	UImage* DynImage;
};
