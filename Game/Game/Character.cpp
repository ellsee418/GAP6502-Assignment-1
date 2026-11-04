#include "Character.h"
#include "Math.hpp"

Character::Character(sf::Vector2f pos, sf::Color col, float size, int points, float angle) 
    : m_pos(pos), m_active(true), m_colour(col), m_size(size), m_points(points), m_angle(angle), m_speed(2.f)
{
}

sf::Vector2f Character::GetPosition()
{
    return m_pos;
}

void Character::SetPosition(sf::Vector2f pos)
{
    m_pos = pos;
}

bool Character::Active()
{
    return m_active;
}

void Character::Kill()
{
    m_active = false;
}

void Character::Update()
{
    m_angle += m_speed;

    Move(GetDirection());
}

float Character::Angle()
{
    return m_angle;
}

void Character::SetAngle(float angle)
{
    m_angle = angle;
}

sf::Color Character::Colour()
{
    return m_colour;
}

float Character::Size()
{
    return m_size;
}

int Character::Points()
{
    return m_points;
}

float Character::Speed()
{
    return m_speed;
}

sf::Vector2f Character::GetDirection()
{
    float x = RandomFloat(-1, 1) * m_speed;
    float y = RandomFloat(-1, 1) * m_speed;

    return sf::Vector2f(x, y);
}

void Character::Move(sf::Vector2f dir)
{
    if (Length(dir) > 0.f)
        dir = Normalize(dir);

    m_pos.x += dir.x * m_speed;
    m_pos.y += dir.y * m_speed;
}
