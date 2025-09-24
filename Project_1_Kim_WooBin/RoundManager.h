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
	void SetBlankBullet();

	inline int GetLiveBullet() const { return LiveBullet; }
	void SetLiveBullet();

// ��� ������ �𸣴� �ϴ� public���� open
public:
	int CurrentRound = 0; // UpTo 3
	int MaxMagNumber = 5; // UpTo 7
	int BlankBullet = 2; // ���� �� ���ڸ� ������������ ��� ��
	int LiveBullet = 3;	// ���� �� ���ڸ� ������������ ��� ��
	float LiveBulletProbability = LiveBullet / BlankBullet; // AI�� �ѱ� ���� ���� �ٰ�
};

