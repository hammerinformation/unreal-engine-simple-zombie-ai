
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "ChangeSpeed.generated.h"

UCLASS()
class ZOMBIEAIPROJECT_API UChangeSpeed : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:

	UChangeSpeed();
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
	UPROPERTY(EditAnywhere)
		float MaxWalkSpeed = 25.0f;
	UPROPERTY(EditAnywhere)
		float MaxAcceleration = 64.0f;

};
