#include "GameManager.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "RoundManager.h"

void GameManager::Play()
{

}

// Only for Debug
void GameManager::PlayDebug()
{
	// RoundManager 테스트
	{
		//RoundManager TestRound;

		//printf("0라운드\n");
		//TestRound.ResetRound(); // 0라운드는 그냥 ResetRound()초기화해주자. => LiveBulletProbability를 초기화 할 때 0 나누기가 안됨 | Bullet들 0으로 초기화 불가
		//printf("공포탄 개수 : %d\n실탄 개수 : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
		//printf("탄창의 장전 순서 : ");
		//for (int n : TestRound.GetMagazine())
		//{
		//	printf("%d ", n);
		//}
		//printf("\n\n\n");


		//printf("1라운드\n");
		//TestRound.NextRound(); // 필요한 요소들 전부 초기화
		//printf("공포탄 개수 : %d\n실탄 개수 : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
		//printf("탄창의 장전 순서 : ");
		//for (int n : TestRound.GetMagazine())
		//{
		//	printf("%d ", n);
		//}
		//printf("\n\n\n");

		//printf("2라운드\n");
		//TestRound.NextRound();
		//printf("공포탄 개수 : %d\n실탄 개수 : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
		//printf("탄창의 장전 순서 : ");
		//for (int n : TestRound.GetMagazine())
		//{
		//	printf("%d ", n);
		//}
		//printf("\n\n\n");
	}


	Actor* pActorPlayer = new APlayer("Player");
	Actor* pActorEnemy = new AEnemy("악마1");

	pActorEnemy->Attack(pActorPlayer, true, 1.5f);

	delete pActorEnemy;
	pActorEnemy = nullptr;

	delete pActorPlayer;
	pActorPlayer = nullptr;
}

void GameManager::PrintGameState() const
{
}
