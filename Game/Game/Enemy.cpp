#include "Enemy.h"
#include "Math.hpp"

Enemy::Enemy(sf::Vector2f pos, sf::Color col, float size, int points, float angle)
	: Character(pos, col, size, points, angle), m_directionTimer(nullptr), m_nextTurnTime(RandomFloat(0,2))
{
    m_angle = angle;
    m_size = size;
    m_speed = 2.f;
    m_pos = pos;
    m_type = EntityType::Enemy;

    m_directionTimer = new Timer();
}

Enemy::~Enemy()
{
    delete m_directionTimer;
}

void Enemy::Update()
{
    m_directionTimer->Tick();
    Character::Update();
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
    float angle = GetAngle();

    angle *= (3.14159f / 180.f);

    dir.x = std::cos(angle);
    dir.y = std::sin(angle);
    if (Length(dir) > 0.f)
        dir = Normalize(dir);

    m_velocity = sf::Vector2f(dir.x * m_speed, dir.y * m_speed);
}

void Enemy::OnBoundsCollision()
{
    SetAngle(RandomFloat(0, 360));
}

void Enemy::OnEntityCollision(IEntity* other)
{
    if (other->Type() == m_type) return;


    TakeDamage(100);
}
