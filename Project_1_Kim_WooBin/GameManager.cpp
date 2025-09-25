#include "GameManager.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "RoundManager.h"

void GameManager::Play()
{
	APlayer* pPlayer = new APlayer("Player");
	AEnemy* pEnemy = new AEnemy("�Ǹ�1");
	RoundManager GameRound;

	printf("===���� ����===\n\n\n");

	// Round 0
	printf("ù ��° ����\n\n");
	GameRound.ResetRound();
	printf("����ź ���� : %d\n��ź ���� : %d\n", GameRound.GetBlankBullet(), GameRound.GetLiveBullet());
	printf("źâ�� ���� ���� : ");
	for (int n : GameRound.GetMagazine())
		{
			printf("%d ", n);
		}
	printf("\n");
	while (pPlayer->IsAlive() || pEnemy->IsAlive())
	{
		// ���� ����Ǵ� ����

		do
		{
			pPlayer->Attack(pEnemy, GameRound.IsBlank(), GameRound);
		} while (pPlayer->GetBullseye());
		
		do
		{
			pEnemy->Attack(pPlayer, GameRound.IsBlank(), GameRound.GetLiveBulletProbability(), GameRound);
		} while (pEnemy->GetBullseye());

	}
	if (!pPlayer->IsAlive())
	{
		printf("Game Over...\n����� ������ ����� ���� �ƴϾ����ϴ�...\n");
	}
	else
	{
		printf("���� �¸�!!\n���� ���嵵 ��Ƴ��� �� �������...?\n");
	}


	// Round 1
	printf("�� ��° ����\n\n");
	GameRound.NextRound();
	printf("����ź ���� : %d\n��ź ���� : %d\n", GameRound.GetBlankBullet(), GameRound.GetLiveBullet());
	printf("źâ�� ���� ���� : ");
	for (int n : GameRound.GetMagazine())
	{
		printf("%d ", n);
	}
	printf("\n");
	while (pPlayer->IsAlive() || pEnemy->IsAlive())
	{
		// ���� ����Ǵ� ����

		do
		{
			pPlayer->Attack(pEnemy, GameRound.IsBlank(), GameRound);
		} while (pPlayer->GetBullseye());

		do
		{
			pEnemy->Attack(pPlayer, GameRound.IsBlank(), GameRound.GetLiveBulletProbability(), GameRound);
		} while (pEnemy->GetBullseye());

	}
	if (!pPlayer->IsAlive())
	{
		printf("Game Over...\n����� ������ ����� ���� �ƴϾ����ϴ�...\n");
	}
	else
	{
		printf("���� �¸�!!\n���� ���嵵 ��Ƴ��� �� �������...?\n");
	}
	
	
	// Round 2
	printf("������ ����\n\n");
	GameRound.NextRound();
	printf("����ź ���� : %d\n��ź ���� : %d\n", GameRound.GetBlankBullet(), GameRound.GetLiveBullet());
	printf("źâ�� ���� ���� : ");
	for (int n : GameRound.GetMagazine())
	{
		printf("%d ", n);
	}
	printf("\n");
	while (pPlayer->IsAlive() || pEnemy->IsAlive())
	{
		// ���� ����Ǵ� ����

		do
		{
			pPlayer->Attack(pEnemy, GameRound.IsBlank(), GameRound);
		} while (pPlayer->GetBullseye());

		do
		{
			pEnemy->Attack(pPlayer, GameRound.IsBlank(), GameRound.GetLiveBulletProbability(), GameRound);
		} while (pEnemy->GetBullseye());

	}
	if (!pPlayer->IsAlive())
	{
		printf("Game Over...\n����� ������ ����� ���� �ƴϾ����ϴ�...\n");
	}
	else
	{
		printf("�����մϴ�!!! ����� ���� �¸��Ͽ����ϴ�!!\n����� ������ ����� ���̾����ϴ�!\n");
	}

	// !!�߿�!! Player, Enemy �޸� ����
	delete pEnemy;
	pEnemy = nullptr;
	delete pPlayer;
	pPlayer = nullptr;
}

// Only for Debug
void GameManager::PlayDebug()
{
	// RoundManager �׽�Ʈ
	
	//{
	//	RoundManager TestRound;
	//	printf("0����\n");
	//	TestRound.ResetRound(); // 0����� �׳� ResetRound()�ʱ�ȭ������. => LiveBulletProbability�� �ʱ�ȭ �� �� 0 �����Ⱑ �ȵ� | Bullet�� 0���� �ʱ�ȭ �Ұ�
	//	printf("����ź ���� : %d\n��ź ���� : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	//	printf("źâ�� ���� ���� : ");
	//	for (int n : TestRound.GetMagazine())
	//	{
	//		printf("%d ", n);
	//	}
	//	printf("\n");
	//	for (int n : TestRound.GetMagazine())
	//	{// IsBlank() �׽�Ʈ
	//		if (TestRound.IsBlank()) // ù ��° źâ�� ����� ��� ��µ�
	//		{
	//			printf("B ");	// 1���� Blank�� ��µȴ�.
	//		}
	//		else
	//		{
	//			printf("L ");
	//		}
	//		TestRound.IncreaseMagazineIndex();
	//	}
	//	printf("\n\n\n");
	//	printf("1����\n");
	//	TestRound.NextRound(); // �ʿ��� ��ҵ� ���� �ʱ�ȭ
	//	printf("����ź ���� : %d\n��ź ���� : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	//	printf("źâ�� ���� ���� : ");
	//	for (int n : TestRound.GetMagazine())
	//	{
	//		printf("%d ", n);
	//	}
	//	printf("\n");
	//	for (int n : TestRound.GetMagazine())
	//	{// IsBlank() �׽�Ʈ
	//		
	//		if (TestRound.IsBlank())
	//		{
	//			printf("B ");
	//		}
	//		else
	//		{
	//			printf("L ");
	//		}
	//		TestRound.IncreaseMagazineIndex();
	//	}
	//	printf("\n\n\n");
	//	printf("2����\n");
	//	TestRound.NextRound();
	//	printf("����ź ���� : %d\n��ź ���� : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	//	printf("źâ�� ���� ���� : ");
	//	for (int n : TestRound.GetMagazine())
	//	{
	//		printf("%d ", n);
	//	}
	//	printf("\n");
	//	for (int n : TestRound.GetMagazine())
	//	{// IsBlank() �׽�Ʈ
	//		
	//		if (TestRound.IsBlank())
	//		{
	//			printf("B ");
	//		}
	//		else
	//		{
	//			printf("L ");
	//		}
	//		TestRound.IncreaseMagazineIndex();
	//	}
	//	printf("\n\n\n");
	//}

	// Enemy, Player Ŭ���� �׽�Ʈ
	/*{
		APlayer* pActorPlayer = new APlayer("Player");
		AEnemy* pActorEnemy = new AEnemy("�Ǹ�1");

		pActorEnemy->Attack(pActorPlayer, true, 1.5f);
		pActorPlayer->Attack(pActorEnemy, true, TestRound);
		pActorPlayer->Attack(pActorEnemy, false, TestRound);

		delete pActorEnemy;
		pActorEnemy = nullptr;

		delete pActorPlayer;
		pActorPlayer = nullptr;
	}*/

}

void GameManager::PrintGameState() const
{
}
