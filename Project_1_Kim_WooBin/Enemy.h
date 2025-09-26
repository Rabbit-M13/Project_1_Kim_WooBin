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

	void Attack(Actor* InTarget, bool InIsBlank, RoundManager& InRound); // InProbability 인수로 받을 필요가 없나...? 그럼 처음 판단은 어떻게 해..
																		 // Attack 함수 내부에서 설정하고 받아서 사용하면 된다.
	//void IsShoot(Actor* InTarget); // Attack 을 오버라이드 하면 굳이 필요 없음
	


private:
	
};

