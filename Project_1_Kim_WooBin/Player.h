#pragma once
#include "Actor.h"
#include "Items.h" // 지우게 되면 전방 선언 살리고 inline UseGold() cpp에 구현
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
//class Items; // UseGold()에서 Items 타입 객체의 Price 변수를 인수로 받기 위해 전방 선언하였으나, inline으로 헤더에 바로 정의해서 지움.

class APlayer : public Actor
{
public:
	APlayer() = default;
	APlayer(const std::string InName)
		: Actor(InName)
	{

	}
	
	void AddItem(const std::string &InItem) { Inventory[InItem] += 1; }
	
	// 남은 골드량 리턴(int)
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
		{"화약", 0},
		{"맥주", 0},
		{"수상한 안경", 0},
	};
	int Gold = 0;
	bool ShootTarget = 0; // 0면 상대, 1이면 나를 타켓으로 설정
	bool Bullseye = 0;
};

