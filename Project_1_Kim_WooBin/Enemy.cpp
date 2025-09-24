#include "Enemy.h"
#include <random>

void AEnemy::IsShoot(Actor* InTarget)
{
	// 1/3확률로 본인에게 발포, 2/3확률로 플레이어에게 발포
	int Possibility = rand() % 3;
	if (Possibility == 0 || Possibility == 1)
	{
		Attack(InTarget);
	}
	else
	{
		Attack(this);
	}
}
