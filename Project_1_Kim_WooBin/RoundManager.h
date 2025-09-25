#pragma once
#include <random>
#include <vector>

// �� ������ �ʿ� ���� ����, ���尡 ����Ǹ� MaxMagNumber, BlankBullet, LiveBullet�� ����ȴ�.
class RoundManager
{
public:
	RoundManager() = default;

	inline int GetCurrentRound() const { return CurrentRound; }
	void SetCurrentRound() { CurrentRound++; }
	
	inline int GetMaxMagNumber() const { return MaxMagNumber; }

	/// <summary>
	/// �ִ� ź�� ���� ���� ���忡 ���� �ø���.
	/// </summary>
	inline void SetMaxMagNumber() { MaxMagNumber++; };

	// Enemy Class���� �޾Ƽ� ����ؾ���
	inline float GetLiveBulletProbability() const { return LiveBulletProbability; }

	// ����ź ���� ����
	inline int GetBlankBullet() const { return BlankBullet; }

	/// <summary>
	/// ����ź�� ��ź ���� ����
	/// </summary>
	/// <param name="InMaxMagNumber">�ִ� ź���</param>
	void SetBulletRatio(int InMaxMagNumber);

	inline int GetLiveBullet() const { return LiveBullet; }

	bool IsBlank() const;

	int PeekNextChamber() const;

	inline void ResetMagazineIndex() { MagazineIndex = 0; }

	inline const std::vector<int>& GetMagazine() const { return Magazine; }
	
	/// <summary>
	/// GetBlankBullet()���� ����ź ������ �޾� �������� ��ź�� ����ź ��ġ, źâ ���� GetMaxMagNumber()�� �޾ƾ� ��
	/// </summary>
	void SetMagazine();

	/// <summary>
	/// MagazineIndex ������ 1��ŭ ������ŵ�ϴ�.
	/// </summary>
	inline void IncreaseMagazineIndex() { MagazineIndex++; }

	inline int GetMagazineIndex() const { return MagazineIndex; }

	/// <summary>
	/// źâ�� ����.
	/// </summary>
	inline void ClearMagazine() { Magazine.clear(); } // �̰� ����� �������� ����

	/// <summary>
	/// �÷��̾���� ������ ����Ʈ�� ��� ���Ұ�, ���� �� �ִ� źâ�� ��� ������� �� ���带 �ʱ�ȭ �Ѵ�.
	/// </summary>
	void ResetRound();

	/// <summary>
	/// ���� ���� ���۽� ȣ��. �ʿ��� ������ ��� �ʱ�ȭ �Ѵ�.
	/// [CurrentRound, MaxMagNumber, BlankBullet, LiveBullet, MagazineIndex, Magazine]
	/// </summary>
	void NextRound();


private:
	int CurrentRound = 0; // (���� ���� int) UpTo 3 || Round ��� �� ++
	int MaxMagNumber = 5; // (źâ �ִ� ź�� �� int) UpTo 7 || Round ��� �� += CurrentRound;
	int BlankBullet = 1; // (����ź �� int) ���� �� ���ڸ� ������������ ��� ��
	int LiveBullet = 1;	// (��ź �� int) ���� �� ���ڸ� ������������ ��� ��
	float LiveBulletProbability = LiveBullet / BlankBullet; // ��ǻ���� �ѱ� ���� ���� �ٰ� (>=1 ��뿡�� �߻�)
	int MagazineIndex = 0; // Attack()�� ȣ��ǰų�, �� �����ϸ� ++; , �����⳪ �߰� ������(����ź�� ��ź���� �ٲٱ� �� �� �� �ʿ���)
	std::vector<int> Magazine;
};

