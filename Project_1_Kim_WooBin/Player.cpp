#include "Player.h"
#include <vector>
#include <iostream>

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
		// GoldSack은 1개까지만 구매 가능하고 사용하는 아이템 아님, 골드 증가량 50% 상승할 뿐임
	}
}

bool APlayer::SetShootTarget()
{
	bool ChooseTarget = 0;
	printf("\'누구를 향해 발포할까....?\'\n상대 : 0 | 본인 : 1\n선택 : ");
	std::cin >> ChooseTarget;
	return ChooseTarget;
}

void APlayer::Attack(Actor* InTarget, bool InIsBlank)
{
	if (SetShootTarget()) // 0면 상대, 1이면 나를 타켓으로 설정 || default = 0;
	{
		if (InIsBlank)
		{
			printf("총구가 본인을 향합니다.\n");
			printf("찰칵....\n");
		}
		else
		{
			printf("총구가 본인을 향합니다.\n");
			printf("Baaang!!!!\n");
			this->TakeDamage();
		}
	}
	else
	{
		if (InIsBlank)
		{
			printf("총구가 상대를 향합니다.\n");
			printf("찰칵....\n");
		}
		else
		{
			printf("총구가 상대를 향합니다.\n");
			printf("Baaang!!!!\n");
			InTarget->TakeDamage();
		}
	}
}


// 나중에 사용할 때, if( InvenPair.first == "Beer" ) ~~ 이런 식으로 구현 예정