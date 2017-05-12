#include "System.hpp"
#include <SFML\Window\Event.hpp>

System::System()
{
	m_window = nullptr;
	m_input = nullptr;
}

System::~System()
{
	if (m_window)
	{
		m_window->close();
		delete m_window;
		m_window = nullptr;
	}
}

bool System::Initialize()
{
	m_window = new sf::RenderWindow(sf::VideoMode(512, 512), "Dungeon Twitter Game");
	if (!m_window)
		return false;
	
	m_input = std::make_shared<Input>();
	if (!m_input)
		return false;

	m_FSM.Push<GamePlayState>();
	m_FSM.Peek()->SetInput(m_input);

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
			}
		}

		m_input->Update();

		m_FSM.Peek()->Update();

		m_window->clear();
		m_window->draw(*m_FSM.Peek());
		m_window->display();
	}
}