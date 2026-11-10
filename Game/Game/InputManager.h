#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

enum Mouse 
{
	Left = 0,
	Right,
	Middle,
	Back,
	Front
};
class InputManager
{
public:
	~InputManager();
	static InputManager& Get();
	void ClearEvents();
	void OnEvent(const sf::Event& event);

	bool GetKeyDown(sf::Keyboard::Key key) const;
	bool GetKeyUp(sf::Keyboard::Key key) const;
	bool GetKeyHeld(sf::Keyboard::Key key) const;

	bool GetMouseDown(int button) const;
	bool GetMouseUp(int button) const;
	bool GetMouseHeld(int button) const;

	sf::Vector2i GetMousePos() const;

private:
	InputManager();
	int* m_keysHeld;
	int* m_mouseButtons;
	int m_mouseX, m_mouseY;
	std::vector<sf::Keyboard::Key> m_keyDownEvents, m_keyReleasedEvents;
};

