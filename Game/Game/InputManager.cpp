#include "InputManager.h"

InputManager::InputManager()
	: m_keysHeld(nullptr), m_mouseButtons(nullptr), m_mouseX(0), m_mouseY(0)
{
	m_keysHeld = new int[sf::Keyboard::KeyCount];
	m_mouseButtons = new int[sf::Mouse::ButtonCount] {};
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

void InputManager::ClearEvents()
{
	m_keyDownEvents.Clear();
	m_keyReleasedEvents.Clear();
}

void InputManager::OnEvent(const sf::Event& event)
{
	switch (event.type)
	{
		case sf::Event::KeyPressed:
		{
			m_keyDownEvents.PushBack(event.key.code);
			m_keysHeld[event.key.code] = 1;
			//printf("KeyPressed: %d\n", event.key.scancode);
			break;
		}
		case sf::Event::KeyReleased:
		{
			m_keyReleasedEvents.PushBack(event.key.code);
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

bool InputManager::GetKeyDown(sf::Keyboard::Key key) const
{
	for(int i = 0; i < m_keyDownEvents.Size(); ++i)
	{
		if (key == m_keyDownEvents[i])
			return true;
	}
	return false;
}

bool InputManager::GetKeyUp(sf::Keyboard::Key key) const
{
	for (int i = 0; i < m_keyReleasedEvents.Size(); ++i)
	{
		if (key == m_keyReleasedEvents[i])
			return true;
	}
	return false;
}

bool InputManager::GetKeyHeld(sf::Keyboard::Key key) const
{
	return sf::Keyboard::isKeyPressed(key);
}

bool InputManager::GetMouseDown(int button) const
{
	return m_mouseButtons[button] == 1;
}

bool InputManager::GetMouseUp(int button) const
{
	return m_mouseButtons[button] == 0;
}

bool InputManager::GetMouseHeld(int button) const
{
	return GetMouseDown(button);// the same since button is down this frame?
}

sf::Vector2i InputManager::GetMousePos() const
{
	return sf::Vector2i(m_mouseX, m_mouseY);
}