#include "Enemy.h"
#include <random>

void AEnemy::Attack(Actor* InTarget, bool InIsBlank ,float InProbability) // GameManager���� GetLiveBulletProbability();�� �޾ƾ���
{
	if (InIsBlank == false)
	{
		if (InProbability >= 1)
		{
			printf("�ѱ��� ����� ���մϴ�.\n");
			printf("Baaang!!!!\n"); // ���Ŀ� �ƽ�Ű ��Ʈ�� ��ü ���
			InTarget->TakeDamage();
			//CountPlayerAttack++;
		}
		else
		{
			printf("�ѱ��� ������ ���մϴ�.\n");
			printf("Baaang!!!!\n");
			this->TakeDamage();
			//CountSelfAttack++;
		}
	}
	else
	{
		if (InProbability >= 1)
		{
			printf("�ѱ��� ����� ���մϴ�.\n");
			printf("��Ĭ....\n");
			//CountPlayerAttack++;
		}
		else
		{
			printf("�ѱ��� ������ ���մϴ�.\n");
			printf("��Ĭ....\n");
			//CountSelfAttack++;
		}
	}

	
}
