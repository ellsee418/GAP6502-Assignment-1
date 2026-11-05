#include "Character.h"
#include "Math.hpp"

Character::Character(sf::Vector2f pos, sf::Color col, float size, int points, float angle) 
    : Entity(pos, col, size, points, angle)
{
    m_angle = angle;
    m_size = size;
    m_speed = 2.f;
    m_pos = pos;
}

void Character::Update()
{
    Move();
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

    m_pos.x += dir.x * m_speed;
    m_pos.y += dir.y * m_speed;
}
