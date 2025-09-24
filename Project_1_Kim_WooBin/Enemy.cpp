#include "Enemy.h"
#include <random>

void AEnemy::Attack(Actor* InTarget)
{
	// 1/3확률로 본인에게 발포, 2/3확률로 플레이어에게 발포
	// Attack방법 변경할 수 있음 => 남은 BlankBullet과 LiveBullet의 수를 전달 받아서
	// BlankBullet의 수가 더 많으면 본인 발포, LiveBullet의 수가 더 많으면 Player 발포 이런식으로
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
//	// 1/3확률로 본인에게 발포, 2/3확률로 플레이어에게 발포
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
