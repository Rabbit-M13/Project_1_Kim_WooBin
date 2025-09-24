#include "Actor.h"

void Actor::Attack(Actor* InTarget)
{
	InTarget->TakeDamage(); // Attack을 받으면 CurrentHealth--:
}
