#pragma once


class IState
{
public:
	virtual void Enter() = 0;
	virtual void Toggle() = 0;
	virtual void Exit() = 0;
	virtual ~IState() {}
private:

};

class GameState : public IState
{
public:
	void Enter() override;
	void Toggle() override;
	void Exit() override;


private:

};