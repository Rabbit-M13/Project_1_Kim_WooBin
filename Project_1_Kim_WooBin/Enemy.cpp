#include "Enemy.h"
#include <random>

void AEnemy::IsShoot(Actor* InTarget)
{
	// 1/3Ȯ���� ���ο��� ����, 2/3Ȯ���� �÷��̾�� ����
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
