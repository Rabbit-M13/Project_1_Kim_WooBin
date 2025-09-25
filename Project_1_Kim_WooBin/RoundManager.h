#pragma once
#include <random>
#include <vector>

// 매 라운드의 필요 정보 저장, 라운드가 변경되면 MaxMagNumber, BlankBullet, LiveBullet이 변경된다.
class RoundManager
{
public:
	RoundManager() = default;

	inline int GetCurrentRound() const { return CurrentRound; }
	void SetCurrentRound() { CurrentRound++; }
	
	inline int GetMaxMagNumber() const { return MaxMagNumber; }

	/// <summary>
	/// 최대 탄약 수를 현재 라운드에 맞춰 늘린다.
	/// </summary>
	inline void SetMaxMagNumber() { MaxMagNumber++; };

	// Enemy Class에서 받아서 사용해야함
	inline float GetLiveBulletProbability() const { return LiveBulletProbability; }

	// 공포탄 개수 리턴
	inline int GetBlankBullet() const { return BlankBullet; }

	/// <summary>
	/// 공포탄과 실탄 개수 설정
	/// </summary>
	/// <param name="InMaxMagNumber">최대 탄약수</param>
	void SetBulletRatio(int InMaxMagNumber);

	inline int GetLiveBullet() const { return LiveBullet; }

	bool IsBlank() const;

	int PeekNextChamber() const;

	inline void ResetMagazineIndex() { MagazineIndex = 0; }

	inline const std::vector<int>& GetMagazine() const { return Magazine; }
	
	/// <summary>
	/// GetBlankBullet()으로 공포탄 개수를 받아 랜덤으로 실탄과 공포탄 배치, 탄창 수는 GetMaxMagNumber()로 받아야 함
	/// </summary>
	void SetMagazine();

	/// <summary>
	/// MagazineIndex 변수를 1만큼 증가시킵니다.
	/// </summary>
	inline void IncreaseMagazineIndex() { MagazineIndex++; }

	inline int GetMagazineIndex() const { return MagazineIndex; }

	/// <summary>
	/// 탄창을 비운다.
	/// </summary>
	inline void ClearMagazine() { Magazine.clear(); } // 이게 제대로 동작하지 않음

	/// <summary>
	/// 플레이어들의 라이프 포인트가 모두 남았고, 라운드 별 최대 탄창을 모두 사용했을 때 라운드를 초기화 한다.
	/// </summary>
	void ResetRound();

	/// <summary>
	/// 다음 라운드 시작시 호출. 필요한 변수를 모두 초기화 한다.
	/// [CurrentRound, MaxMagNumber, BlankBullet, LiveBullet, MagazineIndex, Magazine]
	/// </summary>
	void NextRound();


private:
	int CurrentRound = 0; // (현재 라운드 int) UpTo 3 || Round 통과 시 ++
	int MaxMagNumber = 5; // (탄창 최대 탄약 수 int) UpTo 7 || Round 통과 시 += CurrentRound;
	int BlankBullet = 1; // (공포탄 수 int) 라운드 별 숫자를 고정으로할지 고민 중
	int LiveBullet = 1;	// (실탄 수 int) 라운드 별 숫자를 고정으로할지 고민 중
	float LiveBulletProbability = LiveBullet / BlankBullet; // 컴퓨터의 총구 방향 선택 근거 (>=1 상대에게 발사)
	int MagazineIndex = 0; // Attack()이 호출되거나, 턴 시작하면 ++; , 돋보기나 추가 아이템(공포탄을 실탄으로 바꾸기 등 할 때 필요함)
	std::vector<int> Magazine;
};

