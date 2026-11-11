#pragma once

enum class StateResult
{
	EStateMenu = 0,
	EStateGame,
	EStateGameOver,
	EStateQuit,
	EStateContinue
};

class IState
{
public:
	virtual void Enter() = 0;
	virtual void Exit() = 0;
	virtual StateResult Update() = 0;

	virtual ~IState() = default;
};

