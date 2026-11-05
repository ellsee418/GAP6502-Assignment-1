#pragma once
#include "Character.h"
#include "Math.hpp"

class Player final : public Character
{
public:
	Player(sf::Vector2f pos, sf::Color col, float size = 25.f, int points = 4, float angle = 45.f);

	sf::Vector2f GetDirection();
	void Move() override;
	void OnEntityCollision(IEntity* other) override;
private:

protected:

};
