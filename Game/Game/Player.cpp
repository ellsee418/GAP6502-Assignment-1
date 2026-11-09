#include "Player.h"
#include "InputManager.h"
#include "BulletFactory.h"
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
    HandleInput();
    Character::Update();
}

void Player::HandleInput()
{
    if (InputManager::Get().GetMouseDown(Mouse::Left))
    {
        sf::Vector2f mouse = (sf::Vector2f)InputManager::Get().GetMousePos();
        Shoot(mouse);
    }
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
bool Player::CanShoot() const
{
    return m_shootTimer->GetTotalTime() >= m_shootCooldown;
}

void Player::Shoot(sf::Vector2f mouse)
{
    if (!CanShoot()) return;
    BulletFactory::Get().Create(mouse, m_pos);
    m_shootTimer->Reset();
}