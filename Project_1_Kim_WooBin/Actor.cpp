#include "Actor.h"

void Actor::Attack(Actor* InTarget)
{
	InTarget->TakeDamage(); // Attack�� ������ CurrentHealth--:
}
