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


