#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ZombieAIController.h"

#include "ZombieCharacter.generated.h"

UCLASS()
class ZOMBIEAIPROJECT_API AZombieCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AZombieCharacter();
private:
	class AZombieAIController* ZombieAIController;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	class  AFpsCharacter* Player;

	UPROPERTY(EditAnywhere)
	 float MaxWalkSpeed = 50;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* Trigger;

	UFUNCTION()
		void OnTriggerEnter(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	UFUNCTION()
		void OnTriggerExit(
			UPrimitiveComponent* OverlappedComponent, 
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);


	UPROPERTY(EditAnywhere)
		class UAnimMontage* AttackMontage;

};
