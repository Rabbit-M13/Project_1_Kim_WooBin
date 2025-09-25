#include "Enemy.h"
#include <random>

void AEnemy::Attack(Actor* InTarget, bool InIsBlank ,int InProbability) // GameManager에서 GetLiveBulletProbability();로 받아야함
{
	if (InIsBlank == false)
	{
		if (InProbability >= 1)
		{
			printf("총구가 당신을 향합니다.\n");
			printf("Baaang!!!!\n"); // 추후에 아스키 아트로 대체 고려
			InTarget->TakeDamage();
			//CountPlayerAttack++;
		}
		else
		{
			printf("총구가 본인을 향합니다.\n");
			printf("Baaang!!!!\n");
			this->TakeDamage();
			//CountSelfAttack++;
		}
	}
	else
	{
		if (InProbability >= 1)
		{
			printf("총구가 당신을 향합니다.\n");
			printf("찰칵....\n");
			//CountPlayerAttack++;
		}
		else
		{
			printf("총구가 본인을 향합니다.\n");
			printf("찰칵....\n");
			//CountSelfAttack++;
		}
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
