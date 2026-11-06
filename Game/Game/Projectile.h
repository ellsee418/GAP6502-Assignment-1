#pragma once
#include "Entity.h"
class Projectile : public Entity
{
public:
	Projectile(sf::Vector2f pos, sf::Vector2f target, sf::Color col = sf::Color::White, float size = 15.f, int points = 30, float angle = 0.f);

	void Update() override;
	void Fire();

	void OnBoundsCollision() override;
	void OnEntityCollision(IEntity* other) override;
private:

protected:
	float m_speed;
	sf::Vector2f m_target;
};

