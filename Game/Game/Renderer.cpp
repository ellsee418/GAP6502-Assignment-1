#include "Renderer.h"
#include "EventManager.h"

Renderer::Renderer(unsigned int width = 800, unsigned int height = 600)
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
		sf::CircleShape shape(e->Size(), e->Points());
		shape.setOrigin({ e->Size() / 2, e->Size() / 2});
		shape.setPosition(e->GetPosition());
		shape.setFillColor(e->Colour());
		shape.setRotation(e->Angle());
		m_window->draw(shape);
	}
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
