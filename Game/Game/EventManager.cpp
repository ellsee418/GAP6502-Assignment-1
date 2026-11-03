#include "EventManager.h"

bool EventManager::PollEvents(sf::RenderWindow& window)
{
	if (!window.isOpen()) return false;

	bool windowOpen = true;
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			windowOpen = false;
			continue;
		}
		// send event to input manager etc.
	}
	// successfully polled events on window that is not closed
	return windowOpen;
}
