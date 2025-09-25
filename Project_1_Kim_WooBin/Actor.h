#pragma once
#include <string>

class Actor
{
public:
	Actor() = default;
	Actor(const std::string InName) // 이름을 입력 받아서 진행하고 싶은데...
		:Name(InName)
	{

	}
	virtual ~Actor() {};

	// Debug : Enemy Attack Random Ratio
	int CountPlayerAttack = 0;
	int CountSelfAttack = 0;

	/// <summary>
	/// (확인)플레이어의 이름을 리턴한다.
	/// </summary>
	/// <returns>플레이어의 이름</returns>
	inline const std::string GetName() { return Name; }

	/// <summary>
	/// (확인)플레이어의 이름을 입력 받는다.
	/// </summary>
	/// <param name="InName">Name에 저장할 플레이어의 이름</param>
	
	
	
	inline const void SetCurrentHealth(std::string InName) { Name = InName; }

	inline const int GetCurrentHealth() { return CurrentHealth; }
	// 체력을 임의 수치로 정할 일은 없을 것 같아서 Health의 setter는 구현 X => AddHealth로 대체(Item::Beer가 호출 예정)
	// void SetCurrentHealth() {}

	inline int AddCurrentHealth() { CurrentHealth++; }
	// (Item::Beer가 호출 예정)

	/// <summary>
	/// 다음 라운드 진행시 현재 체력을 최대로 회복
	/// </summary>
	inline void SetCurrentHealthToMaxHealth() // 이게 더 맞는 거 같음
	{
		CurrentHealth = MaxHealth;
	}

	/// <summary>
	/// 다음 라운드 진행시 최대 체력을 늘린다. || R1 = 3, R2 = 4, R3 = 5
	/// </summary>
	inline void ResetMaxHealth() { MaxHealth++; }

	/// <summary>
	/// 공격력 1증가(Item::GunPowder가 호출) | 반드시 ResetAttackPower()호출 필요
	/// </summary>
	inline void AddAttackPower() { AttackPower++; }

	/// <summary>
	/// 공격력 초기화 | 
	/// </summary>
	inline void ResetAttackPower() { AttackPower = 1; }

	/// <summary>
	/// Target에게 공격하는 함수 || Actor::Enemy 또는 Actor::Player에서 'TakeDamage()' 호출
	/// </summary>
	/// <param name="InTarget">공격을 받는 대상</param>
	void Attack(Actor* InTarget); /*!!!얘를 가상함수로 만들어서 Enemy랑 Player랑 따로 구현해야 하는지 고민해보기!!!*/
	// 공포탄인지 실탄인지 확인이 필요함. // 무엇을 인수로 받아야할까?

	/// <summary>
	/// 지정된 피해량만큼 본인에게 피해를 입힙니다.
	/// </summary>
	void TakeDamage() { CurrentHealth--; }

	/// <summary>
	/// 현재 체력을 +1 해주는 함수. Item::Beer가 호출 예정
	/// </summary>
	inline void AddHealth() { CurrentHealth++; }

	/// <summary>
	/// 이 Actor의 생존 여부를 알려주는 함수
	/// </summary>
	/// <returns>false면 죽었다.</returns>
	inline bool IsAlive() const { return CurrentHealth > 0; }




protected: // 자식 클래스들이 사용 필요
	std::string Name = "Default Actor";
	int CurrentHealth = 3;
	int MaxHealth = 3; // 라운드 별 MaxHealth 값 변동 예정 R1 = 3, R2 = 4, R3 = 5
	int AttackPower = 1; // Item::GunPowder로 해당 턴에만 1증가 || Max 2

};

