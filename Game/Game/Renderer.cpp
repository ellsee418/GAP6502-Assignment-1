#include "Renderer.h"

Renderer::Renderer()
{
}

Renderer& Renderer::Get()
{
	static Renderer sInstance;
	return sInstance;
}

void Renderer::Render(sf::RenderWindow* windowPtr)
{
	windowPtr->clear(sf::Color::Black);

	sf::CircleShape shape(50.f, 3);
	shape.setPosition({ 500.f, 500.f });
	shape.setFillColor(sf::Color::Green);
	windowPtr->draw(shape);

	windowPtr->display();
}
