#pragma once


class GameManager
{
public:
	GameManager() = default;
	void Play();
	void PlayDebug();

private:
	// 최대 라운드 수
	static constexpr int MaxRound = 2;

	// 현재 게임 상태 출력(상대와 나의 남은 HP, 남은 탄약 수, 공격 결과)
	void PrintGameState() const;


	// 테스트 모드 여부(약실에 남은 총알의 종류를 공개)
	bool IsTestMode = true;	
};

