#include "Character.h"

Character::Character(sf::Vector2f pos, sf::Color col, float size, int points, float angle) 
    : m_pos(pos), m_active(true), m_colour(col), m_size(size), m_points(points), m_angle(angle)
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

float Character::Angle()
{
    return m_angle;
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
