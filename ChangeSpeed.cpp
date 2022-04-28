

#include "ChangeSpeed.h"
#include "ZombieAIController.h"
#include "ZombieCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UChangeSpeed::UChangeSpeed() {
	bNotifyBecomeRelevant = true;
	NodeName = "Change Speed";
}
void UChangeSpeed::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	auto const AIController = Cast<AZombieAIController>(OwnerComp.GetAIOwner());
	AZombieCharacter* const Zombie = Cast<AZombieCharacter>(AIController->GetPawn());
	Zombie->GetCharacterMovement()->MaxWalkSpeed = this->MaxWalkSpeed;
	Zombie->GetCharacterMovement()->MaxAcceleration = this->MaxAcceleration;
}
