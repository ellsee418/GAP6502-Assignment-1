#include "Projectile.h"
#include "Math.hpp"

Projectile::Projectile(sf::Vector2f pos, sf::Vector2f target, sf::Color col, float size, int points, float angle)
	: Entity(pos, col, size, points, angle), m_speed(6.f)
{
    m_angle = angle;
    m_target = target;
    m_size = size;
    m_speed = 6.f;
    m_pos = pos;
    m_type = EntityType::Projectile;
    Fire();
}

void Projectile::Update()
{
	m_pos += m_velocity;
}

void Projectile::Fire()
{
    sf::Vector2f dir = { 0.f, 0.f };
    float o = (m_target.y - m_pos.y);
    float a = (m_target.x - m_pos.x);
    float angle = std::atan2(o, a);

    m_angle = angle * (180.f / 3.14159f);

    dir.x = std::cos(angle);
    dir.y = std::sin(angle);

    m_velocity = sf::Vector2f(dir.x * m_speed, dir.y * m_speed);
}

void Projectile::OnBoundsCollision()
{
    Kill();
}

void Projectile::OnEntityCollision(IEntity* other)
{
    if (other->Type() == m_type) return;
    if (other->Type() == EntityType::Player) return;
    if (other->Type() == EntityType::Enemy) other->Kill();


    Kill();
}
