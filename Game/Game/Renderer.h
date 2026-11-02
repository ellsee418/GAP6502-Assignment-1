#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

class Renderer
{
public:
	static Renderer& Get();
	void Render(sf::RenderWindow* windowPtr);

private:
	Renderer();
};

