#pragma once
#include "IState.h"

#include <vector>
#include <SFML/Graphics/Font.hpp>

class IState;
class Button;


class Menu : public IState
{
public:
	Menu();
	~Menu() override;

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

