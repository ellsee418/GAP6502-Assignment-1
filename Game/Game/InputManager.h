#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>


static class InputManager
{
public:
	static void OnEvent(const sf::Event& event);
	static void HandleKeyInput();
private:
	static int* m_keysHeld;
	static std::vector<sf::Keyboard::Key> m_keyDownEvents, m_keyReleasedEvents;// we love gamewell
};

