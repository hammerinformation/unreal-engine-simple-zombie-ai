
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FpsCharacter.generated.h"

UCLASS()
class ZOMBIEAIPROJECT_API AFpsCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFpsCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveRight(float Value);
	void MoveForward(float Value);


	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	

};
