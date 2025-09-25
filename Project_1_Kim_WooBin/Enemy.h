#pragma once
#include "Actor.h"

class RoundManager; // Attack()에서 RoundManger 타입을 인수로 받기 위해 전방 선언

class AEnemy : public Actor
{
public:
	AEnemy() = default;
	AEnemy(const std::string InName)
		: Actor(InName)
	{

	}

	void Attack(Actor* InTarget, bool InIsBlank, float InProbability, RoundManager& InRound);
	//void IsShoot(Actor* InTarget); // Attack 을 오버라이드 하면 굳이 필요 없음
	


private:
	
};

