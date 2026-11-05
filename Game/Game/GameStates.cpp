#include "GameStates.h"
#include "Enemy.h"
#include "Player.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Collision.hpp"


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

void GameState::Enter()
{
	//printf("GameState::Enter() called.\n");
	Init();
}

void GameState::Exit()
{
	//printf("GameState::Exit() called.\n");
	// cleanup pointers and such
}

StateResult GameState::Update()
{
	//printf("GameState::Update() called.\n");
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

void GameState::Init()
{
	//printf("GameState::Init() called. Creating Entities.\n");

	for (int i = 0; i < 10; ++i)
		m_entities.push_back(new Enemy({ 50.f, (float)(i+1.f) * 50.f }, sf::Color::Red));// delete plz

	m_player = new Player({ 400.f, 200.f }, sf::Color::Green);
	m_entities.push_back(m_player);
}

// ------------------------------ MENU STATE ------------------------------ \\

MenuState::MenuState()
{
}

MenuState::~MenuState()
{
}

void MenuState::Enter()
{
	//printf("MenuState::Enter() called.\n");
	Init();
}

void MenuState::Exit()
{
	//printf("MenuState::Exit() called.\n");
	// cleanup pointers and such
}

StateResult MenuState::Update()
{
	//printf("MenuState::Exit() called.\n");

	static int countTo1000 = 0;

	if (countTo1000 >= 1000)
	{
		countTo1000 = 0;
		return StateResult::EStateGame;
	}

	++countTo1000;

	return StateResult::EStateMenu;
}

void MenuState::Init()
{

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

void GameOverState::Enter()
{
	//printf("MenuState::Enter() called.\n");
	Init();
}

void GameOverState::Exit()
{
	//printf("MenuState::Exit() called.\n");
	// cleanup pointers and such
}

StateResult GameOverState::Update()
{
	Renderer::Get().Render(*m_text);

	if (InputManager::Get().GetKeyDown(sf::Keyboard::R))
		return StateResult::EStateGame;

	return StateResult::EStateGameOver;
}

void GameOverState::Init()
{
	m_font.loadFromFile("../Assets/Pong.ttf");// this might break
	std::string str = "u fuckig died man\n   'r' to restart";
	m_text = new sf::Text(str, m_font, 30);

	sf::FloatRect textRect = m_text->getLocalBounds();
	m_text->setOrigin(textRect.left + textRect.width / 2.f,
		textRect.top + textRect.height / 2.f);
	m_text->setPosition(WIN_WIDTH / 2.f, WIN_HEIGHT / 3.f);
}
