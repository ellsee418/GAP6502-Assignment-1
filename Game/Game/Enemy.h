#pragma once
#include "Character.h"
#include "Timer.h"

class Enemy : public Character
{
public:
	Enemy(sf::Vector2f pos = { 0.f, 0.f }, sf::Color col = sf::Color::Red, float size = 20.f, int points = 3, float angle = 0.f);
	~Enemy();

	virtual void Update() override;
	virtual void HandleMovementDirection();
	virtual void Move() override;

	virtual void OnBoundsCollision() override;
private:

protected:
	Timer* m_directionTimer;
	float m_nextTurnTime;
};

