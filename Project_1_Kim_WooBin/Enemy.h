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

	void Attack(Actor* InTarget, bool InIsBlank, RoundManager& InRound); // InProbability �μ��� ���� �ʿ䰡 ����...? �׷� ó�� �Ǵ��� ��� ��..
																		 // Attack �Լ� ���ο��� �����ϰ� �޾Ƽ� ����ϸ� �ȴ�.
	//void IsShoot(Actor* InTarget); // Attack �� �������̵� �ϸ� ���� �ʿ� ����
	


private:
	
};

