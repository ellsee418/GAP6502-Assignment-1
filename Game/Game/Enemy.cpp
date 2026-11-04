#include "Enemy.h"
#include "Math.hpp"

Enemy::Enemy(sf::Vector2f pos, sf::Color col, float size, int points, float angle)
	: Character(pos, col, size, points, angle), m_pos(pos), m_active(true), m_colour(col), m_size(size), 
    m_points(points), m_angle(angle), m_speed(2.f), m_directionTimer(nullptr), m_nextTurnTime(RandomFloat(0,2))
{
    m_directionTimer = new Timer();
}

Enemy::~Enemy()
{
    delete m_directionTimer;
}

sf::Vector2f Enemy::GetPosition()
{
    return m_pos;
}

void Enemy::SetPosition(sf::Vector2f pos)
{
    m_pos = pos;
}

bool Enemy::Active()
{
    return m_active;
}

void Enemy::Kill()
{
    m_active = false;
}

void Enemy::Update()
{
    //m_angle += m_speed;
    //add timer for random direction
    m_directionTimer->Tick();
    Move();
}

float Enemy::Angle()
{
    return m_angle;
}

void Enemy::SetAngle(float angle)
{
    m_angle = angle;
}

sf::Color Enemy::Colour()
{
    return m_colour;
}

float Enemy::Size()
{
    return m_size;
}

int Enemy::Points()
{
    return m_points;
}

float Enemy::Speed()
{
    return m_speed;
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