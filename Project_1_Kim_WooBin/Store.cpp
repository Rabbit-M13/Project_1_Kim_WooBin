#include "Store.h"
#include "Player.h"
#include "Items.h"

void Store::ShoppingTime(APlayer* InPlayer, Items* InItems)
{
	// 플레이어의 현재 골드 받아와야 함

	

	int PlayerItemChoice = 0;

	while (PlayerItemChoice != 4)
	{
		int PlayerCurrentGold = InPlayer->GetGoldLeft();

		printf("[구매 가능한 아이템]\n");
		printf("1. 화약 (40G) : 더 강한 공격?? 더 많은 화약!! (공격력 : +1)\n");
		printf("2. 맥주 (50G) : 시원한 맥주. 마시면 활기를 되찾아 줄 것 같다! (생명력 : +1)\n");
		printf("3. 수상한 안경 (80G) : 어딘가 수상해 보이는 안경.. 착용하면 무언가를 꽤뚫어 볼수 있을지도.. (다음 장전된 탄알의 종류를 알 수 있습니다.)\n");
		printf("구매를 희망하는 아이템 번호를 입력하세요(종료 - 4)\n");
		printf("선택 : \n");

		std::cin >> PlayerItemChoice;

		if (PlayerItemChoice < 1 || PlayerItemChoice > 4)
		{
			printf("Error : 잘못된 입력입니다! 다시 입력해주세요!\n");
			continue;
		}

		switch (PlayerItemChoice)
		{
		case 1:
			if (PlayerCurrentGold < InItems->GetGunpowderItemPrice())
			{
				printf("소지한 골드가 부족합니다!\n");
				break;
			}
			// 플레이어의 인벤토리 맵을 미리 초기화 해둬야 하고, 항목이 아예 삭제되지 않게 해야함.
			// Key(아이템 이름)값을 받아와서 Value가 MaxItemCount를 초과하지 않는지 체크해야함
			if (InPlayer.)
			{
				printf("소지한 골드가 부족합니다!\n");
				break;
			}
			printf("화약 1개를 구매했습니다!\n");
			InPlayer->AddItem("화약");
			printf("현재 소지하고 있는 아이템\n");
			
			break;

		case 2:

		}
	}
}
