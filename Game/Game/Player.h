#pragma once
#include "Character.h"
class Timer;

class Player final : public Character
{
public:
	Player(sf::Vector2f pos, sf::Color col, float size = 25.f, int points = 4, float angle = 45.f);
	~Player();
	void Update() override;
	void HandleInput();
	sf::Vector2f GetDirection();
	void Move() override;
	void OnEntityCollision(IEntity* other) override;

	bool CanShoot() const;
	void Shoot();

	const float m_shootCooldown = 0.2f;
private:

protected:
	Timer* m_shootTimer;
};
