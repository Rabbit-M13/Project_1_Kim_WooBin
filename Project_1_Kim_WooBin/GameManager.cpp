#include "GameManager.h"
#include <iostream>

#include "Player.h"
#include "Enemy.h"
#include "RoundManager.h"

void GameManager::Play()
{
	APlayer* pPlayer = new APlayer("Player");
	AEnemy* pEnemy = new AEnemy("상대");
	RoundManager GameRound;

	printf("===게임 시작===\n\n\n");

	// Round 0
	printf("첫 번째 라운드\n\n");
	GameRound.ResetRound();
	printf("공포탄 개수 : %d\n실탄 개수 : %d\n", GameRound.GetBlankBullet(), GameRound.GetLiveBullet());
	printf("탄창의 장전 순서 : ");
	for (int n : GameRound.GetMagazine())
		{
			printf("%d ", n);
		}
	printf("\n");
	while (pPlayer->IsAlive() && pEnemy->IsAlive())
	{
		// 게임 진행되는 공간
		
		do
		{
			// 플레이어의 턴
			GameRound.ReloadMagazine();
			pPlayer->DisplayStatus(pEnemy);
			pPlayer->Attack(pEnemy, GameRound.IsBlank(), GameRound);
			if (!pPlayer->IsAlive()) // 이거 나중에 게임 오버 함수 따로 만들고 한 번에 처리하는 걸로 변경하자
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
			// 컴퓨터의 턴
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
		printf("Game Over...\n운명의 여신은 당신의 편이 아니었습니다...\n");
	}
	else
	{
		printf("라운드 승리!!\n다음 라운드도 살아남을 수 있을까요...?\n");
	}

	

	// Round 1
	printf("두 번째 라운드\n\n");
	GameRound.NextRound();
	pPlayer->ResetActorStatus(); // RoundManager::NextRound()에 넣으려다가 역할 구분 명확하게 분리하기 위해 따로 구현 및 호출 || GameManager에서 인수로 받아서 실행하게 통합해도 될 거 같음
	pEnemy->ResetActorStatus();
	printf("공포탄 개수 : %d\n실탄 개수 : %d\n", GameRound.GetBlankBullet(), GameRound.GetLiveBullet());
	printf("탄창의 장전 순서 : ");
	for (int n : GameRound.GetMagazine())
	{
		printf("%d ", n);
	}
	printf("\n");
	while (pPlayer->IsAlive() && pEnemy->IsAlive())
	{
		// 게임 진행되는 공간

		do
		{
			// 플레이어의 턴
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
			// 컴퓨터의 턴
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
		printf("Game Over...\n운명의 여신은 당신의 편이 아니었습니다...\n");
	}
	else
	{
		printf("라운드 승리!!\n다음 라운드도 살아남을 수 있을까요...?\n");
	}



	// Round 2
	printf("마지막 라운드\n\n");
	GameRound.NextRound();
	pPlayer->ResetActorStatus();
	pEnemy->ResetActorStatus();
	printf("공포탄 개수 : %d\n실탄 개수 : %d\n", GameRound.GetBlankBullet(), GameRound.GetLiveBullet());
	printf("탄창의 장전 순서 : ");
	for (int n : GameRound.GetMagazine())
	{
		printf("%d ", n);
	}
	printf("\n");
	while (pPlayer->IsAlive() && pEnemy->IsAlive())
	{
		// 게임 진행되는 공간

		do
		{
			// 플레이어의 턴
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
			// 컴퓨터의 턴
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
		printf("Game Over...\n운명의 여신은 당신의 편이 아니었습니다...\n");
	}
	else
	{
		printf("축하합니다!!! 당신은 최종 승리하였습니다!!\n운명의 여신은 당신의 편이었습니다!\n");
	}


	// !!중요!! Player, Enemy 메모리 해제
	delete pEnemy; // 상대방을 늦게 생성했으니까, 먼저 해제
	pEnemy = nullptr;
	delete pPlayer;
	pPlayer = nullptr;
}

// Only for Debug
void GameManager::PlayDebug()
{
	// RoundManager 테스트
	
	//{
	//	RoundManager TestRound;
	//	printf("0라운드\n");
	//	TestRound.ResetRound(); // 0라운드는 그냥 ResetRound()초기화해주자. => LiveBulletProbability를 초기화 할 때 0 나누기가 안됨 | Bullet들 0으로 초기화 불가
	//	printf("공포탄 개수 : %d\n실탄 개수 : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	//	printf("탄창의 장전 순서 : ");
	//	for (int n : TestRound.GetMagazine())
	//	{
	//		printf("%d ", n);
	//	}
	//	printf("\n");
	//	for (int n : TestRound.GetMagazine())
	//	{// IsBlank() 테스트
	//		if (TestRound.IsBlank()) // 첫 번째 탄창의 결과로 모두 출력됨
	//		{
	//			printf("B ");	// 1에서 Blank가 출력된다.
	//		}
	//		else
	//		{
	//			printf("L ");
	//		}
	//		TestRound.IncreaseMagazineIndex();
	//	}
	//	printf("\n\n\n");
	//	printf("1라운드\n");
	//	TestRound.NextRound(); // 필요한 요소들 전부 초기화
	//	printf("공포탄 개수 : %d\n실탄 개수 : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	//	printf("탄창의 장전 순서 : ");
	//	for (int n : TestRound.GetMagazine())
	//	{
	//		printf("%d ", n);
	//	}
	//	printf("\n");
	//	for (int n : TestRound.GetMagazine())
	//	{// IsBlank() 테스트
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
	//	printf("2라운드\n");
	//	TestRound.NextRound();
	//	printf("공포탄 개수 : %d\n실탄 개수 : %d\n", TestRound.GetBlankBullet(), TestRound.GetLiveBullet());
	//	printf("탄창의 장전 순서 : ");
	//	for (int n : TestRound.GetMagazine())
	//	{
	//		printf("%d ", n);
	//	}
	//	printf("\n");
	//	for (int n : TestRound.GetMagazine())
	//	{// IsBlank() 테스트
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

	// Enemy, Player 클래스 테스트
	/*{
		APlayer* pActorPlayer = new APlayer("Player");
		AEnemy* pActorEnemy = new AEnemy("악마1");

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
