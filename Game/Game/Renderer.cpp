#include "Renderer.h"
#include "EventManager.h"
#include "common.h"

Renderer::Renderer(unsigned int width = WIN_WIDTH, unsigned int height = WIN_HEIGHT)
	: m_window(nullptr)
{
	m_window = new sf::RenderWindow(sf::VideoMode({ width, height }), "fortnite");
	m_window->setFramerateLimit(60);
}

Renderer& Renderer::Get()
{
	static Renderer sInstance;
	return sInstance;
}

void Renderer::Update()
{

}

void Renderer::RenderTest()
{
	m_window->clear(sf::Color::Black);

	sf::CircleShape shape(50.f, 3);
	shape.setPosition({ 500.f, 500.f });
	shape.setFillColor(sf::Color::Green);
	m_window->draw(shape);

	m_window->display();
}

void Renderer::Render(std::vector<IEntity*>& vec)
{
	m_window->clear(sf::Color::Black);

	for (int i = 0; i < vec.size(); ++i)
	{
		auto& e = vec[i];
		if (!e->ShouldDraw()) continue;
		sf::CircleShape shape(e->Size(), e->Points());
		shape.setOrigin({ e->Size() , e->Size() });
		shape.setPosition(e->GetPosition());
		shape.setFillColor(e->GetColour());
		shape.setRotation(e->GetAngle());
		m_window->draw(shape);
	}
	m_window->display();

}

void Renderer::Render(sf::Text& txt)
{
	m_window->clear(sf::Color::Red);
	m_window->draw(txt);
	m_window->display();
}

bool Renderer::Active()
{
	return m_window->isOpen();
}

sf::RenderWindow& Renderer::Window() const
{
	return *m_window;
}
