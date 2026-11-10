#pragma once

class Player;

class UIManager
{
public:
	static UIManager& Get();
	void Init(Player* player);

	int GetScore() const;
	void AddScore(int score);
	void ResetScore();

	int GetPlayerHealth() const;

	~UIManager();
private:
	UIManager();
	UIManager(const UIManager&) = delete;

	int m_score;
	Player* m_player;
};

