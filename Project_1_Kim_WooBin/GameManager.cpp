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
	// RoundManager �׽�Ʈ
	{
		//RoundManager TestRound;

		//printf("0����\n");
		//TestRound.ResetRound(); // 0����� �׳� ResetRound()�ʱ�ȭ������. => LiveBulletProbability�� �ʱ�ȭ �� �� 0 �����Ⱑ �ȵ� | Bullet�� 0���� �ʱ�ȭ �Ұ�
		//printf("����ź ���� : %d\n��ź ���� : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
		//printf("źâ�� ���� ���� : ");
		//for (int n : TestRound.GetMagazine())
		//{
		//	printf("%d ", n);
		//}
		//printf("\n\n\n");


		//printf("1����\n");
		//TestRound.NextRound(); // �ʿ��� ��ҵ� ���� �ʱ�ȭ
		//printf("����ź ���� : %d\n��ź ���� : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
		//printf("źâ�� ���� ���� : ");
		//for (int n : TestRound.GetMagazine())
		//{
		//	printf("%d ", n);
		//}
		//printf("\n\n\n");

		//printf("2����\n");
		//TestRound.NextRound();
		//printf("����ź ���� : %d\n��ź ���� : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
		//printf("źâ�� ���� ���� : ");
		//for (int n : TestRound.GetMagazine())
		//{
		//	printf("%d ", n);
		//}
		//printf("\n\n\n");
	}


	Actor* pActorPlayer = new APlayer("Player");
	Actor* pActorEnemy = new AEnemy("�Ǹ�1");

	pActorEnemy->Attack(pActorPlayer, true, 1.5f);

	delete pActorEnemy;
	pActorEnemy = nullptr;

	delete pActorPlayer;
	pActorPlayer = nullptr;
}

void GameManager::PrintGameState() const
{
}
