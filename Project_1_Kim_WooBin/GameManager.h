#pragma once

class APlayer; // SetIsGameAlive()���� APlayer Ÿ���� �μ��� �ޱ� ���� ���� ����

class GameManager
{
public:
	GameManager() = default;
	//void Run();
	void Play();
	void PlayDebug();

private:
	// �ִ� ���� ��
	static constexpr int MaxRound = 2;

	// ���� ���� ���� ���(���� ���� ���� HP, ���� ź�� ��, ���� ���)
	void PrintGameState() const;

	// ������ �÷��̾�� �������� üũ(bool)
	inline const bool GetIsGameAlive() const { return IsGameAlive; }

	/// <summary>
	/// ������ �÷��̾�� ���� ��ȯ
	/// </summary>
	/// <param name="InPlayer">�÷��̾��� IsAlive() ����</param>
	void SetIsGameAlive(APlayer* InPlayer);

	/// <summary>
	/// ���� ����� ���� | 'r'�Ǵ� 'R'�� �Է� ������ �����
	/// </summary>
	void RestartGame();


	// �׽�Ʈ ��� ����(��ǿ� ���� �Ѿ��� ������ ����)
	bool IsTestMode = true;

	// ������ �÷��̾�� �������� üũ(bool)
	bool IsGameAlive = true;
};

