#include "Renderer.h"

Renderer::Renderer(unsigned int height = 800, unsigned int width = 600) : mWindow(nullptr)
{
	mWindow = new sf::RenderWindow(sf::VideoMode({ height, width }), "fortnite");
}

Renderer& Renderer::Get()
{
	static Renderer sInstance;
	return sInstance;
}

void Renderer::Update()
{
	while (mWindow->isOpen())
	{
		sf::Event event;
		while (mWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mWindow->close();
		}
		mWindow->clear(sf::Color::Black);

		mWindow->display();
	}
}
