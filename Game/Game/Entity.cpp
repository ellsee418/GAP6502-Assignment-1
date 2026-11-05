#include "Entity.h"

Entity::Entity(sf::Vector2f pos, sf::Color col, float size, int points, float angle)
: m_active(true), m_colour(col), m_size(size), m_points(points), m_angle(angle), m_collides(false), m_velocity({0.f,0.f})
{
}

sf::Vector2f Entity::GetPosition()
{
    return m_pos;
}

void Entity::SetPosition(sf::Vector2f pos)
{
    m_pos = pos;
}

void Entity::Update()
{
    m_angle++;
}

bool Entity::Active()
{
    return m_active;
}

void Entity::Kill()
{
    m_active = false;
}

bool Entity::Collides()
{
    return m_collides;
}

float Entity::Angle()
{
    return m_angle;
}

void Entity::SetAngle(float angle)
{
    m_angle = angle;
}

sf::Vector2f Entity::Velocity()
{
    return m_velocity;
}

void Entity::SetVelocity(sf::Vector2f vel)
{
    m_velocity = vel;
}

sf::Color Entity::Colour()
{
    return m_colour;
}

float Entity::Size()
{
    return m_size;
}

int Entity::Points()
{
    return m_points;
}
