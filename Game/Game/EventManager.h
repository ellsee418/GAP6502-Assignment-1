#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class EventManager
{
public:
	static bool PollEvents(sf::RenderWindow& window);
private:
	static void Dispatch(const sf::Event& event);
};

