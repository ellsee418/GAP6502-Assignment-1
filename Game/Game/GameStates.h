#pragma once

#include <vector>

class IEntity;

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

class MenuState : public IState
{
public:
	MenuState();
	~MenuState() override;

	void Enter() override;
	void Exit() override;
	StateResult Update() override;

	void Init();


private:

};

class GameState : public IState
{
public:
	GameState();
	~GameState() override;

	void Enter() override;
	void Exit() override;
	StateResult Update() override;

	void Init();

	std::vector<IEntity*> m_entities;
	IEntity* m_player;
private:

};