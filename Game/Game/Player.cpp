#include "Player.h"
#include "InputManager.h"
#include "Character.h"
#include "Timer.h"
#include "Math.hpp"

Player::Player(sf::Vector2f pos, sf::Color col, float size, int points, float angle)
    : Character(pos, col, size, points), m_shootTimer(nullptr)
{
    m_angle = angle;
    m_size = size;
    m_speed = 3.5f;
    m_pos = pos;
    m_type = EntityType::Player;

    m_shootTimer = new Timer();
}

Player::~Player()
{
    delete m_shootTimer;
}

void Player::Update()
{
    m_shootTimer->Tick();
    Character::Update();
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

    m_velocity = sf::Vector2f(dir.x * m_speed, dir.y * m_speed);
    m_pos += m_velocity;
}

void Player::OnEntityCollision(IEntity* other)
{
    EntityType type = other->Type();
    if (type == m_type) return;
    if (type == EntityType::Enemy)
    {
        TakeDamage(20);
        printf("player hit. health: %d\n", m_health);
    }
}

float Player::GetShootCooldown()
{
    return m_shootTimer->GetTotalTime();
}

void Player::ResetShootCooldown()
{
    m_shootTimer->Reset();
}