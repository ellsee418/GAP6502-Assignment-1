#include "GameStates.h"
#include "Character.h"
#include "Player.h"
#include "Renderer.h"
#include "InputManager.h"

#include <stdio.h>

// ------------------------------ GAME STATE ------------------------------ \\

GameState::GameState() 
	: m_player(nullptr)
{

}

GameState::~GameState()
{

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
	m_player->Move(GetInputDirection());

	Renderer::Get().Render(m_entities);// do i want render to be handled here? idk man i dont think so - i dont wanna pass vec to RendererUpdate tho

	return StateResult::EStateContinue;
}

void GameState::Init()
{
	//printf("GameState::Init() called. Creating Entities.\n");

	for (int i = 0; i < 10; ++i)
		m_entities.push_back(new Character({ (float)i, (float)i * 60.f }, sf::Color::Red));

	m_player = new Player({ 400.f, 200.f }, sf::Color::Green);
	m_entities.push_back(m_player);
}

sf::Vector2f GameState::GetInputDirection()
{
	// this feels weird having this here but it wont be used in any other state.
	// just feels wrong idk
	sf::Vector2f dir = { 0.f, 0.f };
	if (InputManager::Get().GetKeyHeld(sf::Keyboard::S))
		dir.y += 1;
	if (InputManager::Get().GetKeyHeld(sf::Keyboard::W))
		dir.y -= 1;
	if (InputManager::Get().GetKeyHeld(sf::Keyboard::D))
		dir.x += 1;
	if (InputManager::Get().GetKeyHeld(sf::Keyboard::A))
		dir.x -= 1;

	return dir;
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
