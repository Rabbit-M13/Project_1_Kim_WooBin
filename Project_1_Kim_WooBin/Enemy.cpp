#include "Enemy.h"
#include <random>

void AEnemy::Attack(Actor* InTarget, bool InIsBlank ,int InProbability) // GameManager���� GetLiveBulletProbability();�� �޾ƾ���
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

//void AEnemy::IsShoot(Actor* InTarget)
//{
//	// 1/3Ȯ���� ���ο��� ����, 2/3Ȯ���� �÷��̾�� ����
//	int Possibility = rand() % 3;
//	printf("Possibility : %d", Possibility);
//	if (Possibility == 0 || Possibility == 1)
//	{
//		Attack(InTarget);
//	}
//	else
//	{
//		Attack(this);
//	}
//}
