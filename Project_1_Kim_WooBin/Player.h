#pragma once
#include "Actor.h"
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

class APlayer : public Actor
{
public:
	APlayer() = default;
	APlayer(const std::string InName)
		: Actor(InName)
	{

	}

	inline void AddItem(const std::string &InItem) { Inventory[InItem] += 1; }
	void UseItem(Actor* InTarget, const std::string& InItem);
	bool SetShootTarget();
	void Attack(Actor* InTarget, bool InIsBlank, RoundManager& InRound);

private:
	std::unordered_map<std::string, int> Inventory;
	bool ShootTarget = 0; // 0�� ���, 1�̸� ���� Ÿ������ ����
	bool Bullseye = 0;
};

