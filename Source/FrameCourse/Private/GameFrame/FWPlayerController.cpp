// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFrame/FWPlayerController.h"

void AFWPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//输入模式
	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);
	SetInputMode(InputMode);

	//显示鼠标
	bShowMouseCursor = true;
}
