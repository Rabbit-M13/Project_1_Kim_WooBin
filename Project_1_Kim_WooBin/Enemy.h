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

	void Attack(Actor* InTarget, bool InIsBlank, int InProbability);
	//void IsShoot(Actor* InTarget); // Attack �� �������̵� �ϸ� ���� �ʿ� ����

private:
	
};

