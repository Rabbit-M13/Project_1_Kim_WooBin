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
		printf("���� : \n");

		std::cin >> PlayerItemChoice;

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
				if (InPlayer->GetInventory()["ȭ��"] >= InItems->GetMaxItemCount())
				{
					InPlayer->GetInventory()["ȭ��"] = 3;
					printf("�ִ� �ѵ��� ���� ���Դϴ�!\n");
					break;
				}

				printf("ȭ�� 1���� �����߽��ϴ�!\n");
				InPlayer->AddItem("ȭ��");
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
				if (InPlayer->GetInventory()["����"] >= InItems->GetMaxItemCount())
				{
					InPlayer->GetInventory()["����"] = 3;
					printf("�ִ� �ѵ��� ���� ���Դϴ�!\n");
					break;
				}

				printf("���� 1���� �����߽��ϴ�!\n");
				InPlayer->AddItem("����");
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
				if (InPlayer->GetInventory()["������ �Ȱ�"] >= InItems->GetMaxItemCount())
				{
					InPlayer->GetInventory()["������ �Ȱ�"] = 3;
					printf("�ִ� �ѵ��� ���� ���Դϴ�!\n");
					break;
				}

				printf("������ �Ȱ� 1���� �����߽��ϴ�!\n");
				InPlayer->AddItem("������ �Ȱ�");
				printf("���� �����ϰ� �ִ� ������\n");
				InPlayer->ShowInventory();

				break;
			}

		}
	}
}
