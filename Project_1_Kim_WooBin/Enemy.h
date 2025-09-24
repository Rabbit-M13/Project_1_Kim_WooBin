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

	void IsShoot(Actor* InTarget);
};

