#include "Entity.h"

Entity::Entity(sf::Vector2f pos, sf::Color col, float size, int points, float angle)
: m_active(true), m_colour(col), m_size(size), m_points(points), m_angle(angle), m_collides(true), m_velocity({0.f,0.f}), m_type(EntityType::Entity), m_draw(m_active)
{
}

void Entity::Update()
{
    //m_angle++;
}

bool Entity::Active()
{
    return m_active;
}

void Entity::Kill()
{
    m_active = false;
    m_collides = false;
    m_draw = false;
}

bool Entity::Collides()
{
    return m_collides;
}

bool Entity::ShouldDraw()
{
    return m_draw;
}

EntityType Entity::Type()
{
    return m_type;
}

sf::Vector2f Entity::GetPosition()
{
    return m_pos;
}

void Entity::SetPosition(sf::Vector2f pos)
{
    m_pos = pos;
}

float Entity::GetAngle()
{
    return m_angle;
}

void Entity::SetAngle(float angle)
{
    m_angle = angle;
}

sf::Vector2f Entity::GetVelocity()
{
    return m_velocity;
}

void Entity::SetVelocity(sf::Vector2f vel)
{
    m_velocity = vel;
}

sf::Color Entity::GetColour()
{
    return m_colour;
}

void Entity::SetColour(sf::Color col)
{
    m_colour = col;
}

float Entity::Size()
{
    return m_size;
}

int Entity::Points()
{
    return m_points;
}
