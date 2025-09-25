#include "GameManager.h"
#include <iostream>
#include "Player.h"
#include "Enemy.h"

void GameManager::Play()
{

}

// Only for Debug
void GameManager::PlayDebug()
{
	
	//std::string InputPlayerName;
	//printf("당신의 이름을 입력하세요 : ");
	//std::cin >> InputPlayerName;

	Actor* pActorPlayer = new APlayer("Player");
	Actor* pActorEnemy = new AEnemy("악마1");

	// Player 확인
	//printf("GetName() : %s\n", pActorPlayer->GetName().c_str());
	//printf("Player GetCurrentHealth() : %d\n", pActorPlayer->GetCurrentHealth());
	//pActorPlayer->TakeDamage();
	//pActorPlayer->TakeDamage();
	//printf("TakeDamage()*2 실행 후 체력 : %d\n", pActorPlayer->GetCurrentHealth());
	//pActorPlayer->SetCurrentHealthToMaxHealth();
	//printf("SetCurrentHealthToMaxHealth() 실행 후 체력 : %d\n", pActorPlayer->GetCurrentHealth());

	// Enemy 확인
	printf("GetName() : %s\n", pActorEnemy->GetName().c_str());
	printf("GetCurrentHealth() : %d\n", pActorEnemy->GetCurrentHealth());
	//pActorEnemy->Attack(pActorPlayer);

	int RandomTryCount = 1000000;
	for (int i = 0; i < RandomTryCount; i++)
	{
		pActorEnemy->Attack(pActorPlayer);
	}
	printf("Player Attacked Count : %d\n", pActorEnemy->CountPlayerAttack);
	printf("Player Attacked Count : %d\n", pActorEnemy->CountSelfAttack);

	//pActorEnemy->TakeDamage();
	//printf("TakeDamage() 실행 후 체력 : %d\n", pActorEnemy->GetCurrentHealth());
	//pActorPlayer->Attack(pActorEnemy);
	//printf("pActorPlayer->Attack(pActorEnemy) 실행 후 체력 : %d\n", pActorEnemy->GetCurrentHealth());
	//pActorEnemy->SetCurrentHealthToMaxHealth();
	//printf("SetCurrentHealthToMaxHealth() 실행 후 체력 : %d\n", pActorEnemy->GetCurrentHealth());

	printf("Player GetCurrentHealth() : %d\n", pActorPlayer->GetCurrentHealth());

	

	delete pActorEnemy;
	pActorEnemy = nullptr;

	delete pActorPlayer;
	pActorPlayer = nullptr;
}

void GameManager::PrintGameState() const
{
}
