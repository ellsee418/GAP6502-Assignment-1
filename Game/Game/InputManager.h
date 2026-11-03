#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>


class InputManager
{
public:
	~InputManager();
	static InputManager& Get();
	void OnEvent(const sf::Event& event);

private:
	InputManager();
	int* m_keysHeld;
	std::vector<sf::Keyboard::Key> m_keyDownEvents, m_keyReleasedEvents;// we love gamewell
};

