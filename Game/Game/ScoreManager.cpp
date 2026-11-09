#include "ScoreManager.h"

ScoreManager::ScoreManager()
    : m_score(0)
{
}

ScoreManager::~ScoreManager()
{
}

ScoreManager& ScoreManager::Get()
{
    static ScoreManager sInstance;
    return sInstance;
}

int ScoreManager::GetScore()
{
    return m_score;
}

void ScoreManager::AddScore(int score)
{
    m_score += score;
}

void ScoreManager::ResetScore()
{
    m_score = 0;
}


