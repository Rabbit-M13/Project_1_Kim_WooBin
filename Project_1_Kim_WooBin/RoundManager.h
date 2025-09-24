#pragma once

// 매 라운드의 필요 정보 저장, 라운드가 변경되면 MaxMagNumber, BlankBullet, LiveBullet가 변경된다.
class RoundManager
{
public:
	RoundManager() = default;

	inline int GetCurrentRound() const { return CurrentRound; }
	void SetCurrentRound();
	
	inline int GetMaxMagNumer() const { return MaxMagNumber; }
	void SetMaxMagNumer();

	// Enemy Class에서 받아서 사용해야함
	inline float GetLiveBulletProbability() const { return LiveBulletProbability; }

	inline int GetBlankBullet() const { return BlankBullet; }
	void SetBlankBullet();

	inline int GetLiveBullet() const { return LiveBullet; }
	void SetLiveBullet();

// 어떻게 사용될지 모르니 일단 public으로 open
public:
	int CurrentRound = 0; // UpTo 3
	int MaxMagNumber = 5; // UpTo 7
	int BlankBullet = 2; // 라운드 별 숫자를 고정으로할지 고민 중
	int LiveBullet = 3;	// 라운드 별 숫자를 고정으로할지 고민 중
	float LiveBulletProbability = LiveBullet / BlankBullet; // AI의 총구 방향 선택 근거
};

