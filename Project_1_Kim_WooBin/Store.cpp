#include "Store.h"
#include "Player.h"
#include "Items.h"

void Store::ShoppingTime(APlayer* InPlayer, Items* InItems)
{
	// �÷��̾��� ���� ��� �޾ƿ;� ��

	int PlayerItemChoice = 0;

	while (PlayerItemChoice != 4)
	{
		int PlayerCurrentGold = InPlayer->GetGoldLeft();

		printf("[���� ������ ������]\n");
		printf("1. ȭ�� (40G) : �� ���� ����?? �� ���� ȭ��!! (���ݷ� : +1)\n");
		printf("2. ���� (50G) : �ÿ��� ����. ���ø� Ȱ�⸦ ��ã�� �� �� ����! (����� : +1)\n");
		printf("3. ������ �Ȱ� (80G) : ��� ������ ���̴� �Ȱ�.. �����ϸ� ���𰡸� �϶վ� ���� ��������.. (���� ������ ź���� ������ �� �� �ֽ��ϴ�.)\n");
		printf("���Ÿ� ����ϴ� ������ ��ȣ�� �Է��ϼ���(���� - 4)\n");
		printf("���� : ");
		std::cin >> PlayerItemChoice;
		printf("\n\n");

		if (PlayerItemChoice < 1 || PlayerItemChoice > 4)
		{
			printf("Error : �߸��� �Է��Դϴ�! �ٽ� �Է����ּ���!\n");
			continue;
		}

		if (PlayerItemChoice == 4) {
			printf("\'����� �ѷ����� ����...\'\n");
			break;
		}

		switch (PlayerItemChoice)
		{
		case 1: // ȭ��
			{
				if (PlayerCurrentGold < InItems->GetGunpowderItemPrice())
				{
					printf("������ ��尡 �����մϴ�!\n");
					break;
				}

				// �÷��̾��� �κ��丮 ���� �̸� �ʱ�ȭ �ص־� �ϰ�, �׸��� �ƿ� �������� �ʰ� �ؾ���.
				// Key(������ �̸�)���� �޾ƿͼ� Value�� MaxItemCount�� �ʰ����� �ʴ��� üũ�ؾ���
				auto& InvenIndex = InPlayer->GetInventory();
				if (InvenIndex["ȭ��"] >= InItems->GetMaxItemCount())
				{
					InvenIndex["ȭ��"] = InItems->GetMaxItemCount();
					printf("�ִ� �ѵ��� ���� ���Դϴ�!\n");
					break;
				}

				printf("ȭ�� 1���� �����߽��ϴ�!\n");
				InPlayer->AddItem("ȭ��");
				InPlayer->BuyGunpowderSetGold(InItems);
				printf("���� �����ϰ� �ִ� ������\n");
				InPlayer->ShowInventory();

				break;
			}

		case 2: // ����
			{
				if (PlayerCurrentGold < InItems->GetBeerItemPrice())
				{
					printf("������ ��尡 �����մϴ�!\n");
					break;
				}

				// �÷��̾��� �κ��丮 ���� �̸� �ʱ�ȭ �ص־� �ϰ�, �׸��� �ƿ� �������� �ʰ� �ؾ���.
				// Key(������ �̸�)���� �޾ƿͼ� Value�� MaxItemCount�� �ʰ����� �ʴ��� üũ�ؾ���
				auto& InvenIndex = InPlayer->GetInventory();
				if (InvenIndex["����"] >= InItems->GetMaxItemCount())
				{
					InvenIndex["����"] = InItems->GetMaxItemCount();
					printf("�ִ� �ѵ��� ���� ���Դϴ�!\n");
					break;
				}

				printf("���� 1���� �����߽��ϴ�!\n");
				InPlayer->AddItem("����");
				InPlayer->BuyBeerSetGold(InItems);
				printf("���� �����ϰ� �ִ� ������\n");
				InPlayer->ShowInventory();

				break;
			}

		case 3: // ������ �Ȱ�
			{
				if (PlayerCurrentGold < InItems->GetVisionGlassItemPrice())
				{
					printf("������ ��尡 �����մϴ�!\n");
					break;
				}

				// �÷��̾��� �κ��丮 ���� �̸� �ʱ�ȭ �ص־� �ϰ�, �׸��� �ƿ� �������� �ʰ� �ؾ���.
				// Key(������ �̸�)���� �޾ƿͼ� Value�� MaxItemCount�� �ʰ����� �ʴ��� üũ�ؾ���
				auto& InvenIndex = InPlayer->GetInventory();
				if (InvenIndex["������ �Ȱ�"] >= InItems->GetMaxItemCount())
				{
					InvenIndex["������ �Ȱ�"] = InItems->GetMaxItemCount();
					printf("�ִ� �ѵ��� ���� ���Դϴ�!\n");
					break;
				}

				printf("������ �Ȱ� 1���� �����߽��ϴ�!\n");
				InPlayer->AddItem("������ �Ȱ�");
				InPlayer->BuyVisionglassesSetGold(InItems);
				printf("���� �����ϰ� �ִ� ������\n");
				InPlayer->ShowInventory();

				break;
			}

		}
	}
}
