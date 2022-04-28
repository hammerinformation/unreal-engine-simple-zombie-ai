#include "ZombieAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Engine/Engine.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "FpsCharacter.h"

AZombieAIController::AZombieAIController() {
	PrimaryActorTick.bCanEverTick = true;
	PerceptionComp = CreateDefaultSubobject< UAIPerceptionComponent>(TEXT("Perception"));
	SetPerceptionComponent(*PerceptionComp);
	SightConfig = CreateDefaultSubobject< UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
	HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
	HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
	HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
	GetPerceptionComponent()->ConfigureSense(*HearingConfig);
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AZombieAIController::OnTargetPerceptionUpdated);

}
void AZombieAIController::BeginPlay()
{
	Super::BeginPlay();
	Player = Cast<AFpsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	this->ReceiveMoveCompleted.AddDynamic(this, &AZombieAIController::OnMoveCompleted);


}



void AZombieAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Actor == Player && Stimulus.WasSuccessfullySensed())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("I can see you"));
		GetBlackboardComponent()->SetValueAsBool("HasTarget", true);
		GetBlackboardComponent()->SetValueAsBool("Investigation", false);
	}
	else {
		GetBlackboardComponent()->SetValueAsBool("HasTarget", false);
		GetBlackboardComponent()->SetValueAsBool("Investigation", true);
		GetBlackboardComponent()->SetValueAsVector("LastSeenLocation", Player->GetActorLocation());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("I can't see you"));


	}
}
void AZombieAIController::OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	if (Result == EPathFollowingResult::Success) {

		if (GetBlackboardComponent()->GetValueAsBool("Investigation")) {
			GetBlackboardComponent()->SetValueAsBool("Investigation", false);

		}
	}
}






FRotator AZombieAIController::GetControlRotation() const
{
	if (GetPawn() == nullptr)
	{
		return FRotator();
	}

	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

