#pragma once
#include "Entity.h"

class Character : public Entity
{
public:
	Character(sf::Vector2f pos = {0.f, 0.f}, sf::Color col = sf::Color::Red, float size = 30.f, int points = 3, float angle = 0.f);

	virtual void Update() override;
	virtual float Speed() const;
	virtual void Move();

	virtual int GetHealth()const;
	virtual void TakeDamage(int dmg);
	virtual void AddHealth(int hp);// in case of healing item
	virtual void OnDeath();
protected:
	float m_speed;
	int m_health;
};