#include "Enemy.h"
#include "RoundManager.h"
#include <random>

void AEnemy::Attack(Actor* InTarget, bool InIsBlank ,float InProbability, RoundManager& InRound) // GameManager에서 GetLiveBulletProbability();로 받아야함
{
	printf("<<상대방의 턴>>\n\n");
	if (InRound.GetMagazineIndex() == InRound.GetMaxMagNumber())
	{
		InRound.ResetMagazineIndex();
		InRound.SetMagazine();
		// Debug
		printf("\n\n재장전 된 탄창의 장전 순서 : \n\n");
		for (int n : InRound.GetMagazine())
		{
			printf("%d ", n);
		}
		printf("\n\n");
	}

	if (InIsBlank == false)
	{
		if (InProbability >= 1)
		{
			printf("총구가 당신을 향합니다.\n");
			printf("Baaang!!!!\n"); // 추후에 아스키 아트로 대체 고려
			InTarget->TakeDamage();
			SetBullseye();
		}
		else
		{
			printf("총구가 본인을 향합니다.\n");
			printf("Baaang!!!!\n");
			this->TakeDamage();
			ResetBullseye();
		}
	}
	else
	{
		if (InProbability >= 1)
		{
			printf("총구가 당신을 향합니다.\n");
			printf("찰칵....\n");
			ResetBullseye();
		}
		else
		{
			printf("총구가 본인을 향합니다.\n");
			printf("찰칵....\n");
			SetBullseye();
		}
	}
	InRound.IncreaseMagazineIndex();
	
}
