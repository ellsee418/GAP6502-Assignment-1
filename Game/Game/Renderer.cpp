#include "Renderer.h"
#include "EventManager.h"

Renderer::Renderer(unsigned int width = 800, unsigned int height = 600)
	: m_window(nullptr)
{
	m_window = new sf::RenderWindow(sf::VideoMode({ width, height }), "fortnite");
}

Renderer& Renderer::Get()
{
	static Renderer sInstance;
	return sInstance;
}

void Renderer::Update()
{
	if (!EventManager::PollEvents(m_window)) return;
	
	Render();
}

void Renderer::Render()
{
	m_window->clear(sf::Color::Black);

	sf::CircleShape shape(50.f, 3);
	shape.setPosition({ 500.f, 500.f });
	shape.setFillColor(sf::Color::Green);
	m_window->draw(shape);

	m_window->display();
}

bool Renderer::Active()
{
	return m_window->isOpen();
}
