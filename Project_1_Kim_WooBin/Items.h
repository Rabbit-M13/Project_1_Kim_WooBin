#pragma once
class Items
{
public:
	Items() = default;

protected:
	int Price = 0;

};

/*
1. Beer - CurrentHealth++;
2. GunPowder - AttackPower++;
3. VisionGlasses - Peek Current Chamber bullet
4. GoldSack - Add 50% of InGold
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