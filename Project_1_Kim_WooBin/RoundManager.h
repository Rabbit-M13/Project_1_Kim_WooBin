#pragma once

// 매 라운드의 필요 정보 저장, 라운드가 변경되면 MaxMagNumber, BlankBullet, LiveBullet이 변경된다.
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
	void SetBlankBullet(int InMaxMagNumber);

	inline int GetLiveBullet() const { return LiveBullet; }
	void SetLiveBullet();

	bool IsBlank() const;

	int PeekNextChamber() const;

	inline void ResetMagazineIndex() { MagazineIndex = 0; }

	inline std::vector<int> GetMagazine() const { return Magazine; }
	void SetMagazine(int InMaxMagNumber);

// 어떻게 사용될지 모르니 일단 public으로 open
public:
	int CurrentRound = 0; // UpTo 3 || Round 통과 시 ++
	int MaxMagNumber = 5; // UpTo 7 || Round 통과 시 += CurrentRound;
	int BlankBullet = 2; // 라운드 별 숫자를 고정으로할지 고민 중
	int LiveBullet = 3;	// 라운드 별 숫자를 고정으로할지 고민 중
	float LiveBulletProbability = LiveBullet / BlankBullet; // 컴퓨터의 총구 방향 선택 근거 (>=1 상대에게 발사)
	int MagazineIndex = 0; // Attack()이 호출되거나, 턴 시작하면 ++;
	std::vector<int> Magazine;
};

