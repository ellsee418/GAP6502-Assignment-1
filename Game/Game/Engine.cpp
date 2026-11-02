#include "Engine.h"
#include "Renderer.h"

Engine::Engine(unsigned int width = 800, unsigned int height = 600) : mWindow(nullptr)
{
	mWindow = new sf::RenderWindow(sf::VideoMode({ width, height }), "fortnite");
}

Engine::~Engine()
{
	delete mWindow;
}

Engine& Engine::Get()
{
	static Engine sInstance;
	return sInstance;
}

void Engine::Run()
{
	while (mWindow->isOpen())
	{
		sf::Event event;
		while (mWindow->pollEvent(event))
			if (event.type == sf::Event::Closed) 
				mWindow->close();
			
		Update();
	}
}

void Engine::Update()
{
	Renderer::Get().Render(mWindow);
}

