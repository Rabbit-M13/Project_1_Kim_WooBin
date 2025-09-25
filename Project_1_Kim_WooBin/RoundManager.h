#pragma once

// �� ������ �ʿ� ���� ����, ���尡 ����Ǹ� MaxMagNumber, BlankBullet, LiveBullet�� ����ȴ�.
class RoundManager
{
public:
	RoundManager() = default;

	inline int GetCurrentRound() const { return CurrentRound; }
	void SetCurrentRound();
	
	inline int GetMaxMagNumer() const { return MaxMagNumber; }
	void SetMaxMagNumer();

	// Enemy Class���� �޾Ƽ� ����ؾ���
	inline float GetLiveBulletProbability() const { return LiveBulletProbability; }

	inline int GetBlankBullet() const { return BlankBullet; }
	void SetBlankBullet(int InMaxMagNumber);

	inline int GetLiveBullet() const { return LiveBullet; }
	void SetLiveBullet();

	bool IsBlank() const;

	int PeekNextChamber() const;

	inline void ResetMagazineIndex() { MagazineIndex = 0; }

	inline std::vector<int> GetMagazine() const { return Magazine; }
	void SetMagazine(int InMaxMagNumber);

// ��� ������ �𸣴� �ϴ� public���� open
public:
	int CurrentRound = 0; // UpTo 3 || Round ��� �� ++
	int MaxMagNumber = 5; // UpTo 7 || Round ��� �� += CurrentRound;
	int BlankBullet = 2; // ���� �� ���ڸ� ������������ ��� ��
	int LiveBullet = 3;	// ���� �� ���ڸ� ������������ ��� ��
	float LiveBulletProbability = LiveBullet / BlankBullet; // ��ǻ���� �ѱ� ���� ���� �ٰ� (>=1 ��뿡�� �߻�)
	int MagazineIndex = 0; // Attack()�� ȣ��ǰų�, �� �����ϸ� ++;
	std::vector<int> Magazine;
};

