#include "Actor.h"

void Actor::DisplayStatus(Actor* InActor) const
{
	printf("\n\n============\n���� ü��: %d / %d\n��� ü��: %d / %d\n============\n\n",
		this->GetCurrentHealth(), this->GetMaxHealth(), InActor->GetCurrentHealth(), InActor->GetMaxHealth());
}

void Actor::Attack(Actor* InTarget)
{
	InTarget->TakeDamage(); // Attack�� ������ CurrentHealth--:
}

void Actor::ResetActorStatus()
{
	this->ResetMaxHealth();  // �ִ� ü�� +1
	this->SetCurrentHealthToMaxHealth(); // ���� ü�� ��� ȸ��
	this->ResetAttackPower();
}
