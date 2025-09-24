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
	//void IsShoot(Actor* InTarget); // Attack 을 오버라이드 하면 굳이 필요 없음

private:
	
};

