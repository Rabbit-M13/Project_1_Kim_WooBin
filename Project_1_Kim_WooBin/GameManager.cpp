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
	//Actor* pActorEnemy = new AEnemy("�Ǹ�1");

	RoundManager TestRound;

	printf("0����\n");
	TestRound.SetMagazine();
	printf("����ź ���� : %d\n��ź ���� : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	printf("źâ�� ���� ���� : ");
	for (int n : TestRound.GetMagazine())
	{
		printf("%d ", n);
	}
	printf("\n\n\n");


	printf("1����\n");
	TestRound.NextRound(); // �ʿ��� ��ҵ� ���� �ʱ�ȭ
	printf("����ź ���� : %d\n��ź ���� : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	printf("źâ�� ���� ���� : ");
	for (int n : TestRound.GetMagazine())
	{
		printf("%d ", n);
	}
	printf("\n\n\n");

	printf("2����\n");
	TestRound.NextRound();
	printf("����ź ���� : %d\n��ź ���� : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	printf("źâ�� ���� ���� : ");
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
