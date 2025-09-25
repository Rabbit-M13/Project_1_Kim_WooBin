#pragma once
#include "Actor.h"
#include <unordered_map>

/// <summary>
/// (아이템 이름, 아이템 개수) 이러식으로 저장하려고 하는데, Key:Value 쌍인 Map이 더 자연스럽지 않나..?
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

class RoundManager; // Attack()에서 RoundManger 타입을 인수로 받기 위해 전방 선언

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
	bool ShootTarget = 0; // 0면 상대, 1이면 나를 타켓으로 설정
	bool Bullseye = 0;
};

