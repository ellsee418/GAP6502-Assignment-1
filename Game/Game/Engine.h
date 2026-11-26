#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "IState.h"

class Engine
{
public:
	static Engine* Get();

	void Run();
	void Update();
	void DeInit();

	Engine(Engine& other) = delete;
	void operator=(const Engine&) = delete;
private:
	Engine();
	~Engine();

	bool HandleGameState();
	void ChangeState(IState* newState);

	IState* m_gameState;
	bool m_endGame = false;
	static Engine* sInstance;
protected:

};

