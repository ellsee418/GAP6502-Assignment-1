#include "Engine.h"
#include "Renderer.h"

Engine::Engine(unsigned int width = 800, unsigned int height = 600) 
	: m_window(nullptr), m_gameState(new GameState)
{
	m_window = new sf::RenderWindow(sf::VideoMode({ width, height }), "fortnite");
}

Engine::~Engine()
{
	delete m_window;
}

bool Engine::HandleGameState()
{
	StateResult checkState = m_gameState->Update();

	switch (checkState)
	{
	case StateResult::StateGame:
		ChangeState(new GameState);
		break;
	case StateResult::StateMenu:
		ChangeState(new MenuState);
		break;
	//case StateResult::StateGameOver:
	//	ChangeState(new GameOverState);
	//	break;
	case StateResult::StateQuit:
		m_endGame = true;
		break;
	//case Continue:
	//	break;
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
	while (m_window->isOpen())
	{
		sf::Event event;
		while (m_window->pollEvent(event))
			if (event.type == sf::Event::Closed) 
				m_window->close();

		HandleGameState();
		Update();
	}
}

void Engine::Update()
{
	Renderer::Get().Render(m_window);
}

