// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FWCommon.h"
#include "GameFramework/Actor.h"
#include "FWDEActor.generated.h"

DECLARE_DELEGATE(FWDE_Single_Zero)

DECLARE_DELEGATE_TwoParams(FWDE_Single_Two, FString, int32)

DECLARE_MULTICAST_DELEGATE(FWDE_Multi_Zero)

DECLARE_DYNAMIC_DELEGATE(FWDE_Dy_Sl_Zero);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWDE_Dy_Sl_One, FString, InfoStr);

UCLASS()
class FRAMECOURSE_API AFWDEActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFWDEActor();

	//委托变量作为参数
	UFUNCTION(BlueprintCallable, Category = "FrameWork")
	void RegFunDel(FWDE_Dy_Sl_Zero TargetFun);

	//TFunction传递函数
	void RegFunOne(TFunction<void(FString)> TargetFun);

	//TMemFUnPtrType传递函数
	template<class UserClass>
	void RegFunTwo(UserClass* TarObj, typename TMemFunPtrType<false, UserClass, void(FString, int32)>::Type InMethod);

	//FMethodPtr传递函数
	template<class UserClass>
	void RegFunThree(UserClass* TarObj, typename FWDE_Single_Two::TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod);

	
	void RegFunTest(FWDE_Single_Two InMethod);
	

	//泛型定义统一接口
	template<class DelegateType, class UserClass, typename... VarTypes>
	void RegFunFour(UserClass* TarObj, typename DelegateType::template TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod, VarTypes... Vars);


	//泛型定义统一接口 TFunction
	template<typename RetType, typename... VarTypes>
	void RegFunFive(TFunction<RetType(VarTypes...)> TarFun);
	
public:
	FWDE_Single_Two TestMethod;
	

	//委托变量
	UPROPERTY(BlueprintAssignable, Category = "FrameWork")
	FWDE_Dy_Sl_One FDSOFun;

private:

	TFunction<void(FString)> TFunOne;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

template <class UserClass>
void AFWDEActor::RegFunTwo(UserClass* TarObj,
	typename TMemFunPtrType<false, UserClass, void(FString, int32)>::Type InMethod)
{
	FWDE_Single_Zero ExeDel;
	ExeDel.BindUObject(TarObj, InMethod, FString("HHHHHHHH"), 54);
	ExeDel.ExecuteIfBound();
}

template <class UserClass>
void AFWDEActor::RegFunThree(UserClass* TarObj,
	typename FWDE_Single_Two::TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod)
{
	FWDE_Single_Two ExeDel;
	ExeDel.BindUObject(TarObj, InMethod);
	ExeDel.ExecuteIfBound(FString("I am aaa"), 36);
}

template <class DelegateType, class UserClass, typename... VarTypes>
void AFWDEActor::RegFunFour(UserClass* TarObj,
	typename DelegateType::template TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod, VarTypes... Vars)
{
	FWDE_Single_Zero ExeDel;
	ExeDel.BindUObject(TarObj, InMethod, Vars...);
	ExeDel.ExecuteIfBound();
}

template <typename RetType, typename ... VarTypes>
void AFWDEActor::RegFunFive(TFunction<RetType(VarTypes...)> TarFun)
{
	if (TarFun(FString("RegFunFive"), 78)) FWHelper::Debug("Return true", 500.f);		
}
