

#include "Task_FollowPlayer.h"
#include "ZombieAIController.h"
#include "FpsCharacter.h"
#include "Kismet/GameplayStatics.h"
UTask_FollowPlayer::UTask_FollowPlayer(const FObjectInitializer& ObjectInitializer) {
	NodeName = "Follow Player";
}
EBTNodeResult::Type UTask_FollowPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto const AIController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	auto const Pawn = AIController->GetPawn();
	AFpsCharacter* Player = Cast< AFpsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	AIController->MoveToActor(Player, 30.0f, false);
	return EBTNodeResult::Succeeded;
}

