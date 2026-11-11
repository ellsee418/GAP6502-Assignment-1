#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

enum Mouse 
{
	Left = 0,
	Right,
	Middle,
	Back,
	Front
};
class InputManager
{
public:
	~InputManager();
	static InputManager& Get();
	void ClearEvents();
	void OnEvent(const sf::Event& event);

	bool GetKeyDown(sf::Keyboard::Key key) const;
	bool GetKeyUp(sf::Keyboard::Key key) const;
	bool GetKeyHeld(sf::Keyboard::Key key) const;

	bool GetMouseDown(int button) const;
	bool GetMouseUp(int button) const;
	bool GetMouseHeld(int button) const;

	sf::Vector2i GetMousePos() const;

private:
	InputManager();
	int* m_keysHeld;
	int* m_mouseButtons;
	int m_mouseX, m_mouseY;

	class KeyArray
		// i found it hard to fit in dynamic arrays without making a templated vector implementation.
		// this is the simplest case i could find where it is useful without being better to template.
	{
	public:
		KeyArray(int capacity = 16) { m_array = new sf::Keyboard::Key[capacity]; m_capacity = capacity; }
		~KeyArray() { delete[] m_array; }

		void Clear() { m_size = 0; }
		void PushBack(sf::Keyboard::Key key)
		{
			if (m_size < m_capacity) m_array[m_size++] = key;
			else
			{
				Resize();
				PushBack(key);
				// never really needs to resize, but has been tested.
			}
		}

		int Size() const { return m_size; }
		sf::Keyboard::Key operator[](int i) const {return m_array[i]; }//  KeyArray[i] -> m_array[i]

	private:
		void Resize()
		{
			m_capacity *= 2;
			sf::Keyboard::Key* newArray = new sf::Keyboard::Key[m_capacity];

			for (int i = 0; i < m_size; i++)
				newArray[i] = m_array[i];
			delete[] m_array;
			m_array = newArray;
		}

		sf::Keyboard::Key* m_array = nullptr;
		int m_capacity = 0;
		int m_size = 0;
	};

	KeyArray m_keyDownEvents, m_keyReleasedEvents;
};

