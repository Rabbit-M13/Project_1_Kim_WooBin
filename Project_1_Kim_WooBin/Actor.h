#pragma once
#include <string>

class Actor
{
public:
	Actor() = default;
	Actor(const std::string InName) // �̸��� �Է� �޾Ƽ� �����ϰ� ������...
		:Name(InName)
	{

	}
	virtual ~Actor() {};

	// Debug : Enemy Attack Random Ratio
	int CountPlayerAttack = 0;
	int CountSelfAttack = 0;

	/// <summary>
	/// (Ȯ��)�÷��̾��� �̸��� �����Ѵ�.
	/// </summary>
	/// <returns>�÷��̾��� �̸�</returns>
	inline const std::string GetName() { return Name; }

	/// <summary>
	/// (Ȯ��)�÷��̾��� �̸��� �Է� �޴´�.
	/// </summary>
	/// <param name="InName">Name�� ������ �÷��̾��� �̸�</param>
	
	
	
	inline const void SetCurrentHealth(std::string InName) { Name = InName; }

	inline const int GetCurrentHealth() { return CurrentHealth; }
	// ü���� ���� ��ġ�� ���� ���� ���� �� ���Ƽ� Health�� setter�� ���� X => AddHealth�� ��ü(Item::Beer�� ȣ�� ����)
	// void SetCurrentHealth() {}

	inline int AddCurrentHealth() { CurrentHealth++; }
	// (Item::Beer�� ȣ�� ����)

	/// <summary>
	/// ���� ���� ����� ���� ü���� �ִ�� ȸ��
	/// </summary>
	inline void SetCurrentHealthToMaxHealth() // �̰� �� �´� �� ����
	{
		CurrentHealth = MaxHealth;
	}

	/// <summary>
	/// ���� ���� ����� �ִ� ü���� �ø���. || R1 = 3, R2 = 4, R3 = 5
	/// </summary>
	inline void ResetMaxHealth() { MaxHealth++; }

	/// <summary>
	/// ���ݷ� 1����(Item::GunPowder�� ȣ��) | �ݵ�� ResetAttackPower()ȣ�� �ʿ�
	/// </summary>
	inline void AddAttackPower() { AttackPower++; }

	/// <summary>
	/// ���ݷ� �ʱ�ȭ | 
	/// </summary>
	inline void ResetAttackPower() { AttackPower = 1; }

	/// <summary>
	/// Target���� �����ϴ� �Լ� || Actor::Enemy �Ǵ� Actor::Player���� 'TakeDamage()' ȣ��
	/// </summary>
	/// <param name="InTarget">������ �޴� ���</param>
	void Attack(Actor* InTarget); /*!!!�긦 �����Լ��� ���� Enemy�� Player�� ���� �����ؾ� �ϴ��� ����غ���!!!*/
	// ����ź���� ��ź���� Ȯ���� �ʿ���. // ������ �μ��� �޾ƾ��ұ�?

	/// <summary>
	/// ������ ���ط���ŭ ���ο��� ���ظ� �����ϴ�.
	/// </summary>
	void TakeDamage() { CurrentHealth--; }

	/// <summary>
	/// ���� ü���� +1 ���ִ� �Լ�. Item::Beer�� ȣ�� ����
	/// </summary>
	inline void AddHealth() { CurrentHealth++; }

	/// <summary>
	/// �� Actor�� ���� ���θ� �˷��ִ� �Լ�
	/// </summary>
	/// <returns>false�� �׾���.</returns>
	inline bool IsAlive() const { return CurrentHealth > 0; }




protected: // �ڽ� Ŭ�������� ��� �ʿ�
	std::string Name = "Default Actor";
	int CurrentHealth = 3;
	int MaxHealth = 3; // ���� �� MaxHealth �� ���� ���� R1 = 3, R2 = 4, R3 = 5
	int AttackPower = 1; // Item::GunPowder�� �ش� �Ͽ��� 1���� || Max 2

};

