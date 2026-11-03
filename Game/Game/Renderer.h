#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

class Renderer
{
public:
	static Renderer& Get();
	void Update();
	void Render();

	bool Active();
private:
	Renderer(unsigned int height, unsigned int width);


	sf::RenderWindow* m_window;
};

