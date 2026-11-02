#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "GameStates.h"

class Engine// rename to game perhaps since this is not really gonna be the engine
{
public:
	static Engine& Get();

	void Run();
	void Update();
private:
	Engine(unsigned int height, unsigned int width);
	~Engine();

	bool HandleGameState();
	void ChangeState(IState* newState);

	sf::RenderWindow* m_window;
	IState* m_gameState;
	bool m_endGame = false;
protected:

};

