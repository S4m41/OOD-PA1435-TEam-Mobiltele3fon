#include "System.hpp"
#include <iostream>

System::System()
{
	m_window = nullptr;
	m_input = nullptr;
	m_currentState = nullptr;
}

System::~System()
{
}

bool System::Initialize()
{
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(512, 512), "Dungeon Twitter Game");
	if (!m_window)
		return false;
	
	m_input = std::make_unique<Input>();
	if (!m_input)
		return false;

	m_currentState = std::make_unique<GameState>();
	if (!m_currentState->Initialize())
		return false;

	return true;
}

void System::Run()
{
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
			
			// Set Keyboard states
			case sf::Event::KeyPressed:
				m_input->KeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				m_input->KeyUp(event.key.code);
				break;
			}
		}

		UpdateCurrentState();

		m_window->clear();
		m_window->display();
	}
}

void System::UpdateCurrentState()
{

	///////////////////////////////////////////////////
	// Preferrably move to each substate when possible
	if (m_input->IsKeyDown(sf::Keyboard::Escape))
	{
		m_window->close();
		return;
	}
	///////////////////////////////////////////////////



	// Only send indices and let m_game deal with it (only one pointers to m_input stored)
	for (int i = 0; i < 101; i++)
	{
		if (m_input->IsKeyDown(i))
			m_currentState->ProcessKeyDown(i);
		if (m_input->IsKeyPressed(i))
			m_currentState->ProcessKeyPressed(i);
	}

	// Update keys for next game loop cycle
	m_input->UpdatePreviousKeys();

	// Update whichever state is active
	m_currentState->Update();
}