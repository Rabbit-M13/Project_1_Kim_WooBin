#include "RoundManager.h"
#include <algorithm>

void RoundManager::SetBulletRatio(int InMaxMagNumber) 
{

	switch (InMaxMagNumber)
	{
	case 5:
	{
		int TempNumMag5 = rand() % 2;
		if (TempNumMag5 == 0)
		{
			BlankBullet = 2;
		}
		else
		{
			BlankBullet = 3;
		}
		break;
	}

	case 6:
	{
		int TempNumMag6 = rand() % 3;
		if (TempNumMag6 == 0)
		{
			BlankBullet = 2;
		}
		else if (TempNumMag6 == 1)
		{
			BlankBullet = 3;
		}
		else
		{
			BlankBullet = 4;
		}

		break;
	}

	case 7:
	{
		int TempNumMag7 = rand() % 2;
		if (TempNumMag7 == 0)
		{
			BlankBullet = 3;
		}
		else
		{
			BlankBullet = 4;
		}

		break;
	}
	default:
		printf("\n\n\nError : Value Of InMaxMagNumber is Invalid\n\n\n");
		break;
	}

	LiveBullet = MaxMagNumber - BlankBullet;
}

bool RoundManager::IsBlank() const
{
	return Magazine[MagazineIndex] == 0;
}

int RoundManager::PeekNextChamber() const
{
	return 0;
}

void RoundManager::SetMagazine()
{
	int MagIndex = 0;
	// BlankBullet과 LiveBullet 차례대로 개수만큼 삽입
	for (MagIndex; MagIndex < GetMaxMagNumber(); MagIndex++)
	{
		if (MagIndex >= GetBlankBullet())
		{
				Magazine.push_back(1);
			continue;
		}

		Magazine.push_back(0);
	}

	// shuffle 알고리즘으로 순서 랜덤으로 섞음
	std::mt19937 gen(std::random_device{}());
	std::shuffle(Magazine.begin(), Magazine.end(), gen);
	
}

/// <summary>
/// 플레이어들의 라이프 포인트가 모두 남았고, 라운드 별 최대 탄창을 모두 사용했을 때 라운드를 초기화 한다.
/// </summary>
void RoundManager::ResetRound()
{
	ResetMagazineIndex();
	ClearMagazine();
	SetBulletRatio(GetMaxMagNumber());
	SetMagazine();
}

/// <summary>
/// 다음 라운드 시작시 호출. 필요한 변수를 모두 초기화 한다.
/// [CurrentRound, MaxMagNumber, SetBulletRatio, MagazineIndex, Magazine]
/// </summary>
void RoundManager::NextRound()
{
	SetCurrentRound();
	ResetMagazineIndex();
	ClearMagazine();
	SetMaxMagNumber();
	SetBulletRatio(GetMaxMagNumber());
	SetMagazine();
}

/* 가능한 Bullet Pair */
/*
		Blank	Live	TempNum
Max5	2		3		0
		3		2		1

Max6	2		4		0
		3		3		1
		4		2		2
					
Max7	3		4		0
		4		3		1
*/