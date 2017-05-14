#include "PauseMenuState.hpp"
#include "Input.hpp"
#include "FiniteStateMachine.hpp"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\CircleShape.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RenderStates.hpp>

PauseMenuState::PauseMenuState(FiniteStateMachine* fsm) : GameState(fsm)
{
}

PauseMenuState::~PauseMenuState()
{
}

//bool GamePauseMenuState::Initialize()
//{
//	return false;
//}

void PauseMenuState::Update()
{
	if (m_input->IsKeyPressed(sf::Keyboard::Key::Escape))
	{
		m_FSM->Pop();		// Exit pause state, return to play state
	}
	// .
	// .
	// .
	// Do stuff
	// .
	// .
}

void PauseMenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(100.0f);
	circle.setFillColor(sf::Color::Green);
	target.draw(circle, states);
}