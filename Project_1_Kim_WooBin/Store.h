#pragma once
#include <iostream>

// ���� ����
class APlayer;
class Items;

class Store
{
public:
	Store() { printf("\"������ ���Ǵ� ���� : \"�̺�! �� ���ǵ��� ������ ���� �ʰھ�?? �� �� �ѷ������!\"\n"); }
	~Store() { printf("\"����... �� �� ���غ����!\"\n"); }

	void ShoppingTime(APlayer* InPlayer, Items* InItems);

private:

};

