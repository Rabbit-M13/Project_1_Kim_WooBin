#pragma once


class GameManager
{
public:
	GameManager() = default;
	void Play();
	void PlayDebug();

private:
	// �ִ� ���� ��
	static constexpr int MaxRound = 2;

	// ���� ���� ���� ���(���� ���� ���� HP, ���� ź�� ��, ���� ���)
	void PrintGameState() const;


	// �׽�Ʈ ��� ����(��ǿ� ���� �Ѿ��� ������ ����)
	bool IsTestMode = true;	
};

