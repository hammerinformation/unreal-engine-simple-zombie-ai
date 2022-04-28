#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "AITypes.h"
#include "Navigation/PathFollowingComponent.h"
#include "ZombieAIController.generated.h"


UCLASS()
class ZOMBIEAIPROJECT_API AZombieAIController : public AAIController
{
	GENERATED_BODY()
public:
	AZombieAIController();

	virtual void BeginPlay()override;
	UPROPERTY(EditAnywhere)
		class UAIPerceptionComponent* PerceptionComp = nullptr;

	UPROPERTY(EditAnywhere)
		class UAISenseConfig_Sight* SightConfig;
	UPROPERTY(EditAnywhere)

		class UAISenseConfig_Hearing* HearingConfig;
	UFUNCTION()
		void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);


	class  AFpsCharacter* Player;


	virtual FRotator GetControlRotation() const override;


	UFUNCTION()
		void	OnMoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result);


};
