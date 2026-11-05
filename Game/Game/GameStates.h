#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>


class IEntity;
class Player;

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


private:
	std::vector<IEntity*> m_entities;
	Player* m_player;
};

class GameOverState : public IState
{
public:
	GameOverState();
	~GameOverState() override;

	void Enter() override;
	void Exit() override;
	StateResult Update() override;

	void Init();


private:
	sf::Font m_font;
	sf::Text* m_text;
};