#include "Game.h"
#include "Math.hpp"
#include "EntityManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "common.h"
#include "Player.h"
#include "Enemy.h"

Game::Game()
	: m_player(nullptr), m_score(0)
{

}

Game::~Game()
{

}

void Game::Init()
{
	m_player = new Player({ WIN_WIDTH / 2.f, WIN_HEIGHT / 2.f }, sf::Color::Green);
	UIManager::Get().Init(m_player);
	EntityManager::Get()->AddEntity(m_player);

	for (int i = 0; i < 10; ++i)
		EntityManager::Get()->AddEntity((new Enemy(RandomPosition(m_player->GetPosition()), sf::Color::Red)));
}

StateResult Game::HandleStates()
{
	//TODO: add pause
	if (InputManager::Get().GetKeyDown(sf::Keyboard::Escape))
		return StateResult::EStateMenu;
	if (!m_player->Active())
		return StateResult::EStateGameOver;
	return StateResult::EStateContinue;
}

void Game::Enter()
{
	Init();
}

void Game::Exit()
{
	EntityManager::Get()->DeInit();
}

StateResult Game::Update()
{
	StateResult result;
	if (Continued(result, HandleStates()))
		EntityManager::Get()->Update();

	return result;
}

bool Game::Continued(StateResult& out, StateResult result)
{
	out = result;
	return result == StateResult::EStateContinue;
}