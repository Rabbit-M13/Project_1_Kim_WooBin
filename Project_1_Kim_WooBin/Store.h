#pragma once
#include <iostream>

// ���� ����
class APlayer;
class Items;

class Store
{
public:
    Store() = default;
	~Store() {}

    void StoreOpen()
    {
        printf("[������ ���Ǵ� ����] : \"�̺�! �� ���ǵ��� ������ ���� �ʰھ�?? �� �� �ѷ������!\"\n");
    }

    void StoreClose()
    {
        printf("[������ ���Ǵ� ����] : \"����... �� �� ���غ����!\"\n");
    }

	void ShoppingTime(APlayer* InPlayer, Items* InItems);

private:

};

