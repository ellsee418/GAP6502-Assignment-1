#pragma once
#include "IState.h"

class Player;


class Game : public IState
{
public:
	Game();
	~Game() override;

	void Enter() override;
	void Exit() override;
	StateResult Update() override;

	void Init();
	StateResult HandleStates();
	static bool Continued(StateResult& out, StateResult r);

protected:
	Player* m_player;
	int m_score;
};
