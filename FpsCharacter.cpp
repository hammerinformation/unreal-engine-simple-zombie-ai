

#include "FpsCharacter.h"
#include "Components/InputComponent.h"
AFpsCharacter::AFpsCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AFpsCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void AFpsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFpsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	PlayerInputComponent->BindKey(EKeys::SpaceBar, IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("Horizontal", this, &AFpsCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Vertical", this, &AFpsCharacter::MoveForward);
	PlayerInputComponent->BindAxis("HorizontalRotation", this, &AFpsCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("VerticalRotation", this, &AFpsCharacter::LookUpAtRate);

}
void AFpsCharacter::MoveRight(float Value)
{

	AddMovementInput(GetActorRightVector(), Value);

}



void AFpsCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);

}

void AFpsCharacter::TurnAtRate(float Value)
{
	AddControllerYawInput(Value);

}

void AFpsCharacter::LookUpAtRate(float Value)
{
	AddControllerPitchInput(Value);

}


