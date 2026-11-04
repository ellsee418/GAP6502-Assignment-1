#pragma once
#include "Character.h"
#include "Math.hpp"

class Player final : public Character
{
public:
	Player(sf::Vector2f pos, sf::Color col, float size = 50.f, int points = 4, float angle = 45.f);

	virtual sf::Vector2f GetPosition() override;
	virtual void SetPosition(sf::Vector2f pos) override;

	void Update() override;
	bool Active() override;
	void Kill() override;

	float Angle() override;
	sf::Color Colour() override;
	float Size() override;
	int Points() override;
	float Speed() override;

	sf::Vector2f GetDirection();
	void Move() override;

private:
	bool m_active;
	sf::Vector2f m_pos;
	sf::Color m_colour;
	float m_size;// fixed for now, add w/l later
	int m_points;
	float m_angle;
	float m_speed;
};
