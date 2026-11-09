#include "Renderer.h"
#include "EventManager.h"
#include "common.h"
#include "Button.h"

Renderer::Renderer(unsigned int width = WIN_WIDTH, unsigned int height = WIN_HEIGHT)
	: m_window(nullptr)
{
	Init();
}

Renderer::~Renderer()
{
	delete m_window;// dont think this is necessary
}

Renderer& Renderer::Get()
{
	static Renderer sInstance;
	return sInstance;
}

void Renderer::Init()
{
	m_window = new sf::RenderWindow(sf::VideoMode({ WIN_WIDTH, WIN_HEIGHT }), "fortnite");
	m_window->setFramerateLimit(60);
	sf::Image icon;
	if (icon.loadFromFile("../Assets/fortnite.png"))
		m_window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
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

void Renderer::Render(std::vector<Button>& vec, sf::Font font)
{
	m_window->clear(sf::Color::Black);

	sf::Text title("fortnite", font);
	float yGap = 150.f;
	title.setPosition((WIN_WIDTH - title.getGlobalBounds().width) / 2, yGap);
	m_window->draw(title);

	for (int i = 0; i < vec.size(); ++i)
	{
		m_window->draw(vec[i].GetShape());
		m_window->draw(vec[i].GetText());
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


