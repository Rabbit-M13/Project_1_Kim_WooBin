#pragma once
#include "Actor.h"

class RoundManager; // Attack()���� RoundManger Ÿ���� �μ��� �ޱ� ���� ���� ����

class AEnemy : public Actor
{
public:
	AEnemy() = default;
	AEnemy(const std::string InName)
		: Actor(InName)
	{

	}

	void Attack(Actor* InTarget, bool InIsBlank, float InProbability, RoundManager& InRound);
	//void IsShoot(Actor* InTarget); // Attack �� �������̵� �ϸ� ���� �ʿ� ����
	


private:
	
};

