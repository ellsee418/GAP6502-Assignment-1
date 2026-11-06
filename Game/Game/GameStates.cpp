#include "GameStates.h"
#include "Enemy.h"
#include "Player.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Collision.hpp"
#include "Button.h"


#include <stdio.h>

// move these to their own files man this is silly
// ------------------------------ GAME STATE ------------------------------ \\

GameState::GameState() 
	: m_player(nullptr)
{

}

GameState::~GameState()
{
	for (IEntity* e : m_entities)
		if (e) delete e;// includes player
}

void GameState::Init()
{

	for (int i = 0; i < 10; ++i)
		m_entities.push_back(new Enemy({ 50.f, (float)(i + 1.f) * 50.f }, sf::Color::Red));// delete plz

	m_player = new Player({ 400.f, 200.f }, sf::Color::Green);
	m_entities.push_back(m_player);
}

void GameState::Enter()
{
	Init();
}

void GameState::Exit()
{

}

StateResult GameState::Update()
{
	for (IEntity* e : m_entities)
	{
		if (!e->Active()) continue;
		e->Update();
		HandleCollidingBounds(e);
		if(e != m_player) HandleCollidingEntity(m_player, e);
	}
	if (!m_player->Active()) return StateResult::EStateGameOver;
	Renderer::Get().Render(m_entities);// do i want render to be handled here?

	return StateResult::EStateContinue;
}

// ------------------------------ MENU STATE ------------------------------ \\

MenuState::MenuState()
	: m_play(nullptr), m_quit(nullptr)
{
}

MenuState::~MenuState()
{
	delete m_play;
	delete m_quit;
}

void MenuState::Init()
{
	m_font.loadFromFile("../Assets/Pong.ttf");
	m_play = new Button(m_font, "Play", { 0.f,0.f});
	m_quit = new Button(m_font, "Quit", { 0.f,0.f});
	
	float gap = 10.f;
	m_play->SetPosition({ (WIN_WIDTH - m_play->GetBounds().width) / 2 ,	(WIN_HEIGHT - m_play->GetBounds().height - gap)  / 2 });
	m_quit->SetPosition({ (WIN_WIDTH - m_quit->GetBounds().width) / 2 , (WIN_HEIGHT + m_quit->GetBounds().height + gap)  / 2 });

	m_buttons.push_back(*m_play);
	m_buttons.push_back(*m_quit);
}

void MenuState::Enter()
{
	Init();
}

void MenuState::Exit()
{
}

StateResult MenuState::Update()
{
	m_play->Hover();
	m_quit->Hover();

	Renderer::Get().Render(m_buttons);


	if (m_play->Clicked())
		return StateResult::EStateGame;
	if (m_quit->Clicked())
		return StateResult::EStateQuit;

	return StateResult::EStateMenu;
}



// ------------------------------ GAME OVER STATE ------------------------------ \\

GameOverState::GameOverState()
	: m_text(nullptr)
{
}

GameOverState::~GameOverState()
{
	delete m_text;
}

void GameOverState::Init()
{
	m_font.loadFromFile("../Assets/Pong.ttf");
	std::string str = "u fuckig died man\n   'r' to restart";
	m_text = new sf::Text(str, m_font, 30);

	sf::FloatRect textRect = m_text->getLocalBounds();
	m_text->setOrigin(textRect.left + textRect.width / 2.f,
		textRect.top + textRect.height / 2.f);
	m_text->setPosition(WIN_WIDTH / 2.f, WIN_HEIGHT / 3.f);
}

void GameOverState::Enter()
{
	Init();
}

void GameOverState::Exit()
{
}

StateResult GameOverState::Update()
{
	Renderer::Get().Render(*m_text);

	if (InputManager::Get().GetKeyDown(sf::Keyboard::R))
		return StateResult::EStateGame;

	return StateResult::EStateGameOver;
}


