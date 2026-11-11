#pragma once

#include <SFML/Graphics/Text.hpp>

class Player;

class UIManager
{
public:
	static UIManager& Get();
	void Init(Player* player);

	int GetScore() const;
	void AddScore(int score);
	void ResetScore();

	int ReadHighScore();// reads from file
	int GetHighScore();
	void SaveHighScore(int score);

	int GetPlayerHealth() const;

	void UpdateInGameUI(sf::Text& scoreText, sf::Text& healthText, sf::Font& font);
	void UpdateGameOverUI(sf::Text& scoreText, sf::Text& highScoreText, sf::Font& font);


	~UIManager();
private:
	UIManager();
	UIManager(const UIManager&) = delete;

	int m_score;
	Player* m_player;
	int m_highScore;
	const std::string m_highScorePath = "../Assets/highscore.txt";
};

