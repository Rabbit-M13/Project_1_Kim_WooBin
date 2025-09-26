#include "Enemy.h"
#include "RoundManager.h"
#include <random>
#include <thread>      // std::this_thread::sleep_for || 상대턴 너무 빠르게 연속으로 출력되는 거 개선용
#include <chrono>      // std::chrono::seconds, std::chrono::milliseconds

void AEnemy::Attack(Actor* InTarget, bool InIsBlank , RoundManager& InRound) // GameManager에서 GetLiveBulletProbability();로 받아야함
{
	printf("<<상대방의 턴>>\n\n");

	InRound.SetLiveBulletProbability();
	float InProbability = InRound.GetLiveBulletProbability();

	printf("상대가 고민 중...\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(1800)); // 1.8초 동안 대기

	if (InProbability >= 1)
	{
		if (InIsBlank)
		{
			printf("총구가 당신을 향합니다.\n");
			printf("찰칵....\n");
			ResetBullseye();
		}
		else
		{
			printf("총구가 당신을 향합니다.\n");
			printf("Baaang!!!!\n"); // 추후에 아스키 아트로 대체 고려
			InTarget->TakeDamage();
			SetBullseye();

			
		}
	}
	else
	{
		if (InIsBlank)
		{
			printf("총구가 본인을 향합니다.\n");
			printf("찰칵....\n");
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
	InRound.IncreaseMagazineIndex();
	
}


