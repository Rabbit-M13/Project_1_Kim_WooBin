#pragma once

class APlayer; // SetIsGameAlive()에서 APlayer 타입을 인수로 받기 위해 전방 선언

class GameManager
{
public:
	GameManager() = default;
	//void Run();
	void Play();
	void PlayDebug();

private:
	// 최대 라운드 수
	static constexpr int MaxRound = 2;

	// 현재 게임 상태 출력(상대와 나의 남은 HP, 남은 탄약 수, 공격 결과)
	void PrintGameState() const;

	// 게임이 플레이어블 상태인지 체크(bool)
	inline const bool GetIsGameAlive() const { return IsGameAlive; }

	/// <summary>
	/// 게임이 플레이어블 상태 전환
	/// </summary>
	/// <param name="InPlayer">플레이어의 IsAlive() 상태</param>
	void SetIsGameAlive(APlayer* InPlayer);

	/// <summary>
	/// 게임 재시작 여부 | 'r'또는 'R'을 입력 받으면 재시작
	/// </summary>
	void RestartGame();


	// 테스트 모드 여부(약실에 남은 총알의 종류를 공개)
	bool IsTestMode = true;

	// 게임이 플레이어블 상태인지 체크(bool)
	bool IsGameAlive = true;
};

