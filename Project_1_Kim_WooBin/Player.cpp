#include "Player.h"
#include <vector>

//std::vector<Inventory> PlayerInventory = { {"Beer", 0}, {"GunPowder", 0}, {"VisionGlasses", 0}, {"GoldSack", 0} };

void APlayer::UseItem(Actor* InTarget, const std::string& InItem) // AddAttackPower()로 증가된 공격력 리셋해야함
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
		if (InItem == "GunPowder") // 턴 끝나고 InTarget->ResetAttackPower(); 호출 필요함
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


// 나중에 사용할 때, if( InvenPair.first == "Beer" ) ~~ 이런 식으로 구현 예정