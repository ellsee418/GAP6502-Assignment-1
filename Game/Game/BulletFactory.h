#pragma once
#include <SFML/System/Vector2.hpp>
class BulletFactory
{
public:
	static BulletFactory& Get();
	void Init();
	void Create(sf::Vector2f target, sf::Vector2f spawn);


	~BulletFactory();
private:
	BulletFactory();
};

