#include "GameOver.h"
#include "common.h"
#include "UIManager.h"
#include "InputManager.h"
#include "Renderer.h"

GameOver::GameOver()
	: m_text(nullptr), m_score(0)
{
}

GameOver::~GameOver()
{
	delete m_text;
}

void GameOver::Init()
{
	m_font.loadFromFile("../Assets/Pong.ttf");
	std::string str = "  u died man\n'r' to restart\n 'esc' to exit";
	m_text = new sf::Text(str, m_font, 30);

	sf::FloatRect textRect = m_text->getLocalBounds();
	m_text->setOrigin(textRect.left + textRect.width / 2.f,
		textRect.top + textRect.height / 2.f);
	m_text->setPosition(WIN_WIDTH / 2.f, WIN_HEIGHT / 3.f);

}

void GameOver::Enter()
{
	Init();
}

void GameOver::Exit()
{
	UIManager::Get().ResetScore();
}

StateResult GameOver::Update()
{
	Renderer::Get().Render(*m_text, m_score);

	if (InputManager::Get().GetKeyDown(sf::Keyboard::R))
		return StateResult::EStateGame;
	if (InputManager::Get().GetKeyDown(sf::Keyboard::Escape))
		return StateResult::EStateMenu;

	return StateResult::EStateContinue;
}
