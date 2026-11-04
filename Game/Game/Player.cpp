#include "Player.h"
#include "InputManager.h"

Player::Player(sf::Vector2f pos, sf::Color col, float size, int points, float angle)
    : Character(pos, col, size, points), m_pos(pos), m_active(true), m_colour(col), m_size(size), m_points(points), m_angle(angle), m_speed(5.f)
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

void Player::Update()
{
    Move(GetDirection());
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

float Player::Speed()
{
    return m_speed;
}

sf::Vector2f Player::GetDirection()
{
    sf::Vector2f dir = { 0.f, 0.f };
    if (InputManager::Get().GetKeyHeld(sf::Keyboard::S))
        dir.y += 1;
    if (InputManager::Get().GetKeyHeld(sf::Keyboard::W))
        dir.y -= 1;
    if (InputManager::Get().GetKeyHeld(sf::Keyboard::D))
        dir.x += 1;
    if (InputManager::Get().GetKeyHeld(sf::Keyboard::A))
        dir.x -= 1;

    return dir;
}

void Player::Move(sf::Vector2f dir)
{
    if (Length(dir) > 0.f)
        dir = Normalize(dir);

    m_pos.x += dir.x * m_speed;
    m_pos.y += dir.y * m_speed;
}
