#include "Player.h"
#include "InputManager.h"

Player::Player(sf::Vector2f pos, sf::Color col, float size, int points, float angle)
    : Character(pos, col, size, points)
{
    m_angle = angle;
    m_size = size;
    m_speed = 5.f;
    m_pos = pos;
}

void Player::Update()
{
    Move();
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

void Player::Move()
{
    sf::Vector2f dir = GetDirection();

    if (Length(dir) > 0.f)
        dir = Normalize(dir);

    m_pos.x += dir.x * m_speed;
    m_pos.y += dir.y * m_speed;
}
