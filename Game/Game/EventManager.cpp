#include "EventManager.h"
#include <SFML/Graphics.hpp>
#include "InputManager.h"


bool EventManager::PollEvents(sf::RenderWindow& window)
{
	InputManager::Get().ClearEvents();

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
		Dispatch(event);
	}
	return windowOpen;
}

void EventManager::Dispatch(const sf::Event& event)
{
	InputManager::Get().OnEvent(event);
}
