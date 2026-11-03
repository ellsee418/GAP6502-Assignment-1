#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

class Renderer // maybe static instead of singleton
{
public:
	static Renderer& Get();
	void Update();
	void RenderTest();
	void Render(std::vector<IEntity*>& vec);

	bool Active();
	sf::RenderWindow& Window() const;

private:
	Renderer(unsigned int height, unsigned int width);

	sf::RenderWindow* m_window;
};

