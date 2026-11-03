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

bool InputManager::GetKeyDown(sf::Keyboard::Key key)
{
	for (sf::Keyboard::Key k: m_keyDownEvents)
	{
		if (key == k)
			return true;
	}
	return false;
}

bool InputManager::GetKeyUp(sf::Keyboard::Key key)
{
	for (sf::Keyboard::Key k : m_keyReleasedEvents)
	{
		if (key == k)
			return true;
	}
	return false;
}

bool InputManager::GetKeyHeld(sf::Keyboard::Key key)
{
	bool k = m_keysHeld[key];
	return k;
}

bool InputManager::GetMouseDown(int button)
{
	return m_mouseButtons[button] == 1;
}

bool InputManager::GetMouseUp(int button)
{
	return m_mouseButtons[button] == 0;
}

bool InputManager::GetMouseHeld(int button)
{
	return GetMouseDown(button);// the same since button is down this frame?
}

sf::Vector2i InputManager::GetMousePos()
{
	return sf::Vector2i(m_mouseX, m_mouseY);
}

