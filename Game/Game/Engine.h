#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "IState.h"

class Engine
{
public:
	static Engine& Get();

	void Run();
	void Update();
private:
	Engine();
	~Engine();

	bool HandleGameState();
	void ChangeState(IState* newState);

	IState* m_gameState;
	bool m_endGame = false;
protected:

};

