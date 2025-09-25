#include "Enemy.h"
#include "RoundManager.h"
#include <random>

void AEnemy::Attack(Actor* InTarget, bool InIsBlank ,float InProbability, RoundManager& InRound) // GameManager���� GetLiveBulletProbability();�� �޾ƾ���
{
	printf("<<������ ��>>\n\n");
	if (InRound.GetMagazineIndex() == InRound.GetMaxMagNumber())
	{
		InRound.ResetMagazineIndex();
		InRound.SetMagazine();
		// Debug
		printf("\n\n������ �� źâ�� ���� ���� : \n\n");
		for (int n : InRound.GetMagazine())
		{
			printf("%d ", n);
		}
		printf("\n\n");
	}

	if (InIsBlank == false)
	{
		if (InProbability >= 1)
		{
			printf("�ѱ��� ����� ���մϴ�.\n");
			printf("Baaang!!!!\n"); // ���Ŀ� �ƽ�Ű ��Ʈ�� ��ü ���
			InTarget->TakeDamage();
			SetBullseye();
		}
		else
		{
			printf("�ѱ��� ������ ���մϴ�.\n");
			printf("Baaang!!!!\n");
			this->TakeDamage();
			ResetBullseye();
		}
	}
	else
	{
		if (InProbability >= 1)
		{
			printf("�ѱ��� ����� ���մϴ�.\n");
			printf("��Ĭ....\n");
			ResetBullseye();
		}
		else
		{
			printf("�ѱ��� ������ ���մϴ�.\n");
			printf("��Ĭ....\n");
			SetBullseye();
		}
	}
	InRound.IncreaseMagazineIndex();
	
}
