#include "Enemy.h"
#include "Math.hpp"

Enemy::Enemy(sf::Vector2f pos, sf::Color col, float size, int points, float angle)
	: Character(pos, col, size, points, angle), m_directionTimer(nullptr), m_nextTurnTime(RandomFloat(0,2))
{
    m_directionTimer = new Timer();
}

Enemy::~Enemy()
{
    delete m_directionTimer;
}

void Enemy::Update()
{
    m_directionTimer->Tick();
    Move();
}

void Enemy::HandleMovementDirection()
{
    if (m_directionTimer->GetTotalTime() < m_nextTurnTime) return;

    m_angle = RandomFloat(0, 360);
    m_nextTurnTime = RandomFloat(0, 3);
    m_directionTimer->Reset();
}

void Enemy::Move()
{
    sf::Vector2f dir = { 0.f,0.f };
    HandleMovementDirection();
    float angle = Angle();

    angle *= (3.14159f / 180.f);

    dir.x = std::cos(angle);
    dir.y = std::sin(angle);
    if (Length(dir) > 0.f)
        dir = Normalize(dir);

    m_pos.x += dir.x * m_speed;
    m_pos.y += dir.y * m_speed;
}