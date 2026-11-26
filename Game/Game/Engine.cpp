#include "Math.hpp"
#include "Engine.h"
#include "Renderer.h"
#include "EventManager.h"
#include "Game.h"
#include "Menu.h"
#include "GameOver.h"
#include "Logger.h"

//only for DeInit()
#include "UIManager.h"
#include "InputManager.h"

Engine* Engine::sInstance = nullptr;

Engine::Engine() 
	: m_gameState(new Menu)
{
	LOGA(SYSTEM, "[Engine] Create Instance.");
	InitRand();
	m_gameState->Enter();
}

Engine::~Engine()
{
}

bool Engine::HandleGameState()
{
	StateResult checkState = m_gameState->Update();

	switch (checkState)
	{
	case StateResult::EStateGame:
		ChangeState(new Game);
		break;
	case StateResult::EStateMenu:
		ChangeState(new Menu);
		break;
	case StateResult::EStateGameOver:
		ChangeState(new GameOver);
		break;
	case StateResult::EStateQuit:
		m_endGame = true;
		break;
	case StateResult::EStateContinue:
		break;
	}
	return m_endGame;
}

void Engine::ChangeState(IState* newState)
{
	if (m_gameState == newState)
		return;
	IState* temp = m_gameState;
	m_gameState->Exit();
	m_gameState = newState;
	m_gameState->Enter();
	if (temp != nullptr)
		delete temp;

}

Engine* Engine::Get()
{
	if (!sInstance) sInstance = new Engine();
	return sInstance;
}

void Engine::Run()
{
	Update();
}

void Engine::DeInit()
{
	// could put somewhere else so Engine doesnt have to include everything?
	UIManager::Get()->DeInit();
	Renderer::Get()->DeInit();
	InputManager::Get()->DeInit();
	LOGA(SYSTEM, "[Engine] Cleaning up...");
	delete m_gameState;
	delete sInstance;
}

void Engine::Update()
{
	while (!m_endGame)
	{
		if (HandleGameState()) break;
		m_gameState->Update();
		m_endGame = EventManager::PollEvents(Renderer::Get()->Window());
	}
	DeInit();
}

