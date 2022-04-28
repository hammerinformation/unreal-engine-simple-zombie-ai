#include "Task_RandomLocation.h"
#include "NavigationSystem.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ZombieAIController.h"
UTask_RandomLocation::UTask_RandomLocation(const FObjectInitializer& ObjectInitializer) {
	NodeName = TEXT("Task_RandomLocation");

}

EBTNodeResult::Type UTask_RandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const AIController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	auto const Pawn = AIController->GetPawn();
	FNavLocation Loc;
	FVector const Origin = Pawn->GetActorLocation();
	UNavigationSystemV1* const NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (NavigationSystem->GetRandomReachablePointInRadius(Origin, 2800.0f, Loc)) {
		AIController->GetBlackboardComponent()->SetValueAsVector("RandomLocation", Loc.Location);
		return EBTNodeResult::Succeeded;

	}
	else {
		return EBTNodeResult::Failed;

	}
}
