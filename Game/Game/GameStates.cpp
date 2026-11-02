#include "GameStates.h"
#include <stdio.h>

// ------------------------------ GAME STATE ------------------------------ \\

GameState::GameState()
{

}

GameState::~GameState()
{

}

void GameState::Enter()
{
	printf("GameState::Enter() called.\n");
	Init();
}

void GameState::Exit()
{
	printf("GameState::Exit() called.\n");
	// cleanup pointers and such
}

StateResult GameState::Update()
{
	printf("GameState::Exit() called.\n");

	static int countTo1000 = 0;

	if (countTo1000 >= 1000)
	{
		countTo1000 = 0;
		return StateResult::StateMenu;
	}
	++countTo1000;

	return StateResult::StateGame;
}

void GameState::Init()
{
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
	printf("MenuState::Enter() called.\n");
	Init();
}

void MenuState::Exit()
{
	printf("MenuState::Exit() called.\n");
	// cleanup pointers and such
}

StateResult MenuState::Update()
{
	printf("MenuState::Exit() called.\n");

	static int countTo1000 = 0;

	if (countTo1000 >= 1000)
	{
		countTo1000 = 0;
		return StateResult::StateGame;
	}

	++countTo1000;

	return StateResult::StateMenu;
}

void MenuState::Init()
{

}
