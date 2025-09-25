#include "RoundManager.h"
#include <random>

void RoundManager::SetCurrentRound()
{
	CurrentRound++;
}

void RoundManager::SetMaxMagNumer()
{	// 반드시 SetCurrentRound() 호출이 선행되어야 함
	MaxMagNumber += CurrentRound;
}

void RoundManager::SetBlankBullet(int InMaxMagNumber)
{

	switch (InMaxMagNumber)
	{
	case 5:
		int TempOdd = rand() % 2;
		if (TempOdd == 0)
		{
			BlankBullet = 2;
		}
		else
		{
			BlankBullet = 3;
		}
		break;

	case 6:
		int TempEven = rand() % 3;
		if (TempEven == 0)
		{
			BlankBullet = 2;
		}
		else if (TempEven == 1)
		{
			BlankBullet = 3;
		}
		else
		{
			BlankBullet = 4;
		}

		break;

	case 7:
		int TempOdd = rand() % 2;
		if (TempOdd == 0)
		{
			BlankBullet = 3;
		}
		else
		{
			BlankBullet = 4;
		}

		break;
	}
}

void RoundManager::SetLiveBullet()
{
	LiveBullet = MaxMagNumber - BlankBullet;
}

bool RoundManager::IsBlank() const
{
	return false;
}

int RoundManager::PeekNextChamber() const
{
	return 0;
}

void RoundManager::SetMagazine(int InMaxMagNumber)
{
	// BlankBullet개수와 LiveBullet개수는 위의 함수로 정해졌음
	switch (InMaxMagNumber)
	{
	case 5:
		for (int i = 0; i < MaxMagNumber; i++)
		{

		}

		break;

	case 6:


		break;

	case 7:


		break;
	}


	for (int i = 0; i < MaxMagNumber; i++)
	{

	}
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