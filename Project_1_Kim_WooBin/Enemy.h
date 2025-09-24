#pragma once
#include "Actor.h"
class AEnemy : public Actor
{
public:
	AEnemy() = default;
	AEnemy(const std::string InName)
		: Actor(InName)
	{

	}

	virtual void Attack(Actor* InTarget) override;
	//void IsShoot(Actor* InTarget); // Attack �� �������̵� �ϸ� ���� �ʿ� ����

private:
	
};

