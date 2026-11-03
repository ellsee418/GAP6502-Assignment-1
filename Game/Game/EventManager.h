#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

static class EventManager
{
public:
	static bool PollEvents(sf::RenderWindow& window);
private:
	static void Dispatch(const sf::Event& event);
};

