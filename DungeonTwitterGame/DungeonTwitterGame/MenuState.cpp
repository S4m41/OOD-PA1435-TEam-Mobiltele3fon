#include "MenuState.hpp"
#include "Input.hpp"
#include <SFML\Window\Keyboard.hpp>
#include <iostream>

MenuState::MenuState(FiniteStateMachine * fsm) : GameState(fsm)
{}

MenuState::~MenuState()
{}

void MenuState::ProcessInput()
{
	if (m_input->IsKeyPressed(sf::Keyboard::Up))
	{
		m_selectedOption--;
		std::cout << "UP" << std::endl;
		ClampSelecton();
	}
	else if (m_input->IsKeyPressed(sf::Keyboard::Down)) {
		m_selectedOption++;
		std::cout << "Down" << std::endl;
		ClampSelecton();
	}
}
