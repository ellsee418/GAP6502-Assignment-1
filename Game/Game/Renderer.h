#pragma once

#include <SFML/Graphics.hpp>
class Renderer
{
public:
	static Renderer& Get();
	void Update();

private:
	Renderer(unsigned int width, unsigned int height);
	sf::RenderWindow* mWindow;
};

