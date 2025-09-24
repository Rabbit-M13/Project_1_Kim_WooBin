#include "Enemy.h"
#include <random>

void AEnemy::Attack(Actor* InTarget)
{
	// 1/3Ȯ���� ���ο��� ����, 2/3Ȯ���� �÷��̾�� ����
	// Attack��� ������ �� ���� => ���� BlankBullet�� LiveBullet�� ���� ���� �޾Ƽ�
	// BlankBullet�� ���� �� ������ ���� ����, LiveBullet�� ���� �� ������ Player ���� �̷�������
	int Possibility = rand() % 3;
	//printf("Possibility : %d\n", Possibility);
	if (Possibility == 0 || Possibility == 1)
	{
		InTarget->TakeDamage();
		CountPlayerAttack++;
	}
	else
	{
		InTarget->TakeDamage();
		CountSelfAttack++;
	}
}

//void AEnemy::IsShoot(Actor* InTarget)
//{
//	// 1/3Ȯ���� ���ο��� ����, 2/3Ȯ���� �÷��̾�� ����
//	int Possibility = rand() % 3;
//	printf("Possibility : %d", Possibility);
//	if (Possibility == 0 || Possibility == 1)
//	{
//		Attack(InTarget);
//	}
//	else
//	{
//		Attack(this);
//	}
//}
