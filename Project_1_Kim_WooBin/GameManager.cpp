#include "GameManager.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"

void GameManager::Play()
{

}

void GameManager::PlayDebug() /*!!!!!!!!!!  ���� Attack�������� �׽�Ʈ �ϱ�  !!!!!!!!!!!*/
{
	// 
	std::string InputPlayerName;
	printf("����� �̸��� �Է��ϼ��� : ");
	std::cin >> InputPlayerName;

	Actor* pActorPlayer = new APlayer(InputPlayerName);
	Actor* pActorEnemy = new AEnemy();

	// Player Ȯ��
	/*printf("GetName() : %s\n", pActorPlayer->GetName().c_str());
	printf(">GetCurrentHealth() : %d\n", pActorPlayer->GetCurrentHealth());
	pActorPlayer->TakeDamage();
	pActorPlayer->TakeDamage();
	printf("TakeDamage()*2 ���� �� ü�� : %d\n", pActorPlayer->GetCurrentHealth());
	pActorPlayer->SetCurrentHealthToMaxHealth();
	printf("SetCurrentHealthToMaxHealth() ���� �� ü�� : %d\n", pActorPlayer->GetCurrentHealth());*/

	// Enemy Ȯ��
	/*printf("GetName() : %s\n", pActorEnemy->GetName().c_str());
	printf(">GetCurrentHealth() : %d\n", pActorEnemy->GetCurrentHealth());
	pActorEnemy->TakeDamage();
	printf("TakeDamage() ���� �� ü�� : %d\n", pActorEnemy->GetCurrentHealth());
	pActorPlayer->Attack(pActorEnemy);
	printf("pActorPlayer->Attack(pActorEnemy) ���� �� ü�� : %d\n", pActorEnemy->GetCurrentHealth());
	pActorEnemy->SetCurrentHealthToMaxHealth();
	printf("SetCurrentHealthToMaxHealth() ���� �� ü�� : %d\n", pActorEnemy->GetCurrentHealth());*/



	delete pActorEnemy;
	pActorEnemy = nullptr;

	delete pActorPlayer;
	pActorPlayer = nullptr;
}

void GameManager::PrintGameState() const
{
}
