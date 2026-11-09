#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

class Button;

class Renderer
{
public:
	static Renderer& Get();
	void Init();

	void Render(std::vector<IEntity*>& vec);
	void Render(sf::Text& txt);
	void Render(std::vector<Button>& vec, sf::Font font);


	bool Active();
	sf::RenderWindow& Window() const;
	~Renderer();
private:
	Renderer(unsigned int height, unsigned int width);

	sf::RenderWindow* m_window;
};

