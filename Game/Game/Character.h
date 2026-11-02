#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>



class IEntity
{
public:
	virtual sf::Vector2f GetPosition() = 0;
	virtual void SetPosition(sf::Vector2f pos) = 0;

	virtual bool Active() = 0;
	virtual void Kill() = 0;
private:

};

class Character : public IEntity
{
public:
	Character(sf::Vector2f pos);

	virtual sf::Vector2f GetPosition() override;
	virtual void SetPosition(sf::Vector2f pos) override;

	virtual bool Active() override;
	virtual void Kill() override;
private:
	bool m_active;
	sf::Vector2f m_pos;
	sf::Vector3i m_colour;
};