
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Task_RandomLocation.generated.h"

UCLASS()
class ZOMBIEAIPROJECT_API UTask_RandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_RandomLocation(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	
};
