#include "EventManager.h"
#include <SFML/Graphics.hpp>
#include "InputManager.h"


bool EventManager::PollEvents(sf::RenderWindow& window)
{
	InputManager::Get()->ClearEvents();

	if (!window.isOpen()) return true;

	bool windowClosed = false;
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			windowClosed = true;
			continue;
		}
		Dispatch(event);
	}
	return windowClosed;
}

void EventManager::Dispatch(const sf::Event& event)
{
	InputManager::Get()->OnEvent(event);
}
