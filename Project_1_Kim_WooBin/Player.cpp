#include "Player.h"
#include <vector>

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
		if (InItem == "GoldSack")
		{
			Inventory[InItem] -= 1;

			if (Inventory[InItem] <= 0)
			{
				Inventory.erase(InItem);
			}
		}
	}
}


// ���߿� ����� ��, if( InvenPair.first == "Beer" ) ~~ �̷� ������ ���� ����