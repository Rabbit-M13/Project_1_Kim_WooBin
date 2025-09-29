#include "RoundManager.h"
#include "Player.h"
#include <algorithm>
#include <vector>


void RoundManager::SetLiveBulletProbability()
{
	int LeftMagIndex = GetMagazineIndex();
	int LeftBlank = 0;
	int LeftLive = 0;

	for (auto Iter = Magazine.begin() + LeftMagIndex; Iter != Magazine.end(); Iter++)
	{
		if (*Iter == 0)
		{
			LeftBlank++;
		}
		else
		{
			LeftLive++;
		}
	}

	if (LeftBlank == 0)
	{
		LiveBulletProbability = LeftLive; // �и� 0 ���ϱ�
	}
	else
	{
		LiveBulletProbability = LeftLive / LeftBlank;
	}
}

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
	// BlankBullet�� LiveBullet ���ʴ�� ������ŭ ����
	for (MagIndex; MagIndex < GetMaxMagNumber(); MagIndex++)
	{
		if (MagIndex >= GetBlankBullet())
		{
				Magazine.push_back(1);
			continue;
		}

		Magazine.push_back(0);
	}

	// shuffle �˰������� ���� �������� ����
	std::mt19937 gen(std::random_device{}());
	std::shuffle(Magazine.begin(), Magazine.end(), gen);
	
}
void RoundManager::ReloadMagazine()
{
	if (MagazineIndex == MaxMagNumber)
	{
		ClearMagazine();
		ResetMagazineIndex();
		SetMagazine();
		// Debug
		/*printf("\n\n������ �� źâ�� ���� ���� : ");
		for (int n : GetMagazine())
		{
			printf("%d ", n);
		}
		printf("\n\n");*/
	}
	
}

void RoundManager::RoundClearReward(APlayer* InPlayer)
{
	InPlayer->AddGold(RoundClearGold);
}

/// <summary>
/// �÷��̾���� ������ ����Ʈ�� ��� ���Ұ�, ���� �� �ִ� źâ�� ��� ������� �� ���带 �ʱ�ȭ �Ѵ�.
/// </summary>
void RoundManager::ResetRound()
{
	ResetMagazineIndex();
	ClearMagazine();
	SetBulletRatio(GetMaxMagNumber());
	SetMagazine();
}

/// <summary>
/// ���� ���� ���۽� ȣ��. �ʿ��� ������ ��� �ʱ�ȭ �Ѵ�.
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

/* ������ Bullet Pair */
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