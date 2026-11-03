#include "InputManager.h"

// static member definitions


InputManager::InputManager()
	: m_keysHeld(nullptr)
{
	m_keysHeld = new int[sf::Keyboard::KeyCount];
}

InputManager::~InputManager()
{
	delete[] m_keysHeld;
}

InputManager& InputManager::Get()
{
	static InputManager sInstance;
	return sInstance;
}

void InputManager::OnEvent(const sf::Event& event)
{
	m_keyDownEvents.clear();
	m_keyReleasedEvents.clear();

	switch (event.type)
	{
		case sf::Event::KeyPressed:
		{
			m_keyDownEvents.push_back(event.key.code);
			m_keysHeld[event.key.code] = 1;// mark as currently down - for held
			printf("KeyPressed: %d\n", event.key.scancode);
			break;
		}
		case sf::Event::KeyReleased:
		{
			m_keyReleasedEvents.push_back(event.key.code);
			m_keysHeld[event.key.code] = 0;
			printf("KeyReleased: %d\n", event.key.scancode);
			break;
		}
	}

}

