#include "MenuState.hpp"
#include "Input.hpp"
#include <SFML\Window\Keyboard.hpp>
#include <iostream>

MenuState::MenuState(FiniteStateMachine * fsm) : GameState(fsm)
{}

MenuState::~MenuState()
{}

void MenuState::Update()
{
	//if (m_input->IsKeyPressed(sf::Keyboard::Up))
	//{
	//	m_selectedOption--;
	//	std::cout << "UP" << std::endl;
	//	ClampSelecton();
	//}
	//else if (m_input->IsKeyPressed(sf::Keyboard::Down)) {
	//	m_selectedOption++;
	//	std::cout << "Down" << std::endl;
	//	ClampSelecton();
	//}
}

void MenuState::Notify(Event* keyDownEvent)
{
	KeyDownEvent* kde = dynamic_cast<KeyDownEvent*>(keyDownEvent);

	if (kde && kde->m_onlyPressed)
	{
		switch (kde->m_key)
		{
		case sf::Keyboard::Up:
			m_selectedOption--;
			std::cout << "UP" << std::endl;
			ClampSelecton();
			break;
		case sf::Keyboard::Down:
			m_selectedOption++;
			std::cout << "Down" << std::endl;
			ClampSelecton();
			break;
		default:
			break;
		}
	}
}