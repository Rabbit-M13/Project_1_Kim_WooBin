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

		switch (PlayerItemChoice)
		{
		case 1:
			if (PlayerCurrentGold < InItems->GetGunpowderItemPrice())
			{
				printf("������ ��尡 �����մϴ�!\n");
				break;
			}
			// �÷��̾��� �κ��丮 ���� �̸� �ʱ�ȭ �ص־� �ϰ�, �׸��� �ƿ� �������� �ʰ� �ؾ���.
			// Key(������ �̸�)���� �޾ƿͼ� Value�� MaxItemCount�� �ʰ����� �ʴ��� üũ�ؾ���
			if (InPlayer.)
			{
				printf("������ ��尡 �����մϴ�!\n");
				break;
			}
			printf("ȭ�� 1���� �����߽��ϴ�!\n");
			InPlayer->AddItem("ȭ��");
			printf("���� �����ϰ� �ִ� ������\n");
			
			break;

		case 2:

		}
	}
}
