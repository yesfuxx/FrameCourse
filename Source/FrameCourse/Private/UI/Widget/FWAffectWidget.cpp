// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/FWAffectWidget.h"

#include "Button.h"
#include "CanvasPanel.h"
#include "CanvasPanelSlot.h"
#include "FWCommon.h"
#include "Image.h"
#include "WidgetTree.h"

UFWAffectWidget::UFWAffectWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

bool UFWAffectWidget::Initialize()
{
	if (!Super::Initialize()) return false;

	//获取方式一：强转子集
	RootPanel = Cast<UCanvasPanel>(GetRootWidget());
	if (RootPanel)
	{
		BGImage = Cast<UImage>(RootPanel->GetChildAt(0));
	}
	
	//获取控件方式二：GetWidgetFromName
	UButton* ButtonTwo = (UButton*)GetWidgetFromName(TEXT("ButtonTwo"));
	
	//绑定按钮事件方法一: _Internal_AddDynamic
	ButtonOne->OnClicked.__Internal_AddDynamic(this, &UFWAffectWidget::ButtonOneEvent, FName("ButtonOneEvent"));

	//绑定按钮事件方法二：FScriptDelegate
	FScriptDelegate ButTwoDel;
	ButTwoDel.BindUFunction(this, "ButtonTwoEvent");
	ButtonTwo->OnReleased.Add(ButTwoDel);

	return true;
}

void UFWAffectWidget::ButtonOneEvent()
{
	// FWHelper::Debug("ButtonOneEvent", 10.f);
	UTexture2D* TarTex = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Resource/UI/Texture/MenuTex/book.book'"));
	BGImage->SetBrushFromTexture(TarTex);
}

void UFWAffectWidget::ButtonTwoEvent()
{
	// FWHelper::Debug("ButtonTwoEvent", 10.f);
	//如果动态Image已经存在，直接返回
	if (DynImage) return;
	//创建Widget方法二：通过WidgetTree创建组件
	DynImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
	//添加新控件到Panel
	UCanvasPanelSlot* DynImageSlot = RootPanel->AddChildToCanvas(DynImage);
	//设置变换
	DynImageSlot->SetAnchors(FAnchors(0.f));
	DynImageSlot->SetOffsets(FMargin(244.f, 268.f, 100.f, 100.f));
}

void UFWAffectWidget::ButtonThreeEvent()
{
	// FWHelper::Debug("ButtonThreeEvent", 10.f);
	//如果动态Image已经存在，直接返回
	if (!DynImage) return;
	//移除出父级
	RootPanel->RemoveChild(DynImage);
	// DynImage->RemoveFromParent();
	//释放资源
	DynImage->ConditionalBeginDestroy();
	//设置为空
	DynImage = nullptr;
}
