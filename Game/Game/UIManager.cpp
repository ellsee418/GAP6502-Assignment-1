#include "common.h"
#include "UIManager.h"
#include "Player.h"
#include <fstream>


UIManager::UIManager()
    : m_score(0), m_highScore(0), m_player(nullptr)
{
}

UIManager::~UIManager()
{
    m_player = nullptr;// deleted elsewhere
}

UIManager& UIManager::Get()
{
    static UIManager sInstance;
    return sInstance;
}

void UIManager::Init(Player* player)
{
    m_player = player;
}

int UIManager::GetScore() const
{
    return m_score;
}

void UIManager::AddScore(int score)
{
    m_score += score;
}

void UIManager::ResetScore()
{
    m_score = 0;
}

int UIManager::ReadHighScore()
{
    std::ifstream in(m_highScorePath);
    if (!in)
    {
        printf("%s could not be found\n", m_highScorePath.c_str());
        return 0;
    }

    int score = 0;
    in >> score;
    if (!in)
    {
        printf("%s could not be read\n", m_highScorePath.c_str());
        return 0;
    }
    m_highScore = score;
    return m_highScore;
}

int UIManager::GetHighScore()
{
    return m_highScore;
}

void UIManager::SaveHighScore(int score)
{
    std::ofstream out(m_highScorePath);
    if (!out)
    {
        printf("failed to open %s\n", m_highScorePath.c_str());
        return;
    }
    m_highScore = score;
    out << score;
}

int UIManager::GetPlayerHealth() const
{
    return m_player->GetHealth();
}

void UIManager::UpdateInGameUI(sf::Text& scoreText, sf::Text& healthText, sf::Font& font)
{
	const float padding = 10.f;

	std::string scoreStr = "Score: " + std::to_string(m_score);
	scoreText.setFont(font);
	scoreText.setString(scoreStr);
	scoreText.setPosition(WIN_WIDTH - scoreText.getGlobalBounds().width - padding,
		scoreText.getGlobalBounds().height + padding);

	int health = m_player->GetHealth();
	std::string healthStr = "Health: " + std::to_string(health);
	healthText.setFont(font);
	healthText.setString(healthStr);
	healthText.setPosition(padding,
		healthText.getGlobalBounds().height + padding);
}

void UIManager::UpdateGameOverUI(sf::Text& scoreText, sf::Text& highScoreText, sf::Font& font)
{
    const float padding = 20.f;
    std::string scoreStr = "Score: " + std::to_string(m_score);
    scoreText.setFont(font);
    scoreText.setString(scoreStr);
   
    scoreText.setPosition(WIN_WIDTH / 2 - scoreText.getGlobalBounds().width / 2,
        WIN_HEIGHT / 2 + scoreText.getGlobalBounds().height - padding);

    std::string highScoreStr = "High Score: " + std::to_string(m_highScore);
    highScoreText.setFont(font);
    highScoreText.setString(highScoreStr);
    highScoreText.setPosition(WIN_WIDTH / 2 - highScoreText.getGlobalBounds().width / 2,
        WIN_HEIGHT / 2 + highScoreText.getGlobalBounds().height + padding);
}


