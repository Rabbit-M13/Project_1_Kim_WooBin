#pragma once

class  APlayer; // BuyItem()���� APlayer Ÿ����, ��ü�� ��带 �����ϱ� ���� �μ��� �ޱ� ���� ���� ����

enum ItemList
{
	Gunpowder = 0,
	Beer,
	VisionGlass,
	ItemListMaxIndex
};

class Items
{
public:
	Items() = default;
	virtual ~Items() {};

	inline const int GetGunpowderItemPrice() const { return GunpowderPrice; }
	inline const int GetBeerItemPrice() const { return BeerPrice; }
	inline const int GetVisionGlassItemPrice() const { return VisionGlassPrice; }
	inline const int GetMaxItemCount() const { return MaxItemCount; }
	//inline void SeItemPrice(int InItemPrice) { Price = InItemPrice; }

	//inline void BuyItem(APlayer* InPlayer); // �÷��̾� ��ü�� �޾Ƽ� gold �����ؾ��� �� ����
	
	// ���� ������ ���� ������ ����
	//inline const int GetCurrentAmount() const { return ItemAmount; } // Player�� ���� �ʿ��� ó��
	//inline void UseItem() { ItemAmount--; } // Player�� ���� �ʿ��� ó��

private:
	int GunpowderPrice = 40;
	int GunpowderItemAmount = 0;
	int BeerPrice = 50;
	int BeerItemAmount = 0;
	int VisionGlassPrice = 80;
	int VisionGlassItemAmount = 0;
	const int MaxItemCount = 3;
};

/*
1. Beer - CurrentHealth++;
2. GunPowder - AttackPower++;
3. VisionGlasses - Peek Current Chamber bullet
4. GoldSack - Add 50% of InGold
*/

/*

*/

// �κ��丮 �̷������� �����ұ�?
//enum MyEnum
//{
//	Beer = 0,
//	GunPowder = 1,
//	Glasses = 2,
//	MAX
//};
//
//MyEnum::MAX
//vec.size(MyEnum::MAX)
//vec[MyEnum::Beer]