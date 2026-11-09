#pragma once
class ScoreManager
{
public:
	static ScoreManager& Get();

	void Update();

	int GetScore();
	void AddScore(int score);
	void ResetScore();

	~ScoreManager();
private:
	ScoreManager();
	ScoreManager(const ScoreManager&) = delete;

	int m_score;
};

