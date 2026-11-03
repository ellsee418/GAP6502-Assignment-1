#pragma once
#include "Character.h"


class Player : public Character
{
public:
	Player(sf::Vector2f pos, sf::Color col, float size = 50.f, int points = 4, float angle = 45.f);

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
	int m_points;
	float m_angle;
};
