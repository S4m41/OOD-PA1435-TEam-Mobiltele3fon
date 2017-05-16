#include "System.hpp"
#include "PlayState.hpp"

#include "MainMenuState.hpp"
#include "SystemSettings.hpp"

#include "Input.hpp"
#include "FiniteStateMachine.hpp"
#include <SFML\Window\Event.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\System\Clock.hpp>

System::System()
{
	m_window = nullptr;
	m_input = nullptr;
	m_FSM = nullptr;
}

System::~System()
{
	if (m_window)
	{
		m_window->close();
		delete m_window;
		m_window = nullptr;
	}
	if (m_input)
	{
		delete m_input;
		m_input = nullptr;
	}
	if (m_FSM)
	{
		delete m_FSM;
		m_FSM = nullptr;
	}
}

bool System::Initialize()
{
	m_window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Dungeon Twitter Game");
	if (!m_window)
		return false;

	m_input = new Input;
	if (!m_input)
		return false;

	m_FSM = new FiniteStateMachine;
	if (!m_FSM)
		return false;

	m_FSM->Push<MainMenuState>();
	m_FSM->Peek()->SetInput(m_input);

	return true;
}

void System::Run()
{
	sf::Clock clock;
	float frameRateDelay = 1.0f / FRAME_RATE;
	float timePassed = 0.0f;

	while (m_window->isOpen())
	{
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window->close();
				break;
			}
		}

		// Delay program
		timePassed += clock.restart().asSeconds();
		if (timePassed < frameRateDelay)
			continue;	
		timePassed = 0.0f;

		m_input->Update();
		m_FSM->Peek()->Update();

		if (m_FSM->Peek()) {
			m_window->clear();
			m_window->draw(*m_FSM->Peek());
			m_window->display();
		}
		else
		{
			m_window->close();
		}
	}
}