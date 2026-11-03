#include "Player.h"

Player::Player(sf::Vector2f pos, sf::Color col, float size, int points, float angle)
    : Character(pos, col, size, points), m_pos(pos), m_active(true), m_colour(col), m_size(size), m_points(points), m_angle(angle)
{
}

sf::Vector2f Player::GetPosition()
{
    return m_pos;
}

void Player::SetPosition(sf::Vector2f pos)
{
    m_pos = pos;
}

bool Player::Active()
{
    return m_active;
}

void Player::Kill()
{
    m_active = false;
}

float Player::Angle()
{
    return m_angle;
}

sf::Color Player::Colour()
{
    return m_colour;
}

float Player::Size()
{
    return m_size;
}

int Player::Points()
{
    return m_points;
}
