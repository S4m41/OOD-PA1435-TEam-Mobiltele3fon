#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\CircleShape.hpp>
#include "GamePauseMenuState.hpp"

GamePauseMenuState::GamePauseMenuState(FiniteStateMachine* fsm) : GameState(fsm)
{
}

GamePauseMenuState::~GamePauseMenuState()
{
}

bool GamePauseMenuState::Initialize()
{
	return false;
}

void GamePauseMenuState::Update()
{
	ProcessInput();
	// .
	// .
	// .
	// Do stuff
	// .
	// .
}

void GamePauseMenuState::ProcessInput()
{
	if (m_input->IsKeyPressed(sf::Keyboard::Key::Escape))
	{
		m_FSM->Pop();		// Exit pause state, return to play state
	}
}

void GamePauseMenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape circle(100.0f);
	circle.setFillColor(sf::Color::Green);
	target.draw(circle, states);
}