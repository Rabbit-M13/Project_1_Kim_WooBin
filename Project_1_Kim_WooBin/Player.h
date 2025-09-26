#pragma once
#include "Actor.h"
#include "Items.h" // ����� �Ǹ� ���� ���� �츮�� inline UseGold() cpp�� ����
#include <unordered_map>

/// <summary>
/// (������ �̸�, ������ ����) �̷������� �����Ϸ��� �ϴµ�, Key:Value ���� Map�� �� �ڿ������� �ʳ�..?
/// </summary>
//struct Inventory
//{
//	std::string ItemName;
//	int ItemCount;
//
//	Inventory(std::string InItemName, int InItemCount)
//		: ItemName(InItemName), ItemCount(InItemCount) 
//	{
//		
//	}
//};

class RoundManager; // Attack()���� RoundManger Ÿ���� �μ��� �ޱ� ���� ���� ����
//class Items; // UseGold()���� Items Ÿ�� ��ü�� Price ������ �μ��� �ޱ� ���� ���� �����Ͽ�����, inline���� ����� �ٷ� �����ؼ� ����.

class APlayer : public Actor
{
public:
	APlayer() = default;
	APlayer(const std::string InName)
		: Actor(InName)
	{

	}
	
	void AddItem(const std::string &InItem) { Inventory[InItem] += 1; }
	
	// ���� ��差 ����(int)
	inline const int GetGoldLeft() const { return Gold; }
	inline void AddGold(int InGold) { Gold += InGold; }
	//inline void UseGold(Items* InItem) { Gold -= InItem->GetItemPrice(); }

	void UseItem(Actor* InTarget, const std::string& InItem);
	
	bool SetShootTarget();
	
	void Attack(Actor* InTarget, bool InIsBlank, RoundManager& InRound);

	std::unordered_map<std::string, int> GetInventory() { return Inventory; }

	void ShowInventory() const;



private:
	std::unordered_map<std::string, int> Inventory
	{
		{"ȭ��", 0},
		{"����", 0},
		{"������ �Ȱ�", 0},
	};
	int Gold = 0;
	bool ShootTarget = 0; // 0�� ���, 1�̸� ���� Ÿ������ ����
	bool Bullseye = 0;
};

