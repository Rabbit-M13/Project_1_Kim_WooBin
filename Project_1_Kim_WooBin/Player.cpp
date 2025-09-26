#include "Player.h"
#include "RoundManager.h"
//#include "Items.h" 나중에 이거 사용하면 헤더에 있는거랑 꼬일지도 모르니까 주의
#include <vector>
#include <iostream>

//std::vector<Inventory> PlayerInventory = { {"Beer", 0}, {"GunPowder", 0}, {"VisionGlasses", 0}, {"GoldSack", 0} };

void APlayer::AddItem(const std::string& InItem)
{
	// Store에서 구매하면 아이템 저장
	Inventory[InItem] += 1;
}

void APlayer::UseItem(Actor* InTarget, const std::string& InItem) // AddAttackPower()로 증가된 공격력 리셋해야함
{
	if (Inventory.find(InItem) != Inventory.end())
	{
		if (InItem == "맥주")
		{
			InTarget->AddHealth();

			Inventory[InItem] -= 1;

			if (Inventory[InItem] <= 0)
			{
				Inventory[InItem] = 0;
			}
		}
		if (InItem == "화약") // 턴 끝나고 InTarget->ResetAttackPower(); 호출 필요함
		{
			InTarget->AddAttackPower();

			Inventory[InItem] -= 1;

			if (Inventory[InItem] <= 0)
			{
				Inventory[InItem] = 0;
			}
		}
		if (InItem == "수상한 안경")
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
	printf("\'누구를 향해 발포할까....?\'\n상대 : 0 | 본인 : 1\n선택 : ");
	std::cin >> ChooseTarget;
	return ChooseTarget;
}

void APlayer::Attack(Actor* InTarget, bool InIsBlank, RoundManager& InRound)
{
	printf("<<당신의 턴>>\n\n");

	// 탄창 모두 소모 시 재장전 => ReloadMagazine()으로 따로 구현하고 Attack() 전에 호출
	//if (InRound.GetMagazineIndex() == InRound.GetMaxMagNumber())
	//{
	//	InRound.ClearMagazine();
	//	InRound.ResetMagazineIndex();
	//	InRound.SetMagazine();
	//	// Debug
	//	printf("\n\n재장전 된 탄창의 장전 순서 : ");
	//	for (int n : InRound.GetMagazine())
	//	{
	//		printf("%d ", n);
	//	}
	//	printf("\n\n");
	//}
	

	if (SetShootTarget()) // 0면 상대, 1이면 나를 타켓으로 설정 || default = 0;
	{
		if (InIsBlank)
		{
			printf("총구가 본인을 향합니다.\n");
			printf("찰칵....\n");
			SetBullseye();
		}
		else
		{
			printf("총구가 본인을 향합니다.\n");
			printf("Baaang!!!!\n");
			this->TakeDamage();
			ResetBullseye();
		}
	}
	else
	{
		if (InIsBlank)
		{
			printf("총구가 상대를 향합니다.\n");
			printf("찰칵....\n");
			ResetBullseye();
		}
		else
		{
			printf("총구가 상대를 향합니다.\n");
			printf("Baaang!!!!\n");
			InTarget->TakeDamage();
			SetBullseye();
		}
	}
	InRound.IncreaseMagazineIndex();
}


// 나중에 사용할 때, if( InvenPair.first == "Beer" ) ~~ 이런 식으로 구현 예정