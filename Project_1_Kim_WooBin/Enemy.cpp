#include "Enemy.h"
#include <random>

void AEnemy::Attack(Actor* InTarget, bool InIsBlank ,float InProbability) // GameManager에서 GetLiveBulletProbability();로 받아야함
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
