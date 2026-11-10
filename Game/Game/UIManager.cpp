#include "common.h"
#include "UIManager.h"
#include "Player.h"


UIManager::UIManager()
    : m_score(0), m_player(nullptr)
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

int UIManager::GetPlayerHealth() const
{
    return m_player->GetHealth();
}

void UIManager::UpdateUI(sf::Text& scoreText, sf::Text& healthText, sf::Font& font)
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


