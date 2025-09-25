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
	//Actor* pActorPlayer = new APlayer("Player");
	//Actor* pActorEnemy = new AEnemy("악마1");

	RoundManager TestRound;

	printf("0라운드\n");
	TestRound.SetMagazine();
	printf("공포탄 개수 : %d\n실탄 개수 : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	printf("탄창의 장전 순서 : ");
	for (int n : TestRound.GetMagazine())
	{
		printf("%d ", n);
	}
	printf("\n\n\n");


	printf("1라운드\n");
	TestRound.NextRound(); // 필요한 요소들 전부 초기화
	printf("공포탄 개수 : %d\n실탄 개수 : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	printf("탄창의 장전 순서 : ");
	for (int n : TestRound.GetMagazine())
	{
		printf("%d ", n);
	}
	printf("\n\n\n");

	printf("2라운드\n");
	TestRound.NextRound();
	printf("공포탄 개수 : %d\n실탄 개수 : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	printf("탄창의 장전 순서 : ");
	for (int n : TestRound.GetMagazine())
	{
		printf("%d ", n);
	}
	printf("\n\n\n");




	//delete pActorEnemy;
	//pActorEnemy = nullptr;

	//delete pActorPlayer;
	//pActorPlayer = nullptr;
}

void GameManager::PrintGameState() const
{
}
