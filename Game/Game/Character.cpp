#include "Character.h"
#include "Math.hpp"

Character::Character(sf::Vector2f pos, sf::Color col, float size, int points, float angle) 
    : Entity(pos, col, size, points, angle), m_health(100)
{
    m_angle = angle;
    m_size = size;
    m_speed = 2.f;
    m_pos = pos;
    m_type = EntityType::Character;
}

void Character::Update()
{
    m_pos += m_velocity;
    Move();

    if (m_health <= 0) OnDeath();
}

float Character::Speed()
{
    return m_speed;
}

void Character::Move()
{
    float x = RandomFloat(-1, 1) * m_speed;
    float y = RandomFloat(-1, 1) * m_speed;
    sf::Vector2f dir = { x,y };

    if (Length(dir) > 0.f)
        dir = Normalize(dir);

    m_velocity = sf::Vector2f(dir.x * m_speed, dir.y * m_speed);
}

int Character::GetHealth()
{
    return m_health;
}

void Character::TakeDamage(int dmg)
{
    m_health -= dmg;
}

void Character::AddHealth(int hp)
{
    m_health += hp;
}

void Character::OnDeath()
{
    Kill();
}
