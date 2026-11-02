#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"	

class Engine
{
public:
	static Engine& Get();

	void Run();
	void Update();
private:
	Engine(unsigned int height, unsigned int width);
	~Engine();

	sf::RenderWindow* mWindow;
protected:

};

