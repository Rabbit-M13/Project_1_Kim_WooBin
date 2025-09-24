#pragma once
#include "Actor.h"

class APlayer : public Actor
{
public:
	APlayer() = default;
	APlayer(const std::string InName)
		: Actor(InName)
	{

	}
};

