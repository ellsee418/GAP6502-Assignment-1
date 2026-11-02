#include "Character.h"

Character::Character(sf::Vector2f pos) : m_pos(pos), m_active(true)
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
