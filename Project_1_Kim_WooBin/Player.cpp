#include "Player.h"
#include "RoundManager.h"
//#include "Items.h" ���߿� �̰� ����ϸ� ����� �ִ°Ŷ� �������� �𸣴ϱ� ����
#include <vector>
#include <iostream>

//std::vector<Inventory> PlayerInventory = { {"Beer", 0}, {"GunPowder", 0}, {"VisionGlasses", 0}, {"GoldSack", 0} };

void APlayer::AddItem(const std::string& InItem)
{
	// Store���� �����ϸ� ������ ����
	Inventory[InItem] += 1;
}

void APlayer::UseItem(Actor* InTarget, const std::string& InItem) // AddAttackPower()�� ������ ���ݷ� �����ؾ���
{
	if (Inventory.find(InItem) != Inventory.end())
	{
		if (InItem == "����")
		{
			InTarget->AddHealth();

			Inventory[InItem] -= 1;

			if (Inventory[InItem] <= 0)
			{
				Inventory[InItem] = 0;
			}
		}
		if (InItem == "ȭ��") // �� ������ InTarget->ResetAttackPower(); ȣ�� �ʿ���
		{
			InTarget->AddAttackPower();

			Inventory[InItem] -= 1;

			if (Inventory[InItem] <= 0)
			{
				Inventory[InItem] = 0;
			}
		}
		if (InItem == "������ �Ȱ�")
		{
			Inventory[InItem] -= 1;

			if (Inventory[InItem] <= 0)
			{
				Inventory[InItem] = 0;
			}
		}
	}
}

void APlayer::ShowInventory() const
{
	printf("[ ");
	bool first = true;
	for (const auto& Index : Inventory)
	{
		if (!first) {
			printf(" | ");
		}
		printf("%s : %d", Index.first.c_str(), Index.second);
		first = false;
	}
	printf(" ]\n");
}

bool APlayer::SetShootTarget()
{
	bool ChooseTarget = 0;
	printf("\'������ ���� �����ұ�....?\'\n��� : 0 | ���� : 1\n���� : ");
	std::cin >> ChooseTarget;
	return ChooseTarget;
}

void APlayer::Attack(Actor* InTarget, bool InIsBlank, RoundManager& InRound)
{
	printf("<<����� ��>>\n\n");

	// źâ ��� �Ҹ� �� ������ => ReloadMagazine()���� ���� �����ϰ� Attack() ���� ȣ��
	//if (InRound.GetMagazineIndex() == InRound.GetMaxMagNumber())
	//{
	//	InRound.ClearMagazine();
	//	InRound.ResetMagazineIndex();
	//	InRound.SetMagazine();
	//	// Debug
	//	printf("\n\n������ �� źâ�� ���� ���� : ");
	//	for (int n : InRound.GetMagazine())
	//	{
	//		printf("%d ", n);
	//	}
	//	printf("\n\n");
	//}
	

	if (SetShootTarget()) // 0�� ���, 1�̸� ���� Ÿ������ ���� || default = 0;
	{
		if (InIsBlank)
		{
			printf("�ѱ��� ������ ���մϴ�.\n");
			printf("��Ĭ....\n");
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
		if (InIsBlank)
		{
			printf("�ѱ��� ��븦 ���մϴ�.\n");
			printf("��Ĭ....\n");
			ResetBullseye();
		}
		else
		{
			printf("�ѱ��� ��븦 ���մϴ�.\n");
			printf("Baaang!!!!\n");
			InTarget->TakeDamage();
			SetBullseye();
		}
	}
	InRound.IncreaseMagazineIndex();
}


// ���߿� ����� ��, if( InvenPair.first == "Beer" ) ~~ �̷� ������ ���� ����