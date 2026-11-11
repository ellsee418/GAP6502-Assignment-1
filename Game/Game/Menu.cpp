#include "Menu.h"
#include "common.h"
#include "Button.h"
#include "Renderer.h"


Menu::Menu()
	: m_play(nullptr), m_quit(nullptr)
{
}

Menu::~Menu()
{
	delete m_play;
	delete m_quit;
}

void Menu::Init()
{
	m_font.loadFromFile("../Assets/Pong.ttf");
	m_play = new Button(m_font, "Play", { 0.f,0.f });
	m_quit = new Button(m_font, "Quit", { 0.f,0.f });

	float gap = 10.f;
	m_play->SetPosition({ (WIN_WIDTH - m_play->GetBounds().width) / 2,
		(WIN_HEIGHT - m_play->GetBounds().height - gap) / 2 });
	m_quit->SetPosition({ (WIN_WIDTH - m_quit->GetBounds().width) / 2,
		(WIN_HEIGHT + m_quit->GetBounds().height + gap) / 2 });

	m_buttons.push_back(*m_play);
	m_buttons.push_back(*m_quit);
}

void Menu::Enter()
{
	Init();
}

void Menu::Exit()
{
}

StateResult Menu::Update()
{
	m_play->Hover();
	m_quit->Hover();

	Renderer::Get().Render(m_buttons, m_font);


	if (m_play->Clicked())
		return StateResult::EStateGame;
	if (m_quit->Clicked())
		return StateResult::EStateQuit;

	return StateResult::EStateMenu;
}
