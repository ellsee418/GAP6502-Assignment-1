#include "InputManager.h"

// static member definitions


InputManager::InputManager()
	: m_keysHeld(nullptr), m_mouseButtons(nullptr), m_mouseX(0), m_mouseY(0)
{
	m_keysHeld = new int[sf::Keyboard::KeyCount];
	m_mouseButtons = new int[5] {};
}

InputManager::~InputManager()
{
	delete[] m_keysHeld;
	delete[] m_mouseButtons;
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
			//printf("KeyPressed: %d\n", event.key.scancode);
			break;
		}
		case sf::Event::KeyReleased:
		{
			m_keyReleasedEvents.push_back(event.key.code);
			m_keysHeld[event.key.code] = 0;
			//printf("KeyReleased: %d\n", event.key.scancode);
			break;
		}
		case sf::Event::MouseMoved:
		{
			m_mouseX = event.mouseMove.x;
			m_mouseY = event.mouseMove.y;
			//printf("Mouse x: %d Mouse y: %d\n", m_mouseX, m_mouseY);
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			m_mouseButtons[event.mouseButton.button] = 1;
			//printf("Mouse Button: %d clicked\n", event.mouseButton.button);
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
			m_mouseButtons[event.mouseButton.button] = 0;
			//printf("Mouse Button: %d released\n", event.mouseButton.button);
			break;
		}
	}

}

