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
	//void IsShoot(Actor* InTarget); // Attack 을 오버라이드 하면 굳이 필요 없음

private:
	
};

