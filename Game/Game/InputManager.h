#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>


class InputManager
{
public:
	~InputManager();
	static InputManager& Get();
	void ClearEvents();
	void OnEvent(const sf::Event& event);

	bool GetKeyDown(sf::Keyboard::Key key);
	bool GetKeyUp(sf::Keyboard::Key key);
	bool GetKeyHeld(sf::Keyboard::Key key);

	bool GetMouseDown(int button);
	bool GetMouseUp(int button);
	bool GetMouseHeld(int button);

	sf::Vector2i GetMousePos();

private:
	InputManager();
	int* m_keysHeld;
	int* m_mouseButtons;
	int m_mouseX, m_mouseY;
	std::vector<sf::Keyboard::Key> m_keyDownEvents, m_keyReleasedEvents;
};

