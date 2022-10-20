// Fill out your copyright notice in the Description page of Project Settings.


#include "Reflect/DecActor.h"

#include "FWCommon.h"
#include "Kismet/GameplayStatics.h"
#include "Reflect/RefObj.h"
#include "Reflect/SrcActor.h"

// Sets default values
ADecActor::ADecActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADecActor::ReflectInstance()
{
	UClass* RefObjClass = StaticLoadClass(UObject::StaticClass(), nullptr, TEXT("URefObj"));
	URefObj* RefObjIns = Cast<URefObj>(RefObjClass);
	//RefObjIns->EchoInfo();

	UObject* RefObjPtr = StaticLoadObject(UObject::StaticClass(), nullptr, TEXT("URefObj"));
	URefObj* RefObjOth = Cast<URefObj>(RefObjPtr);
	//RefObjOth->EchoInfo();

	//if (RefObjIns == RefObjOth) FWHelper::Debug("The Same");

	//反射Enum FindObject UEnum不需load
	 UEnum* EnumPtr = FindObject<UEnum>((UObject*)ANY_PACKAGE, *FString("ERefState"), true);
	FWHelper::Debug(EnumPtr->GetEnumName((int32)1));

	UBlueprint* RefActorBP = LoadObject<UBlueprint>(nullptr, TEXT("Blueprint'/Game/Blueprint/Reflect/RefActorBP.RefActorBP'"));
	TSubclassOf<AActor> RefActorClass = (UClass*)RefActorBP->GeneratedClass;
	// UClass RefActorClass = (UClass*)RefActorBP->GeneratedClass;
	GetWorld()->SpawnActor<AActor>(RefActorClass, FVector::ZeroVector + FVector(0.f, 0.f, 60.f), FRotator::ZeroRotator);
}

void ADecActor::ControlUProperty()
{
	
	for (TFieldIterator<FProperty> ProIt(SrcObj->GetClass()); ProIt; ++ProIt)
	{
		FProperty* Property = *ProIt;
		//操作String类型
		if (Property->GetNameCPP().Equals("ActorName"))
		{
			FStrProperty* StrProperty = Cast<FStrProperty>(Property);
			if (StrProperty)
			{
				void* ValPtr = Property->ContainerPtrToValuePtr<uint8>(SrcObj);
				FWHelper::Debug(FString("ActorName Before --> ") + StrProperty->GetPropertyValue(ValPtr));
				StrProperty->SetPropertyValue(ValPtr, FString("New Name"));	
			}
			FWHelper::Debug(FString("ActorName After --> ") + SrcAct->ActorName);
		}

		//操作bool类型
		if (Property->GetNameCPP().Equals("IsActive"))
		{
			FBoolProperty* BolProperty = Cast<FBoolProperty>(Property);
			if (BolProperty)
			{
				void* ValPtr = Property->ContainerPtrToValuePtr<uint8>(SrcObj);
				FWHelper::Debug(FString("IsActive Before --> ") + FString::FromInt(BolProperty->GetPropertyValue(ValPtr)));
				BolProperty->SetPropertyValue(ValPtr, false);	
			}
			FWHelper::Debug(FString("IsActive After --> ") + FString::FromInt(SrcAct->IsActive));
		}
	}
}

void ADecActor::RunUFunOne()
{
	FScriptDelegate FunDelOne;
	FunDelOne.BindUFunction(SrcObj, FName("UFunOne"));
	// FunDelOne.ProcessDelegate<UObject>(nullptr);

	FScriptDelegate FunDelTwo;
	FunDelTwo.BindUFunction(SrcObj, FName("UFunTwo"));//UFunTwo引用代替返回值
	struct
	{
		FString InfoStr;
		int32 Count;
	} FunTwoParam;

	FunTwoParam.InfoStr = FString("ASrcActor --> UFunTwo");
	FunTwoParam.Count = 567;
	FunDelTwo.ProcessDelegate<UObject>(&FunTwoParam);
	FWHelper::Debug(FString::FromInt((FunTwoParam.Count)));
}

void ADecActor::RunUFunTwo()
{
	//支持返回值
	TBaseDelegate<bool, FString, int32> FunDelThree = TBaseDelegate<bool, FString, int32>::CreateUFunction(SrcObj, "UFunThree");
	bool DelResult = FunDelThree.Execute(FString("ASrcActor --> UFunThree"), 789);
	if (DelResult) FWHelper::Debug("Return true");
}

void ADecActor::RunUFunThree()
{
	UFunction* FunFour = SrcObj->FindFunction(FName("UFunFour"));
	if (FunFour)
	{
		struct
		{
			FString InfoStr;
			int32 Count;
		} FunFourParam;
		FunFourParam.InfoStr = FString("ASrcActor --> UFunFour");
		FunFourParam.Count = 675;
		SrcObj->ProcessEvent(FunFour, &FunFourParam);

		//返回值地址
		uint8* RetValPtr = (uint8*)&FunFourParam + FunFour->ReturnValueOffset;
		int32* RetVal = (int32*)RetValPtr;
		FWHelper::Debug(FString("Return Value --> ") + FString::FromInt(*RetVal));
		FWHelper::Debug(FString("Count Value --> ") + FString::FromInt(FunFourParam.Count));
	}
}

// Called when the game starts or when spawned
void ADecActor::BeginPlay()
{
	Super::BeginPlay();

	// ReflectInstance();

	TArray<AActor*> ActArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASrcActor::StaticClass(), ActArray);
	if (ActArray.Num() > 0)
	{
		SrcAct = Cast<ASrcActor>(ActArray[0]);
		SrcObj = (UObject*)SrcAct;

		//反射操作UProperty对象
		//ControlUProperty();

		//调用UFunction方法一：FScriptDelegate
		// RunUFunOne();

		//调用UFunction方法二：FBaseDelegate
		// RunUFunTwo();

		// 调用UFunction方法三：UFunction
		//RunUFunThree();
	} 
}

// Called every frame
void ADecActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

