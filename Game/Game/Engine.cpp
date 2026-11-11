#include "Math.hpp"
#include "Engine.h"
#include "Renderer.h"
#include "EventManager.h"
#include "Game.h"
#include "Menu.h"
#include "GameOver.h"

Engine::Engine() 
	: m_gameState(new Menu)
{
	InitRand();
	m_gameState->Enter();
}

Engine::~Engine()
{
	delete m_gameState;
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

Engine& Engine::Get()
{
	static Engine sInstance;
	return sInstance;
}

void Engine::Run()
{
	Update();
}

void Engine::Update()
{
	while (!m_endGame)
	{
		if (HandleGameState()) break;
		m_gameState->Update();
		EventManager::PollEvents(Renderer::Get().Window());
		m_endGame = !Renderer::Get().Active();
	}
}

