#include "GameManager.h"
#include <iostream>
#include <cstdlib> // ���� �� Game Over ���� �ʿ�
#include "Player.h"
#include "Enemy.h"
#include "RoundManager.h"
#include "Store.h"
#include "Items.h"

//void GameManager::Run() // �켱 ���� �ϼ��ϰ� ������.
//{
//	while (true)
//	{
//		IsGameAlive = true;
//		Play();
//
//	}
//
//}

void GameManager::Play() // ��ü �ϳ��� �ݺ������� ���ΰ� ������� �� �ְ� ������.
{
	while (IsGameAlive)
	{
		APlayer* pPlayer = new APlayer("Player");
		AEnemy* pEnemy = new AEnemy("���");
		RoundManager GameRound;

		printf("===���� ����===\n\n\n");

		// Round 0
		printf("\n\n[ù ��° ����]\n\n");
		GameRound.ResetRound();
		printf("����ź ���� : %d\n��ź ���� : %d\n", GameRound.GetBlankBullet(), GameRound.GetLiveBullet());
		/*printf("źâ�� ���� ���� : ");
		for (int n : GameRound.GetMagazine())
		{
			printf("%d ", n);
		}
		printf("\n");*/
		while (pPlayer->IsAlive() && pEnemy->IsAlive())
		{
			// ���� ����Ǵ� ����

			do
			{
				// �÷��̾��� ��
				GameRound.ReloadMagazine();
				pPlayer->DisplayStatus(pEnemy);
				pPlayer->Attack(pEnemy, GameRound.IsBlank(), GameRound);
				if (!pPlayer->IsAlive()) // �̰� ���߿� ���� ���� �Լ� ���� ����� �� ���� ó���ϴ� �ɷ� ��������
				{
					break;
				}
				if (!pEnemy->IsAlive())
				{
					break;
				}
			} while (pPlayer->GetBullseye());
			if (!pPlayer->IsAlive())
			{
				break;
			}
			if (!pEnemy->IsAlive())
			{
				break;
			}

			do
			{
				// ��ǻ���� ��
				GameRound.ReloadMagazine();
				pEnemy->Attack(pPlayer, GameRound.IsBlank(), GameRound);
				if (!pPlayer->IsAlive())
				{
					break;
				}
				if (!pEnemy->IsAlive())
				{
					break;
				}
			} while (pEnemy->GetBullseye());
			if (!pPlayer->IsAlive())
			{
				break;
			}
			if (!pEnemy->IsAlive())
			{
				break;
			}

		}
		if (!pPlayer->IsAlive())
		{
			printf("Game Over...\n����� ������ ����� ���� �ƴϾ����ϴ�...\n");
			delete pEnemy;
			pEnemy = nullptr;
			delete pPlayer;
			pPlayer = nullptr;
			break;
		}
		else
		{
			printf("\n\n���� �¸�!!\n���� ���嵵 ��Ƴ��� �� �������...?\n");
			printf("[��� ���� +120]\n\n");
			GameRound.RoundClearReward(pPlayer);
		}


		/*���� ��*/
		Store* pStore = new Store();
		Items* pItems = new Items();
		pStore->StoreOpen();
		pStore->ShoppingTime(pPlayer, pItems);
		pStore->StoreClose();
		// Items ������ ���� ����ÿ� �����ϸ� �ȴ�.
		

		// Round 1
		printf("\n\n[�� ��° ����]\n\n");
		GameRound.NextRound();
		pPlayer->ResetActorStatus(); // RoundManager::NextRound()�� �������ٰ� ���� ���� ��Ȯ�ϰ� �и��ϱ� ���� ���� ���� �� ȣ�� || GameManager���� �μ��� �޾Ƽ� �����ϰ� �����ص� �� �� ����
		pEnemy->ResetActorStatus();
		printf("����ź ���� : %d\n��ź ���� : %d\n", GameRound.GetBlankBullet(), GameRound.GetLiveBullet());
		/*printf("źâ�� ���� ���� : ");
		for (int n : GameRound.GetMagazine())
		{
			printf("%d ", n);
		}
		printf("\n");*/
		while (pPlayer->IsAlive() && pEnemy->IsAlive())
		{
			// ���� ����Ǵ� ����

			do
			{
				// �÷��̾��� ��
				GameRound.ReloadMagazine();
				pPlayer->DisplayStatus(pEnemy);
				pPlayer->Attack(pEnemy, GameRound.IsBlank(), GameRound);
				if (!pPlayer->IsAlive())
				{
					break;
				}
				if (!pEnemy->IsAlive())
				{
					break;
				}
			} while (pPlayer->GetBullseye());
			if (!pPlayer->IsAlive())
			{
				break;
			}
			if (!pEnemy->IsAlive())
			{
				break;
			}

			do
			{
				// ��ǻ���� ��
				GameRound.ReloadMagazine();
				pEnemy->Attack(pPlayer, GameRound.IsBlank(), GameRound);
				if (!pPlayer->IsAlive())
				{
					break;
				}
				if (!pEnemy->IsAlive())
				{
					break;
				}
			} while (pEnemy->GetBullseye());
			if (!pPlayer->IsAlive())
			{
				break;
			}
			if (!pEnemy->IsAlive())
			{
				break;
			}

		}
		if (!pPlayer->IsAlive())
		{
			printf("Game Over...\n����� ������ ����� ���� �ƴϾ����ϴ�...\n");
			delete pItems;
			pItems = nullptr;
			delete pStore;
			pStore = nullptr;
			delete pEnemy;
			pEnemy = nullptr;
			delete pPlayer;
			pPlayer = nullptr;
			break;
		}
		else
		{
			printf("���� �¸�!!\n���� ���嵵 ��Ƴ��� �� �������...?\n");
			printf("[��� ���� +120]\n");
			GameRound.RoundClearReward(pPlayer);
		}


		/*���� ��*/
		pStore->StoreOpen();
		pStore->ShoppingTime(pPlayer, pItems);
		pStore->StoreClose();

		// Round 2
		printf("\n\n[������ ����]\n\n");
		GameRound.NextRound();
		pPlayer->ResetActorStatus();
		pEnemy->ResetActorStatus();
		printf("����ź ���� : %d\n��ź ���� : %d\n", GameRound.GetBlankBullet(), GameRound.GetLiveBullet());
		/*printf("źâ�� ���� ���� : ");
		for (int n : GameRound.GetMagazine())
		{
			printf("%d ", n);
		}
		printf("\n");*/
		while (pPlayer->IsAlive() && pEnemy->IsAlive())
		{
			// ���� ����Ǵ� ����

			do
			{
				// �÷��̾��� ��
				GameRound.ReloadMagazine();
				pPlayer->DisplayStatus(pEnemy);
				pPlayer->Attack(pEnemy, GameRound.IsBlank(), GameRound);
				if (!pPlayer->IsAlive())
				{
					break;
				}
				if (!pEnemy->IsAlive())
				{
					break;
				}
			} while (pPlayer->GetBullseye());
			if (!pPlayer->IsAlive())
			{
				break;
			}
			if (!pEnemy->IsAlive())
			{
				break;
			}

			do
			{
				// ��ǻ���� ��
				GameRound.ReloadMagazine();
				pEnemy->Attack(pPlayer, GameRound.IsBlank(), GameRound);
				if (!pPlayer->IsAlive())
				{
					break;
				}
				if (!pEnemy->IsAlive())
				{
					break;
				}
			} while (pEnemy->GetBullseye());
			if (!pPlayer->IsAlive())
			{
				break;
			}
			if (!pEnemy->IsAlive())
			{
				break;
			}

		}
		if (!pPlayer->IsAlive())
		{
			printf("Game Over...\n����� ������ ����� ���� �ƴϾ����ϴ�...\n");
			delete pItems;
			pItems = nullptr;
			delete pStore;
			pStore = nullptr;
			delete pEnemy;
			pEnemy = nullptr;
			delete pPlayer;
			pPlayer = nullptr;
			break;
		}
		else
		{
			printf("�����մϴ�!!! ����� ���� �¸��Ͽ����ϴ�!!\n����� ������ ����� ���̾����ϴ�!\n");
		}


		// !!�߿�!! Player, Enemy �޸� ����
		delete pItems;
		pItems = nullptr;
		delete pStore;
		pStore = nullptr;
		delete pEnemy; // ������ �ʰ� ���������ϱ�, ���� ����
		pEnemy = nullptr;
		delete pPlayer;
		pPlayer = nullptr;

		RestartGame(); // ���� ����� ���� ���� || ���� �߰��� �״°� ������� �ȵȴ�. 
	}
	
	
	printf("===================================���� ���� ����===================================");
	
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

void GameManager::SetIsGameAlive(APlayer* InPlayer)
{
	if (!InPlayer->IsAlive())
	{
		IsGameAlive = false;
	}
}

void GameManager::RestartGame()
{
	char InRestartChar = 'a';
	printf("������ ������ұ��??\n����� - R || ���� ���� - X\n�Է� : ");
	

	while (1)
	{
		std::cin >> InRestartChar;
		if (InRestartChar == 'R' || InRestartChar == 'r')
		{
			IsGameAlive = true;
			break;
		}
		else if (InRestartChar == 'X' || InRestartChar == 'x')
		{
			IsGameAlive = false;
			break;
		}
		else
		{
			printf("��ȿ�� �Է��� �ƴմϴ�! �ٽ� �Է��ϼ���!\n�Է� : ");
		}
	}
	
}
