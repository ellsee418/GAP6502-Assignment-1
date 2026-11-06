#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>


class IEntity;
class Player;
class Button;

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

class GameState : public IState
{
public:
	GameState();
	~GameState() override;

	void Enter() override;
	void Exit() override;
	StateResult Update() override;

	void Init();
	StateResult HandleInput();
	StateResult HandleEntities();

	void TryShoot();

	static bool Continued(StateResult& out, StateResult r);

private:
	std::vector<IEntity*> m_entities;
	Player* m_player;
	int m_score;
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
	sf::Font m_font;
	Button* m_play;
	Button* m_quit;
	std::vector<Button> m_buttons;
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