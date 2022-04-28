

#include "ZombieCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/BoxComponent.h"
#include "FpsCharacter.h"
#include "Engine/Engine.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "Animation/AnimInstance.h"

AZombieCharacter::AZombieCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(GetRootComponent());
}

void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = this->MaxWalkSpeed;
	(*Trigger).OnComponentBeginOverlap.AddDynamic(this, &AZombieCharacter::OnTriggerEnter);
	(*Trigger).OnComponentEndOverlap.AddDynamic(this, &AZombieCharacter::OnTriggerExit);
	Player = Cast<AFpsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	ZombieAIController = Cast<AZombieAIController>(GetController());
}

void AZombieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AZombieCharacter::OnTriggerEnter(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor == Player) {
		ZombieAIController->GetBlackboardComponent()->SetValueAsBool("CanAttack", true);
		/*
		
		if (GetMesh()->GetAnimInstance() && AttackMontage) {
			GetMesh()->GetAnimInstance()->Montage_Play(AttackMontage);
		}
		*/
		
	}

}

void AZombieCharacter::OnTriggerExit(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherActor == Player) {
		ZombieAIController->GetBlackboardComponent()->SetValueAsBool("CanAttack", false);

	}
}


