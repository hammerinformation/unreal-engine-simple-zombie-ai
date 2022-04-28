
#include "ZombieAnimInstance.h"

void UZombieAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (TryGetPawnOwner()) {
		Speed = TryGetPawnOwner()->GetVelocity().Size();



	}
}