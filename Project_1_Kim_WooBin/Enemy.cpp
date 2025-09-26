#include "Enemy.h"
#include "RoundManager.h"
#include <random>
#include <thread>      // std::this_thread::sleep_for || ����� �ʹ� ������ �������� ��µǴ� �� ������
#include <chrono>      // std::chrono::seconds, std::chrono::milliseconds

void AEnemy::Attack(Actor* InTarget, bool InIsBlank , RoundManager& InRound) // GameManager���� GetLiveBulletProbability();�� �޾ƾ���
{
	printf("<<������ ��>>\n\n");

	InRound.SetLiveBulletProbability();
	float InProbability = InRound.GetLiveBulletProbability();

	printf("��밡 ��� ��...\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(1800)); // 1.8�� ���� ���

	if (InProbability >= 1)
	{
		if (InIsBlank)
		{
			printf("�ѱ��� ����� ���մϴ�.\n");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 1�� ���� ���
			printf("��Ĭ....\n\n");
			ResetBullseye();
		}
		else
		{
			printf("�ѱ��� ����� ���մϴ�.\n");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 1�� ���� ���
			printf("Baaang!!!!\n\n"); // ���Ŀ� �ƽ�Ű ��Ʈ�� ��ü ���
			InTarget->TakeDamage();
			SetBullseye();

			
		}
	}
	else
	{
		if (InIsBlank)
		{
			printf("�ѱ��� ������ ���մϴ�.\n");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			printf("��Ĭ....\n\n");
			SetBullseye();
		}
		else
		{
			printf("�ѱ��� ������ ���մϴ�.\n");
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			printf("Baaang!!!!\n\n");
			this->TakeDamage();
			ResetBullseye();
		}
	}
	InRound.IncreaseMagazineIndex();
	
}


