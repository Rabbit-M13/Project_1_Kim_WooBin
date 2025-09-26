#include "Actor.h"

void Actor::DisplayStatus(Actor* InActor) const
{
	printf("\n\n============\n나의 체력: %d / %d\n상대 체력: %d / %d\n============\n\n",
		this->GetCurrentHealth(), this->GetMaxHealth(), InActor->GetCurrentHealth(), InActor->GetMaxHealth());
}

void Actor::Attack(Actor* InTarget)
{
	InTarget->TakeDamage(); // Attack을 받으면 CurrentHealth--:
}

void Actor::ResetActorStatus()
{
	this->ResetMaxHealth();  // 최대 체력 +1
	this->SetCurrentHealthToMaxHealth(); // 현재 체력 모두 회복
	this->ResetAttackPower();
}
