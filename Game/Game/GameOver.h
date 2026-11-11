#pragma once
#include "IState.h"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class IState;


class GameOver : public IState
{
public:
	GameOver();
	~GameOver() override;

	void Enter() override;
	void Exit() override;
	StateResult Update() override;

	void Init();


private:
	sf::Font m_font;
	sf::Text* m_text;
	int m_score;
};
