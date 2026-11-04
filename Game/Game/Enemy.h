#pragma once
#include "Character.h"
#include "Timer.h"

class Enemy : public Character
{
public:
	Enemy(sf::Vector2f pos = { 0.f, 0.f }, sf::Color col = sf::Color::Red, float size = 20.f, int points = 3, float angle = 0.f);
	~Enemy();
	virtual sf::Vector2f GetPosition() override;
	virtual void SetPosition(sf::Vector2f pos) override;

	virtual void Update() override;
	bool Active() override;
	void Kill() override;
	bool Collides() override;

	virtual float Angle() override;
	virtual void SetAngle(float angle) override;
	virtual sf::Color Colour() override;
	virtual float Size() override;
	virtual int Points() override;
	virtual float Speed();

	virtual void HandleMovementDirection();
	virtual void Move() override;

private:
	bool m_active, m_collides;
	sf::Vector2f m_pos;
	sf::Color m_colour;
	float m_size;// fixed for now, add w/l later
	float m_angle;
	int m_points;
	float m_speed;
	float m_nextTurnTime;

	Timer* m_directionTimer;
};

