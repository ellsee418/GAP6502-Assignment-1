#include "EventManager.h"

bool EventManager::PollEvents(sf::RenderWindow* window)
{
	if (!window->isOpen()) return false;

	sf::Event event;
	if (!window->pollEvent(event)) return false;

	if (event.type == sf::Event::Closed)
	{
		window->close();
		return false;
	}

	// successfully polled events on window that is not closed
	return true;
}
