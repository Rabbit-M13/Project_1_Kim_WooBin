#pragma once

class  APlayer; // BuyItem()에서 APlayer 타입을, 객체의 골드를 조정하기 위한 인수로 받기 위해 전방 선언

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

	//inline void BuyItem(APlayer* InPlayer); // 플레이어 객체를 받아서 gold 조정해야할 거 같음
	
	// 현재 아이템 수량 가지고 오기
	//inline const int GetCurrentAmount() const { return ItemAmount; } // Player가 가진 맵에서 처리
	//inline void UseItem() { ItemAmount--; } // Player가 가진 맵에서 처리

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

// 인벤토리 이런식으로 구현할까?
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