#include "Renderer.h"
#include "EventManager.h"
#include "UIManager.h"
#include "common.h"
#include "Button.h"

Renderer::Renderer(unsigned int width = WIN_WIDTH, unsigned int height = WIN_HEIGHT)
	: m_window(nullptr)
{
	Init();
	m_font.loadFromFile("../Assets/Pong.ttf");
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
	m_window = new sf::RenderWindow(sf::VideoMode({ WIN_WIDTH, WIN_HEIGHT }), "video game");
	m_window->setFramerateLimit(60);
	sf::Image icon;
	if (icon.loadFromFile("../Assets/icon.png"))
		m_window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Renderer::Render(std::vector<IEntity*>& vec)
{
	m_window->clear(sf::Color::Black);

	for (int i = 0; i < vec.size(); ++i)
	{
		IEntity* e = vec[i];
		if (!e->ShouldDraw()) continue;
		sf::CircleShape shape(e->Size(), e->Points());
		shape.setOrigin({ e->Size() , e->Size() });
		shape.setPosition(e->GetPosition());
		shape.setFillColor(e->GetColour());
		shape.setRotation(e->GetAngle());
		m_window->draw(shape);
	}

	sf::Text scoreText;
	sf::Text healthText;
	UIManager::Get().UpdateUI(scoreText, healthText, m_font);

	m_window->draw(scoreText);
	m_window->draw(healthText);
	m_window->display();
}

void Renderer::Render(sf::Text& txt, int score)
{
	m_window->clear(sf::Color::Red);
	m_window->draw(txt);

	std::string scoreStr = "Score: " + std::to_string(score);
	sf::Text scoreText(scoreStr, m_font);
	float padding = 10.f;
	scoreText.setPosition(WIN_WIDTH / 2 - scoreText.getGlobalBounds().width /2 ,
		WIN_HEIGHT /2 + scoreText.getGlobalBounds().height);

	m_window->draw(scoreText);
	m_window->display();
}

void Renderer::Render(std::vector<Button>& vec, sf::Font font)
{
	m_window->clear(sf::Color::Black);

	sf::Text title("video game", font);
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


