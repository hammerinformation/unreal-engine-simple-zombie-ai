// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Task_FollowPlayer.generated.h"


UCLASS()
class ZOMBIEAIPROJECT_API UTask_FollowPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_FollowPlayer(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

};
