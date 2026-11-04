#pragma once
#include "Entity.h"

class Character : public Entity
{
public:
	Character(sf::Vector2f pos = {0.f, 0.f}, sf::Color col = sf::Color::Red, float size = 30.f, int points = 3, float angle = 0.f);

	virtual sf::Vector2f GetPosition() override;
	virtual void SetPosition(sf::Vector2f pos) override;

	bool Active() override;
	void Kill() override;

	virtual float Angle() override;
	virtual sf::Color Colour() override;
	virtual float Size() override;
	virtual int Points() override;

private:
	bool m_active;
	sf::Vector2f m_pos;
	sf::Color m_colour;
	float m_size;// fixed for now, add w/l later
	float m_angle;
	int m_points;
};