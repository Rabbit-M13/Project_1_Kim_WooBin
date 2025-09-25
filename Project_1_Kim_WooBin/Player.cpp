#include "Player.h"
#include <vector>
#include <iostream>

//std::vector<Inventory> PlayerInventory = { {"Beer", 0}, {"GunPowder", 0}, {"VisionGlasses", 0}, {"GoldSack", 0} };

void APlayer::UseItem(Actor* InTarget, const std::string& InItem) // AddAttackPower()�� ������ ���ݷ� �����ؾ���
{
	if (Inventory.find(InItem) != Inventory.end())
	{
		if (InItem == "Beer")
		{
			InTarget->AddHealth();

			Inventory[InItem] -= 1;

			if (Inventory[InItem] <= 0)
			{
				Inventory.erase(InItem);
			}
		}
		if (InItem == "GunPowder") // �� ������ InTarget->ResetAttackPower(); ȣ�� �ʿ���
		{
			InTarget->AddAttackPower();

			Inventory[InItem] -= 1;

			if (Inventory[InItem] <= 0)
			{
				Inventory.erase(InItem);
			}
		}
		if (InItem == "VisionGlasses")
		{
			Inventory[InItem] -= 1;

			if (Inventory[InItem] <= 0)
			{
				Inventory.erase(InItem);
			}
		}
		// GoldSack�� 1�������� ���� �����ϰ� ����ϴ� ������ �ƴ�, ��� ������ 50% ����� ����
	}
}

bool APlayer::SetShootTarget()
{
	bool ChooseTarget = 0;
	printf("\'������ ���� �����ұ�....?\'\n��� : 0 | ���� : 1\n���� : ");
	std::cin >> ChooseTarget;
	return ChooseTarget;
}

void APlayer::Attack(Actor* InTarget, bool InIsBlank)
{
	if (SetShootTarget()) // 0�� ���, 1�̸� ���� Ÿ������ ���� || default = 0;
	{
		if (InIsBlank)
		{
			printf("�ѱ��� ������ ���մϴ�.\n");
			printf("��Ĭ....\n");
		}
		else
		{
			printf("�ѱ��� ������ ���մϴ�.\n");
			printf("Baaang!!!!\n");
			this->TakeDamage();
		}
	}
	else
	{
		if (InIsBlank)
		{
			printf("�ѱ��� ��븦 ���մϴ�.\n");
			printf("��Ĭ....\n");
		}
		else
		{
			printf("�ѱ��� ��븦 ���մϴ�.\n");
			printf("Baaang!!!!\n");
			InTarget->TakeDamage();
		}
	}
}


// ���߿� ����� ��, if( InvenPair.first == "Beer" ) ~~ �̷� ������ ���� ����